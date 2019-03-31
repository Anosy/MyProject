# 基于控制台的贪吃蛇小游戏
## 语言C++

### 主体
1.**全部函数简介**
locate()————光标定位<br>
color()————颜色<br>
hide()————隐藏光标<br>
show()————显示光标<br>
welecome()————欢迎界面<br>
initialization()————游戏参数初始化<br>
gameover()————游戏结束界面<br>
random(int start, int end)————得到start到end的随机数<br>
print_wall()————打印墙壁<br>
print_snake()—————初始打印蛇<br>
is_correct()————是否碰撞或者自撞<br>
print_food()————打印食物<br>
go_head()————蛇体前进<br>

<br>
**2.核心函数介绍**
welecome()<br>
利用定位函数固定光标的位置，然后不断通过调整合适的位置进行排版，以及改变颜色来提高美观。<br>

<br>
print_snake()<br>
我们定义了一种数据类型，其保存了横纵坐标。初始化的过程中，将蛇身体给保存在一个1D数组中，其中数组的首元素表示的就是蛇头的坐标，数组的最后一个元素保存的就是蛇的尾的坐标。<br>

<br>
is_correct()<br>
在什么情况下才会出现碰撞呢？当然是蛇头碰撞到身体或者墙的时候。所以函数就是判断snake[0].start和snake[0].end和墙与数组中的元素是否存在相同的情况<br>

<br>
print_food()<br>
首先按照时间生成随机种子，然后通过random函数生成x=[1,m]，y=[1,n]之间的随机位置。重点是要判断生成的种子的位置是否已经出现在数组中，也种子是不能出现在蛇的身上的。如果随机到
身上，那么就需要重新的随机产生直到不重复为止。<br>

<br>
go_ahead()<br>
首先先保存蛇尾的坐标，然后从蛇头开始将坐标后移给数组下一个下标的坐标。<br>
然后蛇头的坐标通过方向键的控制查询2D direct数组，对坐标进行改变。<br>
然后这时候因为将蛇头的坐标给传递给了下一个下标的位置，所以我们定位将旧蛇头给打印成身体。<br>
这时候再判断是否吃到了食物，如果吃到了，那么就更新蛇的长度，并且给蛇添加新的尾巴，而新的尾巴的坐标值为之前的尾巴的坐标值，并且打印新食物 <br>
如果没吃到，那么就将之前尾巴的位置给打印成空。<br>
并且如果没吃到还要判断是否自撞或者撞墙了，如果出现，那么就游戏结束，判断是否replay <br>
**注意：这里改变了数组中坐标的内容的同时，还得在显示上输出进行改变！！**<br>

<br>
**3.主函数**
欢迎页<br>
初始化参数<br>
循环进行游戏<br>
通过延时来控制游戏难度，而延时通过蛇的长度来控制，长度越长延时越短。初始延时为0.3s<br>
判断方向键，从而控制蛇身移动<br>
如果失败调用是否replay<br>
更新当前的长度<br>

<br>
**4.效果图**<br>
![](https://github.com/Anosy/MyProject/blob/master/Snake/picture/game.png)<br>
![](https://github.com/Anosy/MyProject/blob/master/Snake/picture/gameover.png)<br>
![](https://github.com/Anosy/MyProject/blob/master/Snake/picture/welcome.png)<br>




