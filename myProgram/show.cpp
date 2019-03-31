#include"Interface.h"


void Interface::DisplayByClass()
{
	string id1;
	string id2;
	int count = 0;
	int choose;
	cout << "������������Ҫ��ѯ��רҵ��ţ�";
	cin >> id1;
	cout << "������������Ҫ��ѯ�İ༶��ţ�";
	cin >> id2;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> choose;
	if (choose == 1) {
		vector<undergraduate>::iterator p = stu1.begin();
		vector<undergraduate> student;
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == id1 && p->getClassNumber() == id2)
			{
				student.push_back(*p++);
				count++;
			}
			else
				p++;
		}
		Display(3, count, student.begin(), student.end());
		return;
	}
	else if (choose == 2) {
		vector<graduate>::iterator p = stu2.begin();
		vector<graduate> student;
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == id2 && p->getClassNumber() == id1)
			{
				student.push_back(*p++);
				count++;
			}
			else
				p++;
		}
		Display(4, count, student.begin(), student.end());
		return;
	}
	else
	{
		cout << "�����������ڷ��ز˵�..." << endl;
		system("pause");
		return;
	}
}

void Interface::DisplayByMajor()
{
	string id;
	cout << "��������Ҫ��ѯ��רҵ��ţ�";
	cin >> id;
	int choose;
	int count = 0;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> choose;
	if (choose == 1)
	{
		vector<undergraduate>::iterator p = stu1.begin();
		vector<undergraduate> student;
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == id)
			{
				student.push_back(*p++);
				count++;
			}
			else
				p++;
		}
		Display(3, count, student.begin(), student.end());
		return;
	}
	else if (choose == 2) {
		vector<graduate>::iterator p = stu2.begin();
		vector<graduate> student;
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == id)
			{
				student.push_back(*p++);
				count++;
			}
			else
				p++;
		}
		Display(4, count, student.begin(), student.end());
		return;
	}
	else
	{
		cout << "�����������ڷ��ز˵�..." << endl;
		system("pause");
		system("cls");
		return;
	}
}

void Interface::DisplayByName()
{
	string name;
	cout << "���������������";
	cin >> name;
	int type;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> type;
	if (type == 1)
	{
		vector<undergraduate>::iterator p = stu1.begin();
		while (p != stu1.end())
		{
			if (p->getName() == name)
			{
				cout << "���ҵ�������Ϣ��" << endl;
				p->print();
				system("pause");
				system("cls");
				return;
			}
			else
				p++;
		}
		cout << "û�����ѧ������Ϣ����˶���Ϣ��" << endl;
		system("pause");
		return;
	}
	else if (type == 2)
	{
		vector<graduate>::iterator p = stu2.begin();
		while (p != stu2.end())
		{
			if (p->getName() == name)
			{
				cout << "���ҵ�������Ϣ��" << endl;
				p->print();
				system("pause");
				system("cls");
				return;
			}
			else
				p++;
		}
		cout << "û�����ѧ������Ϣ����˶���Ϣ��" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "�����������ڷ��ز˵�..." << endl;
		system("pause");
		return;
	}
}

void Interface::DisplayByID()
{
	int id;
	int type;
	cout << "������ѧ��ѧ�ţ�";
	cin >> id;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> type;
	if (type == 1)
	{
		vector<undergraduate>::iterator p = stu1.begin();
		while (p != stu1.end())
		{
			if (p->getID() == id)
			{
				cout << "���ҵ�������Ϣ��" << endl;
				p->print();
				system("pause");
				system("cls");
				return;
			}
			else
				p++;
		}
		cout << "û�����ѧ������Ϣ����˶���Ϣ��" << endl;
		system("pause");
		return;
	}
	else if (type == 2)
	{
		vector<graduate>::iterator p = stu2.begin();
		while (p != stu2.end())
		{
			if (p->getID() == id)
			{
				cout << "���ҵ�������Ϣ��" << endl;
				p->print();
				system("pause");
				system("cls");
				return;
			}
			else
				p++;
		}
		cout << "û�����ѧ������Ϣ����˶���Ϣ��" << endl;
		system("pause");
		return;
	}
	else
	{
		cout << "�����������ڷ��ز˵�..." << endl;
		system("pause");
		return;
	}
}

void Interface::DisplayFailStudent()
{
	string id1;   //�꼶���
	string id2;   //�༶���
	cout << "�������꼶��ţ�";
	cin >> id1;
	cout << "������༶��ţ�";
	cin >> id2;
	int type;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> type;
	int choose;
	int count = 0;
	if (type == 1)
	{
		cout << "��������Ҫͳ����Ϣ�Ŀ�Ŀ��C���ԣ�1��������2��Ӣ�3����";
		cin >> choose;
		vector<undergraduate>::iterator p = stu1.begin();
		vector<undergraduate> student;
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == id1 && p->getClassNumber() == id2 && p->getScore(choose - 1) < 60)
			{
				student.push_back(*p++);
				count++;
			}
			else
				p++;
		}
		if (!count)
		{
			cout << "�ð༶�ڸÿ�Ŀ�в���������Ϊ0��" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
			Display(3, count, student.begin(), student.end());
	}
	else if (type == 2)
	{
		cout << "��������Ҫͳ����Ϣ�Ŀ�Ŀ���γ���ƣ�1�����ĳɼ���2����";
		cin >> choose;
		vector<graduate>::iterator p = stu2.begin();
		vector<graduate> student;
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == id1 && p->getClassNumber() == id2 && p->getScore(choose - 1) < 60)
			{
				student.push_back(*p++);
				count++;
			}
			else
				p++;
		}
		if (!count)
		{
			cout << "�ð༶�ڸÿ�Ŀ�в���������Ϊ0��" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
			Display(4, count, student.begin(), student.end());
	}
	else
	{
		cout << "�����ѧ������������˶�..." << endl;
		system("pause");
		return;
	}
}