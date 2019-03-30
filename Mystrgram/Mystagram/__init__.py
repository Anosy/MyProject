from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_login import LoginManager

app = Flask(__name__)
app.config.from_pyfile('app.conf')
app.jinja_env.add_extension('jinja2.ext.loopcontrols')
db = SQLAlchemy(app)
app.secret_key = '123456'  # flash消息闪烁的时候需要添加上密钥

login_manager = LoginManager(app)
login_manager.login_view = '/regloginpage/'  # 给未登录用户跳转

from Mystagram import views, models
