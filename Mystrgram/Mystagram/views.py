from Mystagram import app, db
from flask import render_template, redirect, request, flash, get_flashed_messages, send_from_directory
from Mystagram.models import User, Image, Comment
import random
import hashlib
import json
import uuid
import os
from flask_login import login_user, logout_user, current_user, login_required
from Mystagram.qiniusdk import qiniu_upload_file


def redirect_with_msg(target, msg, category):
    if msg != None:
        flash(msg, category=category)  # 将消息给闪烁到下一个请求
    return redirect(target)  # 跳转到指定的页面


@app.route('/')
def index():

    images = Image.query.order_by('id desc').limit(10).all()
    return render_template('index.html', images=images)


@app.route('/image/<int:image_id>/')
def image(image_id):
    image = Image.query.get(image_id)
    if image == None:
        return redirect('/')
    return render_template('pageDetail.html', image=image)


@app.route('/profile/<int:user_id>/')
@login_required  # 表示用户只有登录授权之后才能够进入
def profile(user_id):
    user = User.query.get(user_id)
    if user == None:
        return redirect('/')
    paginate = Image.query.filter_by(user_id=user_id).paginate(page=1, per_page=3, error_out=False)  # 将图片给分页，每页3张
    return render_template('profile.html', user=user, images=paginate.items, has_next=paginate.has_next)


@app.route('/profile/images/<int:user_id>/<int:page>/<int:per_page>/')
def user_images(user_id, page, per_page):
    # 参数检查
    paginate = Image.query.filter_by(user_id=user_id).paginate(page=page, per_page=per_page)

    map = {'has_next': paginate.has_next}
    images = []
    for image in paginate.items:
        imgvo = {'id': image.id, 'url': image.url, 'comment_count': len(image.comments)}
        images.append(imgvo)
    map['images'] = images
    return json.dumps(map)


@app.route('/regloginpage/')
def reloginpage():
    msg = ''
    for m in get_flashed_messages(with_categories=False, category_filter=['reglogin']):  # 获取刚刚flash的消息
        msg += m
    return render_template('login.html', msg=msg, next=request.values.get('next'))  # 将消息传递到login.html模板页面


@app.route('/login/', methods={'get', 'post'})
def login():
    username = request.values.get('username').strip()
    password = request.values.get('password').strip()
    # 校验
    if username == '' or password == '':
        return redirect_with_msg('/regloginpage', u'用户名和密码不能为空', 'reglogin')

    user = User.query.filter_by(username=username).first()
    if user == None:
        return redirect_with_msg('/regloginpage', u'用户名不存在', 'reglogin')

    m = hashlib.md5()
    m.update((password + user.salt).encode("utf8"))
    if m.hexdigest() != user.password:
        return redirect_with_msg('/regloginpage', u'密码错误', 'reglogin')

    login_user(user)

    next = request.values.get('next')  # 如果存在next返回值，那么登录成功后将会跳转到之前next所指向的页面
    if next != None and next.startswith('/'):
        return redirect(next)

    return redirect('/')


@app.route('/reg/', methods={'post', 'get'})
def reg():
    # request.args
    # request.form 表单——用于用户的输入
    # request.values

    # 获取用户注册提交的账号和密码
    username = request.values.get('username').strip()
    password = request.values.get('password').strip()

    # 校验
    user = User.query.filter_by(username=username).first()
    if username == '' or password == '':
        return redirect_with_msg('/regloginpage', u'用户名和密码不能为空', 'reglogin')
    if user != None:
        return redirect_with_msg('/regloginpage', u'用户名已存在', 'reglogin')

    salt = ''.join(random.sample('0123456789abcdefghigklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ', 10))
    m = hashlib.md5()
    m.update((password + salt).encode("utf8"))  # update()必须指定要加密的字符串的字符编码
    password = m.hexdigest()
    user = User(username, password, salt)
    db.session.add(user)
    db.session.commit()

    login_user(user)

    next = request.values.get('next')  # 如果存在next返回值，那么登录成功后将会跳转到之前next所指向的页面
    if next != None and next.startswith('/'):
        return redirect(next)

    return redirect('/')


@app.route('/logout/')
def logout():
    logout_user()
    return redirect('/')


def save_to_local(file, file_name):
    save_dir = app.config['UPLOAD_DIR']
    file.save(os.path.join(save_dir, file_name))
    return '/image/' + file_name


@app.route('/image/<image_name>')
# 展示，访问图片。如果是本地上传，那么上传的src就是当前的位置的地址。如果使用云存储，则上传的src为云上存储的地址，所以不需要该函数
# 实际就是开辟一个url来给图片有个显示的入口
def view_image(image_name):
    return send_from_directory(app.config['UPLOAD_DIR'], image_name)


@app.route('/upload/', methods={'post'})
def upload():
    # print(type(request.files))  # 得到请求发送的数据的一个dict
    file = request.files['file']
    # print(dir(file))
    file_ext = ''
    if file.filename.find('.') > 0:  # 如果有后缀名
        file_ext = file.filename.rsplit('.', 1)[1].strip().lower()
    if file_ext in app.config['ALLOWED_EXT']:
        file_name = str(uuid.uuid1()).replace('-', '') + '.' + file_ext

        #url = save_to_local(file, file_name) # 保存到本地

        url = qiniu_upload_file(file, file_name)  # 保存在七牛云
        if url != None:
            db.session.add(Image(url, current_user.id))
            db.session.commit()
    return redirect('/profile/%d' % current_user.id)


@app.route('/addcomment/', methods={'post'})
def add_comment():
    image_id = int(request.values['image_id'])
    content = request.values['content']
    comment = Comment(content, image_id, current_user.id)
    db.session.add(comment)
    db.session.commit()

    return json.dumps({"code": 0, "id": comment.id,
                       "content": comment.content,
                       "username": comment.user.username,
                       "user_id": comment.user_id})
    # return redirect('/image/%d' % image_id)
