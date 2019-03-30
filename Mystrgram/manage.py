from Mystagram import app, db
from flask_script import Manager
from Mystagram.models import User, Image, Comment
import random

manager = Manager(app)


def get_image_url():
    return "http://images.nowcoder.com/head/" + str(random.randint(0, 1000)) + 'm.png'


@manager.command
def init_database():
    """init_database"""
    db.drop_all()
    db.create_all()
    for i in range(0, 100):
        db.session.add(User('牛客' + str(i), 'a' + str(i)))

        for j in range(0, 10):  # 每人发十张图
            db.session.add(Image(get_image_url(), i + 1))
            for k in range(0, 3):
                db.session.add(Comment('这是一条评论' + str(k), 1 + 10 * i + j, i + 1))
        db.session.commit()

    # # update 操作
    # for i in range(50, 100, 2):
    #     user = User.query.get(i)
    #     user.username = '[New] ' + user.username
    #
    # for i in range(51, 100, 2):
    #     User.query.filter_by(id=i).update({'username': '牛客新' + str(i)})
    # db.session.commit()
    #
    # # delete 操作
    # for i in range(50, 100, 2):
    #     comment = Comment.query.get(i+1)
    #     db.session.delete(comment)
    # db.session.commit()


    # 基本的数据库查询操作
    # print(1, User.query.all())  # 查询全部
    # print(2, User.query.get(3))  # 获取第三个
    # print(3, User.query.filter_by(id=2).all())  # 筛选id=2的数据
    # print(4, User.query.order_by(User.id.desc()).limit(2).all())  # 降序找到倒数两个数据
    # print(5, User.query.filter(User.username.endswith('0')).all()) # 筛选出username结尾为0的数据
    # print(6, User.query.paginate(page=1, per_page=10).items) # 将数据分页，每页10个数据，找到第1页
    # u = User.query.get(1)
    # print(u)
    # print(u.images.first())
    # print(Image.query.get(1).user)
    # img = Image.query.get(1)
    # print(img.user)


if __name__ == '__main__':
    manager.run()
