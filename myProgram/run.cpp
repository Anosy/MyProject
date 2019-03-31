#include"Interface.h"


void Interface::run()
{
	int choose = 1;
	while (choose) 
	{
		while (1) 
		{
			menu();
			cin >> choose;
			if (choose == 1 || choose == 2 || choose == 0) {
				break;
			}
			else
				cout << "�����������������룡" << endl;
		}
		system("cls");
		if (choose == 1)
			Administrator();
		else if (choose == 2)
			Teacher();
		else
			break;
		system("cls");
	}
	save();
	cout << "���Ѿ��˳�ʦ������ϵͳ����ӭ�ٴ�ʹ�ã�" << endl;
}


void Interface::Administrator()
{
	cout << "         ���Ѿ��ɹ��������Աϵͳ��        " << endl;
	int choose, choose1 = 1;

	while (choose1) {
		while (1)
		{
			menu1();
			cin >> choose;
			if (!choose) {
				cout << "���Ѿ��˳�����Աϵͳ" << endl;
				system("pause");
				system("cls");
				return;
			}
			else if (choose != 1 && choose != 2)
				cout << "������������������" << endl;
			else break;
		}
		system("cls");
		if (choose == 1) {
			while (choose1) {
				cout << endl;
				cout << "        רҵ����˵�     " << endl;
				cout << "=========================" << endl;
				cout << "       ��1�����רҵ     " << endl;
				cout << "       ��2��ɾ��רҵ     " << endl;
				cout << "       ��3����ѯרҵ     " << endl;
				cout << "       ��4���޸�רҵ     " << endl;
				cout << "       ��0�� �� ��       " << endl;
				cout << "=========================" << endl;
				cout << "      ����������ѡ��";
				cin >> choose1;
				switch (choose1) {
				case 1:creatMajor(); break;
				case 2:Delete_Major(); break;
				case 3:Display(1, count4, maj.begin(), maj.end()); break;
				case 4:motify1(); break;
				case 0:break;
				}
				system("cls");
			}
		}
		else {
			while (choose1) {
				cout << "        �༶����˵�     " << endl;
				cout << "=========================" << endl;
				cout << "       ��1����Ӱ༶     " << endl;
				cout << "       ��2��ɾ���༶     " << endl;
				cout << "       ��3����ѯ�༶     " << endl;
				cout << "       ��4���޸İ༶     " << endl;
				cout << "       ��0�� �� ��       " << endl;
				cout << "=========================" << endl;
				cout << "      ����������ѡ��";
				cin >> choose1;
				switch (choose1) {
				case 1:creatClass(); break;
				case 2:Delete_Class(); break;
				case 3:Display(2, count3, Cla.begin(), Cla.end()); break;
				case 4:motify2(); break;
				case 0:break;
				}
				system("cls");
			}
		}
		cout << "���Ѿ��˳�����Աϵͳ��" << endl;
		system("pause");
		system("cls");
	}
}

void Interface::Teacher()
{
	cout << "         ���Ѿ������ʦϵͳ        " << endl;
	int choose, choose1 = 1;
	menu2();
	cin >> choose;
	system("cls");

	//ѧ����Ϣ����ģ��
	while (choose == 1 && choose1) 
	{
		menu3();
		cin >> choose1;
		switch (choose1) {
		case 1:Input(); break;
		case 2:motify3(); break;
		case 3:motify4(); break;
		case 4:DisplayByID(); break;
		case 5:Delete_student(); break;
		case 6:InputScore(); break;
		case 0:break;
		}
		system("cls");
	}
	while (choose == 2 && choose1)
	{
		menu4();
		cin >> choose1;
		switch (choose1)
		{
		case 1:Display(3, count1, stu1.begin(), stu1.end()); break;
		case 2:Display(4, count2, stu2.begin(), stu2.end()); break;
		case 3:DisplayByClass(); break;
		case 4:DisplayByMajor(); break;
		case 5:DisplayByName(); break;
		case 6:DisplayByID(); break;
		case 7:DisplayFailStudent(); break;
		}

	}
	while (choose == 3 && choose1)
	{
		menu5();
		cin >> choose1;
		switch (choose1)
		{
		case 1:sortUndergraduate();
			break;
		case 2:sortGraduate();
			break;
		case 3:sortByClass_undergraduate();
			break;
		case 4:sortByClass_graduate();
			break;
		}
	}
	while (choose == 4 && choose1)
	{
		menu6();
		cin >> choose1;
		switch (choose1)
		{
		case 1:statistic1(); break;
		case 2:statistic2(); break;
		case 3:statistic3(); break;
		case 4:statistic4(); break;
		}
	}
	return;
}

