#include"Interface.h"

// ͳ�Ʒ���
void Interface::statistic1()
{
	string major_number;
	string class_number;
	cout << "��������Ҫͳ����Ϣ��ذ༶��Ϣ" << endl;
	cout << "������ð༶���꼶��ţ�";
	cin >> major_number;
	cout << "������ð༶�İ༶��ţ�";
	cin >> class_number;
	vector<major>::iterator p = maj.begin();
	while (p != maj.end())
	{
		if (p->getID() == major_number)
			break;
		else
			p++;
	}
	if (p == maj.end())
	{
		cout << "û����ص�רҵ��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<Class>::iterator p2 = Cla.begin();
	while (p2 != Cla.end())
	{
		if (p2->getID() == class_number)
			break;
		else
			p2++;
	}
	if (p2 == Cla.end())
	{
		cout << "û����صİ༶��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	int choose;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> choose;
	if (choose == 1)
	{
		if (!count1)
		{
			cout << "û�����ѧ������Ϣ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		vector<undergraduate>::iterator p = stu1.begin();
		int count = 0, sum = 0;
		double average;
		int max = p->getScore(3), min = p->getScore(3);
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(3) != 0)
			{
				count++;
				if (p->getScore(3) > max)
					max = p->getScore(3);
				if (p->getScore(3) < min)
					min = p->getScore(3);
				sum += p->getScore(3);
			}
			p++;
		}
		average = sum / count;
		cout << "ͳ����ɣ�" << endl;
		cout << "�ð༶��ƽ�����ǣ�" << average << endl;
		cout << "�ð༶����߷��ǣ�" << max << endl;
		cout << "�ð༶����ͷ��ǣ�" << min << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (choose == 2)
	{
		if (!count2)
		{
			cout << "û�����ѧ������Ϣ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		vector<graduate>::iterator p = stu2.begin();
		int count = 0, sum = 0;
		double average;
		int max = p->getScore(2), min = p->getScore(2);
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(2) != 0)
			{
				count++;
				if (p->getScore(2) > max)
					max = p->getScore(2);
				if (p->getScore(2) < min)
					min = p->getScore(2);
				sum += p->getScore(2);
			}
			p++;
		}
		average = sum / count;
		cout << "ͳ����ɣ�" << endl;
		cout << "�ð༶��ƽ�����ǣ�" << average << endl;
		cout << "�ð༶����߷��ǣ�" << max << endl;
		cout << "�ð༶����ͷ��ǣ�" << min << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�������ѧ������������˶Ժ�����..." << endl;
	system("pause");
	system("cls");
	return;
}

void Interface::statistic2()
{
	string major_number;
	string class_number;
	cout << "��������Ҫͳ����Ϣ��ذ༶��Ϣ" << endl;
	cout << "������ð༶���꼶��ţ�";
	cin >> major_number;
	cout << "������ð༶�İ༶��ţ�";
	cin >> class_number;
	vector<major>::iterator p = maj.begin();
	while (p != maj.end())
	{
		if (p->getID() == major_number)
			break;
		else
			p++;
	}
	if (p == maj.end())
	{
		cout << "û����ص�רҵ��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<Class>::iterator p2 = Cla.begin();
	while (p2 != Cla.end())
	{
		if (p2->getID() == class_number)
			break;
		else
			p2++;
	}
	if (p2 == Cla.end())
	{
		cout << "û����صİ༶��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	int choose;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> choose;
	if (choose == 1)
	{
		if (!count1)
		{
			cout << "û�����ѧ������Ϣ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		vector<undergraduate>::iterator p = stu1.begin();
		int count = 0, sum = 0;
		double average;
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(3) != 0)
			{
				count++;
				sum += p->getScore(3);
			}
			p++;
		}
		if (!count)
		{
			cout << "û���ҵ��ð༶����سɼ���Ϣ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		average = sum / count;
		p = stu1.begin();
		int count2 = 0;      //ͳ�Ƴ���ƽ���ֵ�����
		vector<undergraduate>student;
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(3) >= average)
			{
				student.push_back(*p);
				count2++;
			}
			p++;
		}
		cout << "ͳ�ƽ�����" << endl;
		Display(3, count2, student.begin(), student.end());
		return;
	}
	else if (choose == 2)
	{
		if (!count2)
		{
			cout << "û�����ѧ������Ϣ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		vector<graduate>::iterator p = stu2.begin();
		int count = 0, sum = 0;
		double average = 0;
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(2) >= average)
			{
				count++;
				sum += p->getScore(2);
			}
			p++;
		}
		if (!count)
		{
			cout << "û���ҵ��ð༶����سɼ���Ϣ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		average = sum / count;
		p = stu2.begin();
		int count2 = 0;      //ͳ�Ƴ���ƽ���ֵ�����
		vector<graduate>student;
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(2) >= average)
			{
				student.push_back(*p);
				count2++;
			}
			p++;
		}
		cout << "ͳ�ƽ�����" << endl;
		Display(4, count2, student.begin(), student.end());
		return;
	}
	cout << "�������ѧ������������˶Ժ�����..." << endl;
	system("pause");
	system("cls");
	return;
}

void Interface::statistic3()
{
	string major_number;
	string class_number;
	cout << "��������Ҫͳ�Ʒ����İ༶��Ϣ" << endl;
	cout << "������רҵ��ţ�";
	cin >> major_number;
	cout << "������༶��ţ�";
	cin >> class_number;
	vector<major>::iterator p = maj.begin();
	while (p != maj.end())
	{
		if (p->getID() == major_number)
			break;
		else
			p++;
	}
	if (p == maj.end())
	{
		cout << "û����ص�רҵ��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<Class>::iterator p2 = Cla.begin();
	while (p2 != Cla.end())
	{
		if (p2->getID() == class_number)
			break;
		else
			p2++;
	}
	if (p2 == Cla.end())
	{
		cout << "û����صİ༶��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	int choose, subject;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> choose;
	if (choose == 1)
	{
		while (1)
		{
			cout << "����������Ҫͳ����Ϣ�Ŀ�Ŀ��C���ԣ�1��������2��Ӣ�3����";
			cin >> subject;
			if (subject == 1 || subject == 2 || subject == 3)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		vector<undergraduate>::iterator p = stu1.begin();
		vector<undergraduate>student;
		int count = 0;   //ͳ�Ʋ���������
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(subject - 1) <= 60)
			{
				student.push_back(*p);
				count++;
			}
			p++;
		}
		if (!count)
		{
			cout << "�ð༶û�в�����������" << endl;
			system("pause");
			system("cls");
			return;
		}
		Display(3, count, student.begin(), student.end());
	}
	else if (choose == 2)
	{
		while (1)
		{
			cout << "����������Ҫͳ����Ϣ�Ŀ�Ŀ���γ���ƣ�1�����ĳɼ���2����";
			cin >> subject;
			if (subject == 1 || subject == 2)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		vector<graduate>::iterator p = stu2.begin();
		vector<graduate>student;
		int count = 0;   //ͳ�Ʋ���������
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getScore(subject - 1) <= 60)
			{
				student.push_back(*p);
				count++;
			}
			p++;
		}
		if (!count)
		{
			cout << "�ð༶û�в�����������" << endl;
			system("pause");
			system("cls");
			return;
		}
		Display(4, count, student.begin(), student.end());
	}
	else
	{
		cout << "�����ѧ������������˶Ժ����룡" << endl;
		system("pause");
		system("cls");
		return;
	}
}

void Interface::statistic4()
{
	string major_number;
	string class_number;
	cout << "��������Ҫͳ�Ʒ����İ༶��Ϣ" << endl;
	cout << "������רҵ��ţ�";
	cin >> major_number;
	cout << "������༶��ţ�";
	cin >> class_number;
	vector<major>::iterator p = maj.begin();
	while (p != maj.end())
	{
		if (p->getID() == major_number)
			break;
		else
			p++;
	}
	if (p == maj.end())
	{
		cout << "û����ص�רҵ��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<Class>::iterator p2 = Cla.begin();
	while (p2 != Cla.end())
	{
		if (p2->getID() == class_number)
			break;
		else
			p2++;
	}
	if (p2 == Cla.end())
	{
		cout << "û����صİ༶��Ϣ����˶Ժ�����" << endl;
		system("pause");
		system("cls");
		return;
	}
	int choose, subject;
	cout << "������ѧ�����ͣ���������1 or �о�����2����";
	cin >> choose;
	if (choose == 1)
	{
		while (1)
		{
			cout << "����������Ҫͳ����Ϣ�Ŀ�Ŀ��C���ԣ�1��������2��Ӣ�3����";
			cin >> subject;
			if (subject == 1 || subject == 2 || subject == 3)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		vector<undergraduate>::iterator p = stu1.begin();
		static int count[5];
		while (p != stu1.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getMajorNumber() == major_number && p->getClassNumber() == class_number)
			{
				if (p->getScore(subject - 1) == 100)
					count[4]++;
				else if (p->getScore(subject - 1) < 60)
					count[0]++;
				else
					count[subject - 1]++;
			}
			p++;
		}
		cout << "ͳ����ɣ���Ϣ����" << endl;
		cout << "��������Ϊ�� " << count[4] << "λ" << endl;
		cout << "��������Ϊ�� " << count[3] << "λ" << endl;
		cout << "�е�����Ϊ�� " << count[2] << "λ" << endl;
		cout << "��������Ϊ�� " << count[1] << "λ" << endl;
		cout << "����������Ϊ�� " << count[0] << "λ" << endl;
		system("pause");
		system("cls");
		return;
	}
	else if (choose == 2)
	{
		while (1)
		{
			cout << "����������Ҫͳ����Ϣ�Ŀ�Ŀ���γ���ƣ�1�����ĳɼ���2����";
			cin >> subject;
			if (subject == 1 || subject == 2)
				break;
			else
				cout << "�����������������룡" << endl;
		}
		vector<graduate>::iterator p = stu2.begin();
		static int count[5];
		while (p != stu2.end())
		{
			if (p->getMajorNumber() == major_number && p->getClassNumber() == class_number && p->getMajorNumber() == major_number && p->getClassNumber() == class_number)
			{
				if (p->getScore(subject - 1) == 100)
					count[4]++;
				else if (p->getScore(subject - 1) < 60)
					count[0]++;
				else
					count[subject - 1]++;
			}
			p++;
		}
		cout << "ͳ����ɣ���Ϣ����" << endl;
		cout << "��������Ϊ�� " << count[4] << "λ" << endl;
		cout << "��������Ϊ�� " << count[3] << "λ" << endl;
		cout << "�е�����Ϊ�� " << count[2] << "λ" << endl;
		cout << "��������Ϊ�� " << count[1] << "λ" << endl;
		cout << "����������Ϊ�� " << count[0] << "λ" << endl;
		system("pause");
		system("cls");
		return;
	}
}
