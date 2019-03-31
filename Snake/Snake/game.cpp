/*
Game:̰����
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

/* �����ͼ�ĳ����ߵ����꣬���ȣ�����ʳ���λ�ã���� */
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

/* �������� */
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

/* ��궨λ */
void locate(int x, int y)
{
	coord.X = y; // ������õ�ʱ����Ϊy����Ϊx�����ǵ���λ��ʱ����Ϊx����Ϊy���򽻻�x��y��λ��
	coord.Y = x;
	SetConsoleCursorPosition(hout, coord);
};

/* ������ɫ */
int color(int c)
{
	SetConsoleTextAttribute(hout, c);
	return 0;
}

/* ���ع�� */
void hide()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 }; // ���ĺ�Ⱥ͹���Ƿ�ɼ�
	SetConsoleCursorInfo(hout, &cursor_info);
}

/* ��ʾ��� */
void show()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,1 }; // ���ĺ�Ⱥ͹���Ƿ�ɼ�
	SetConsoleCursorInfo(hout, &cursor_info);
}


/* ��ӭ���� */
bool welecome()
{
	locate(5, 27);
	color(11);
	cout << "-------------------- ̰���� ---------------------" << endl;
	color(13);
	locate(10, 27);
	cout << "��Ϸ˵��: ʹ�� �� ���� �� �������߽����ƶ�,��ÿ��" << endl;
	locate(11, 27);
	cout << " �ƶ���������ǽ�ڻ����������򽫻ᵼ����Ϸ������" << endl;
	locate(12, 27);
	cout << "  ��Ϸ����ҪĿ���ǳԵ�ʳ��Ӷ����������ߵĳ��ȡ� " << endl;
	locate(13, 27);
	cout << "                  ף����Ϸ��죡                 " << endl;

	locate(20, 25);
	color(12);
	cout << "1.��ʼ��Ϸ" << endl;

	locate(20, 65);
	cout << "2.�˳���Ϸ" << endl;

	locate(23, 45);
	color(3);
	cout << "ѡ��" << endl;
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
	cout << "Ŀǰ���߳�: ";
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

/* ��������� */
double random(double start, double end)
{
	return start + (end - start)*rand() / (RAND_MAX + 1.0);
}


/* ���ǽ */
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

/*** �״�����ߣ�����snake[0]����ͷ ***/
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

/*** �ж��Ƿ�ײǽ������ײ ***/
bool is_correct()
{
	if (snake[0].x == 0 || snake[0].y == 0 || snake[0].x == m + 1 || snake[0].y == n + 1) return false; // ײǽ
	for (int i = 1; i <= snake_length - 1; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) return false; // ��ͷ��������ĳ��λ�ã���ײ
	}
	return true;
}

/*** ������ɲ����ʳ��λ�� ***/
bool print_food()
{
	srand((unsigned)time(NULL)); // �����������
	bool can_generate;
	while (true)
	{
		can_generate = true;
		int i = (int)random(0, m) + 1, j = (int)random(0, n) + 1;
		food.x = i; food.y = j;
		for (int k = 0; k <= snake_length - 1; k++)  // ���������ߵ�������ô����������
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

/*** �ߵ�ǰ�� ***/
/*
1.�ȴ���ͷ�����Ƶ���β
2.�ж���ͷ�ƶ�����λ��
3.��֮ǰ����ͷ���³�����
4.�ж��Ƿ�Ե�ʳ��:�Ե��򳤶����ӣ���βΪ֮ǰ����β��λ�ã����ҵø��¹�ʵ��λ�ã�û�Ե���֮ǰ����β�����
5.��ӡ����ͷ��λ��
6.�ж��Ƿ�ײǽ������ײ
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

	/*** �Ե���ʳ�� ***/
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

	
	/*** ���ײǽ������ײ ***/
	if (!is_correct())
	{
		gameover();
		return false;
	}
	return true;
}

/*** ������ ***/
int main()
{
	/*** ��ӭҳ ***/
	bool wel = welecome();
	if (!wel)
		return 0;

	/*** ����ȫ����ʼ�����������ڴ�С���߳���λ�ã����� ||| �����ʼ��ͼ������ʳ��***/
	initialization();

	/*** ��ʼ��Ϸ ***/
	while (true)
	{
		/*** �Ѷ��泤�����Ӷ���� ***/
		double hard_len = (double)snake_length / (double)(m*n);
		/*** ����ʱ�䣬��λ��ms ***/
		clock_t a = clock();
		while (1)
		{
			clock_t b = clock();
			if (b - a >= (int)300*(1 - sqrt(hard_len))) // ��ʼ���ٶ�Ϊ0.3ms�����ų��ȵ������ٶ��ٲ��ϵ�����
				break;
		}
		/*** ���ܼ���������������ң����Դ˸ı䷽�� ***/
		if (_kbhit()) // �����Ƿ�����
		{
			int ch = _getch();
			if (ch == 224) // 224��ʾ�����˷����
			{
				ch = _getch(); // ��ʾ������ʲô��
				switch (ch)
				{
				case 72: // ��
					if (dir == 2 || dir == 3) // ֮ǰ���Ҳ���Ч
						dir = 0;
					break;
				case 80: // ��
					if (dir == 2 || dir == 3)
						dir = 1;
					break;
				case 75: // �� 
					if (dir == 0 || dir == 1)
						dir = 2;
					break;
				case 77: //  ��
					if (dir == 0 || dir == 1)
						dir = 3;
					break;
				}
			}
		}
		/*** ǰ�� ***/
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
		/*** ����������ʱ���� ***/
		locate(m + 2, 12); 
		cout << snake_length;
	}

	return 0;
}
