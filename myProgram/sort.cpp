#include"Interface.h"

bool Interface::comparing1(undergraduate s1, undergraduate s2)
{
	return s1.getScore(3) > s2.getScore(3);   //����
}

bool Interface::comparing2(graduate s1, graduate s2)
{
	return s1.getScore(2) > s2.getScore(2);   //����
}

bool Interface::comparing3(undergraduate s1, undergraduate s2)
{
	return s1.getID() < s2.getID();           //����
}

bool Interface::comparing4(graduate s1, graduate s2)
{
	return s1.getID() < s2.getID();          //����
}

void Interface::sortUndergraduate()
{
	sort(stu1.begin(), stu1.end(), comparing1);
	vector<undergraduate>::iterator p1 = stu1.begin();
	int count = 1;
	while (p1 != stu1.end())
	{
		p1->getRanking1() = count++;
		p1++;
	}
	vector<undergraduate>::iterator p = stu1.begin();
	if (count != 1 && count != 0)
		p++;
	else
	{
		cout << "������ɣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (p != stu1.end())
	{
		if (p->getScore(3) == (p - 1)->getScore(3))
			p->getRanking1() = (p - 1)->getRanking1();
		p++;
	}
	Display(3, count1, stu1.begin(), stu1.end());
	sort(stu1.begin(), stu1.end(), comparing3);
	cout << "������ɣ�" << endl;
	system("pause");
	system("cls");
}

void Interface::sortGraduate()
{
	sort(stu2.begin(), stu2.end(), comparing2);
	vector<graduate>::iterator p1 = stu2.begin();
	int count = 1;
	while (p1 != stu2.end())
	{
		p1->getRanking1() = count++;
		p1++;
	}
	vector<graduate>::iterator p = stu2.begin();
	if (count2 != 0 && count2 != 1)
		p++;
	else {
		cout << "������ɣ�" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (p != stu2.end())
	{
		if (p->getScore(2) == (p - 1)->getScore(2))
			p->getRanking1() = (p - 1)->getRanking1();
		p++;
	}
	Display(4, count2, stu2.begin(), stu2.end());
	sort(stu2.begin(), stu2.end(), comparing4);
	cout << "������ɣ�" << endl;
	system("pause");
	system("cls");
}

void Interface::sortByClass_undergraduate()
{
	string id1;   //רҵ���
	string id2;   //�༶���
	int count = 0;
	cout << "������ð༶��רҵ��ţ�";
	cin >> id1;
	cout << "������ð༶�İ༶��ţ�";
	cin >> id2;
	vector<undergraduate>::iterator p = stu1.begin();
	vector<undergraduate>student;
	while (p != stu1.end())
	{
		if (p->getClassNumber() == id2 && p->getMajorNumber() == id1)
		{
			student.push_back(*p);
			p = stu1.erase(p);
			count++;
		}
		else
			p++;
	}
	if (!count)
	{
		cout << "û���ҵ��ð༶�������Ϣ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	sort(student.begin(), student.end(), comparing1);    //����
	vector<undergraduate>::iterator p2 = student.begin();
	int count2 = 1;
	while (p2 != student.end())
	{
		p2->getranking2() = count2++;
		if (p2 != student.begin())
		{
			if (p2->getScore(3) == (p2 - 1)->getScore(3))
				p2->getranking2() = (p2 - 1)->getranking2();
		}
		stu1.push_back(*p2);
		p2++;
	}
	Display(3, count, student.begin(), student.end());    //��ʾ��������Ϣ
	sort(stu1.begin(), stu1.end(), comparing3);    //����ѧ�����򣬻ָ���ʼ��̬
}

void Interface::sortByClass_graduate()
{
	string id1;   //רҵ���
	string id2;   //�༶���
	int count = 0;
	cout << "������ð༶��רҵ��ţ�";
	cin >> id1;
	cout << "������ð༶�İ༶��ţ�";
	cin >> id2;
	if (count2 == 0)
	{
		cout << "û����ص��о�����Ϣ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<graduate>::iterator p = stu2.begin();
	vector<graduate>student;
	while (p != stu2.end())
	{
		if (p->getClassNumber() == id2 && p->getMajorNumber() == id1)
		{
			student.push_back(*p);
			p = stu2.erase(p);
			count++;
		}
		else
			p++;
	}
	if (count == 0)
	{
		cout << "û���ҵ��ð༶�������Ϣ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	sort(student.begin(), student.end(), comparing2);    //����
	vector<graduate>::iterator p2 = student.begin();
	int count2 = 1;
	while (p2 != student.end())
	{
		p2->getranking2() = count2++;
		if (p2 != student.begin())
		{
			if (p2->getScore(2) == (p2 - 1)->getScore(2))
				p2->getranking2() = (p2 - 1)->getranking2();
		}
		stu2.push_back(*p2);
		p2++;
	}
	Display(4, count, student.begin(), student.end());    //��ʾ��������Ϣ
	sort(stu2.begin(), stu2.end(), comparing4);    //����ѧ�����򣬻ָ���ʼ��̬
}