/*
Game:贪吃蛇
Author:WCJ
Language:C++
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cmath>
#include <windows.h>
using namespace std;

/* 定义地图的长宽，蛇的坐标，长度，方向，食物的位置，句柄 */
int m, n;

struct node
{
public:
	int x, y;
};

node snake[1000];
int snake_length, dir;
node food;
int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD coord;

/* 函数声明 */
void locate(int x, int y);
int color(int c);
void hide();
void show();
bool welecome();
void initialization();
void gameover();
double random(double start, double end);
void print_wall();
void print_snake();
bool is_correct();
bool print_food();
bool go_ahead();

/* 光标定位 */
void locate(int x, int y)
{
	coord.X = y; // 光标设置的时候行为y，纵为x。考虑到定位的时候行为x，纵为y，则交换x和y的位置
	coord.Y = x;
	SetConsoleCursorPosition(hout, coord);
};

/* 设置颜色 */
int color(int c)
{
	SetConsoleTextAttribute(hout, c);
	return 0;
}

/* 隐藏光标 */
void hide()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 }; // 光标的厚度和光标是否可见
	SetConsoleCursorInfo(hout, &cursor_info);
}

/* 显示光标 */
void show()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,1 }; // 光标的厚度和光标是否可见
	SetConsoleCursorInfo(hout, &cursor_info);
}


/* 欢迎界面 */
bool welecome()
{
	locate(5, 27);
	color(11);
	cout << "-------------------- 贪吃蛇 ---------------------" << endl;
	color(13);
	locate(10, 27);
	cout << "游戏说明: 使用 ↑ ↓← → 来操纵蛇进行移动,蛇每次" << endl;
	locate(11, 27);
	cout << " 移动不能碰到墙壁或者自身，否则将会导致游戏结束。" << endl;
	locate(12, 27);
	cout << "  游戏的主要目标是吃到食物从而不断增加蛇的长度。 " << endl;
	locate(13, 27);
	cout << "                  祝你游戏愉快！                 " << endl;

	locate(20, 25);
	color(12);
	cout << "1.开始游戏" << endl;

	locate(20, 65);
	cout << "2.退出游戏" << endl;

	locate(23, 45);
	color(3);
	cout << "选择：" << endl;
	show();
	int choose;
	locate(23, 51);
	
	color(FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE);

	cin >> choose;
	if (choose == 2)
		return false;
	else
		return true;
}

void initialization()
{
	m = 25, n = 40;
	snake_length = 5;
	for (int i = 0; i <= 4; i++)
	{
		snake[i].x = 1;
		snake[i].y = 5 - i;
	}
	dir = 3;

	system("cls");
	hide();
	print_wall();
	print_food();
	print_snake();
	locate(m + 2, 0);
	cout << "目前的蛇长: ";
}

void gameover()
{
	system("cls");
	locate(5, 27);
	color(FOREGROUND_RED);
	cout << "Game Over !!!" << endl;

	locate(8, 27);
	color(FOREGROUND_GREEN);
	cout << "You score: " << snake_length << endl;

	color(FOREGROUND_RED |
		FOREGROUND_GREEN |
		FOREGROUND_BLUE);

	locate(11, 27);
	cout << "Do you want to replay (y/n)?" << endl;
	locate(11, 57);
	show();
}

/* 生成随机数 */
double random(double start, double end)
{
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}


/* 输出墙 */
void print_wall()
{
	cout << " ";
	for (int i = 1; i <= n; i++)
		cout << "-";
	cout << " ";
	cout << endl;
	for (int j = 1; j <= m; j++)
	{
		cout << "|";
		for (int i = 1; i <= n; i++) 
			cout << " ";
		cout << "|" << endl;
	}
	cout << " ";
	for (int i = 1; i <= n; i++)
		cout << "-";
	cout << " ";
}

/*** 首次输出蛇，其中snake[0]代表头 ***/
void print_snake()
{
	locate(snake[0].x, snake[0].y);
	cout << "@";
	for (int i = 1; i <= snake_length - 1; i++)
	{
		locate(snake[i].x, snake[i].y);
		cout << "*";
	}
}

/*** 判断是否撞墙或者自撞 ***/
bool is_correct()
{
	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == m + 1 || snake[0].y == n + 1) return false; // 撞墙
	for (int i = 1; i <= snake_length - 1; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) return false; // 蛇头等于蛇身某个位置，自撞
	}
	return true;
}

/*** 随机生成并输出食物位置 ***/
bool print_food()
{
	srand((unsigned)time(NULL)); // 产生随机种子
	bool can_generate;
	while (true)
	{
		can_generate = true;
		int i = (int)random(0, m) + 1, j = (int)random(0, n) + 1;
		food.x = i; food.y = j;
		for (int k = 0; k <= snake_length - 1; k++)  // 如果随机在蛇的身上那么就重新生成
		{
			if (snake[k].x == food.x && snake[k].y == food.y)
			{
				can_generate = false;
				break;
			}
		}
		if (can_generate) break;
	}
	locate(food.x, food.y);
	cout << "$";

	return true;
}

/*** 蛇的前进 ***/
/*
1.先从蛇头逐项移到蛇尾
2.判断蛇头移动到的位置
3.将之前的蛇头更新成身体
4.判断是否吃到食物:吃到则长度增加，蛇尾为之前的蛇尾的位置，并且得更新果实的位置；没吃到则之前的蛇尾给清空
5.打印新蛇头的位置
6.判断是否撞墙或者自撞
*/
bool go_ahead()
{
	node temp;
	bool eat = false;
	temp = snake[snake_length - 1];
	for (int i = snake_length - 1; i >= 1; i--)
		snake[i] = snake[i - 1];
	snake[0].x += direct[dir][0];
	snake[0].y += direct[dir][1];
	locate(snake[1].x, snake[1].y);
	cout << "*";
	locate(snake[0].x, snake[0].y);
	cout << "@";

	/*** 吃到了食物 ***/
	if (snake[0].x == food.x && snake[0].y == food.y)
	{
		snake_length++;
		eat = true;
		snake[snake_length - 1] = temp;
		print_food();
	}
	else
	{
		locate(temp.x, temp.y);
		cout << " ";
	}

	
	/*** 如果撞墙或者自撞 ***/
	if (!is_correct())
	{
		gameover();
		return false;
	}
	return true;
}

/*** 主函数 ***/
int main()
{
	/*** 欢迎页 ***/
	bool wel = welecome();
	if (!wel)
		return 0;

	/*** 数据全部初始化，包括窗口大小，蛇长，位置，方向 ||| 输出初始地图，蛇与食物***/
	initialization();

	/*** 开始游戏 ***/
	while (true)
	{
		/*** 难度随长度增加而提高 ***/
		double hard_len = (double)snake_length / (double)(m*n);
		/*** 调节时间，单位是ms ***/
		clock_t a = clock();
		while (1)
		{
			clock_t b = clock();
			if (b - a >= (int)300*(1 - sqrt(hard_len))) // 起始的速度为0.3ms，随着长度的增加速度再不断的上升
				break;
		}
		/*** 接受键盘输入的上下左右，并以此改变方向 ***/
		if (_kbhit()) // 键盘是否输入
		{
			int ch = _getch();
			if (ch == 224) // 224表示键入了方向键
			{
				ch = _getch(); // 表示键入了什么键
				switch (ch)
				{
				case 72: // ↑
					if (dir == 2 || dir == 3) // 之前左右才有效
						dir = 0;
					break;
				case 80: // ↓
					if (dir == 2 || dir == 3)
						dir = 1;
					break;
				case 75: // ← 
					if (dir == 0 || dir == 1)
						dir = 2;
					break;
				case 77: //  →
					if (dir == 0 || dir == 1)
						dir = 3;
					break;
				}
			}
		}
		/*** 前进 ***/
		if (!go_ahead())
		{
			char replay;
			cin >> replay;
			if (replay == 'y')
			{
				initialization();
				continue;
			}
			else
				break;
		}
		/*** 在最后输出此时长度 ***/
		locate(m + 2, 12); 
		cout << snake_length;
	}

	return 0;
}
