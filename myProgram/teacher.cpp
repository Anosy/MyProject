#include"interface.h"


void Interface::Input()    //�������뱾���������о����Ļ�����Ϣ
{
	int id;
	string name;
	string sex;
	string major_number;    //רҵ���
	string class_number;    //�༶���
	string Class1;
	string major1;
	string type;
	int i, n;
	int flag = 1;
	cout << "��������Ҫ¼����Ϣ��ѧ��������";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "λѧ����Ϣ" << endl;
		cout << "������ѧ��������";
		cin >> name;
		cout << "������ѧ���Ա�";
		cin >> sex;
		while (flag) {
			cout << "������רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
			cin >> major_number;
			vector<major>::iterator p = maj.begin();
			while (p != maj.end())
			{
				if (p->getID() == major_number)
				{
					flag = 0;
					major1 = p->getName();
					break;
				}
				else
					p++;
			}
			if (flag)
			{
				cout << "�����רҵ��Ų����ڣ����ʵ..." << endl;
			}
		}
		flag = 1;
		while (flag) {
			cout << "������༶��ţ�ע�⣺�������벻���ڵİ༶��ţ���";
			cin >> class_number;
			vector<Class>::iterator p1 = Cla.begin();
			while (p1 != Cla.end())
			{
				if (p1->getID() == class_number)
				{
					flag = 0;
					Class1 = p1->getName();
					break;
				}
				else
					p1++;
			}
			if (flag)
			{
				cout << "����İ༶��Ų����ڣ����ʵ..." << endl;
			}
		}
		flag = 1;
		while (1)
		{
			cout << "������ѧ������о��� or ����������";
			cin >> type;
			if (type != "�о���"&&type != "������")
				cout << "�������Ϣ�������������룡" << endl;
			else
				break;
		}
		if (type == "������")
		{
			count1++;
			id = count1;
			undergraduate s(id, name, sex, major_number, class_number, major1, Class1, 0, 0, 4);
			stu1.push_back(s);
		}
		else
		{
			count2++;
			id = count2;
			graduate s(id, name, sex, major_number, class_number, major1, Class1, 0, 0, 3);
			stu2.push_back(s);
		}
		cout << "����ɹ���";
		system("pause");
		system("cls");

	}
	cout << "������Ϣ¼����ɣ�" << endl;
	system("pause");
	system("cls");
}

//����ѧ���޸�ѧ��������Ϣ
void Interface::motify3()    
{
	int id;
	int choose, flag = 1;
	cout << "������ѧ��ѧ�ţ�";
	cin >> id;
	cout << "������ѡ��ѧ����𣨱�������1  or   �о�����2��" << endl;
	cout << "��ѡ��";
	cin >> choose;
	if (choose == 1)
	{
		vector<undergraduate>::iterator p = stu1.begin();
		while (p != stu1.end())
		{
			if (p->getID() == id)
			{
				cout << "�Ѿ��ҵ�������Ϣ��" << endl;
				flag = 0;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "������Ϣ�����ڣ���˶���������..." << endl;
			system("pause");
			return;
		}
		int choose1 = 1;
		while (choose1)
		{
			p->print();
			cout << "��0���˳�" << endl;
			cout << "��������Ҫ�޸ĵ���Ŀ��0-7����";
			cin >> choose1;
			if (choose1 != 3 && choose1 != 4)
				p->motify(choose1);
			else if (choose1 == 3)
			{
				string id;
				cout << "�������޸ĺ��רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
				cin >> id;
				vector<major>::iterator p2 = maj.begin();
				while (p2 != maj.end())
				{
					if (p2->getID() == id)
					{
						p->getMajorNumber() = id;
						p->getMajor() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == maj.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			else if (choose1 == 4)
			{
				string id;
				cout << "�������޸ĺ�İ༶��ţ�ע�⣺�������벻���ڵİ༶��ţ���";
				cin >> id;
				vector<Class>::iterator p2 = Cla.begin();
				while (p2 != Cla.end())
				{
					if (p2->getID() == id)
					{
						p->getClassNumber() = id;
						p->getClass() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == Cla.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			system("cls");
		}
	}
	else
	{
		vector<graduate>::iterator p = stu2.begin();
		while (p != stu2.end())
		{
			if (p->getID() == id)
			{
				cout << "�Ѿ��ҵ�������Ϣ��" << endl;
				flag = 0;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "������Ϣ�����ڣ���˶���������..." << endl;
			system("pause");
			return;
		}
		int choose1 = 1;
		while (choose1)
		{
			p->print();
			cout << "��0���˳�" << endl;
			cout << "��������Ҫ�޸ĵ���Ŀ��0-6����";
			cin >> choose1;
			if (choose1 != 3 && choose1 != 4)
				p->motify(choose1);
			else if (choose1 == 3)
			{
				string id;
				cout << "�������޸ĺ��רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
				cin >> id;
				vector<major>::iterator p2 = maj.begin();
				while (p2 != maj.end())
				{
					if (p2->getID() == id)
					{
						p->getMajorNumber() = id;
						p->getMajor() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == maj.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			else if (choose1 == 4)
			{
				string id;
				cout << "�������޸ĺ�İ༶��ţ�ע�⣺�������벻���ڵİ༶��ţ���";
				cin >> id;
				vector<Class>::iterator p2 = Cla.begin();
				while (p2 != Cla.end())
				{
					if (p2->getID() == id)
					{
						p->getClassNumber() = id;
						p->getClass() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == Cla.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			system("cls");
		}
	}
}

void Interface::InputScore()
{
	string major_number;
	string class_number;
	string type;
	int flag = 1;
	while (flag)
	{
		cout << "������רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
		cin >> major_number;
		vector<major>::iterator p = maj.begin();
		while (p != maj.end())
		{
			if (p->getID() == major_number)
			{
				flag = 0;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "��רҵ��Ų����ڣ����ʵ��������..." << endl;
		}
	}
	flag = 1;
	while (flag)
	{
		cout << "������༶��ţ�ע�⣺�������벻���ڵİ༶��ţ���";
		cin >> class_number;
		vector<Class>::iterator p1 = Cla.begin();
		while (p1 != Cla.end())
		{
			if (p1->getID() == class_number)
			{
				flag = 0;
				break;
			}
			else
				p1++;
		}
		if (flag)
		{
			cout << "�ð༶��Ų����ڣ����ʵ��������..." << endl;
		}
	}
	cout << "������ѧ������(������ or �о���)��";
	cin >> type;
	if (type == "������")
	{
		int choose;
		int flag = 1;    //���ð༶���Ƿ���ѧ����Ϣ
		int score;
		cout << "��������Ҫ����ɼ��Ŀο�Ŀ��C����-1������-2��Ӣ��-3����";
		cin >> choose;
		vector<undergraduate>::iterator p = stu1.begin();
		while (p != stu1.end())
		{
			if (p->getClassNumber() == class_number && p->getMajorNumber() == major_number)
			{
				flag = 0;
				cout << "������" << p->getName() << endl;
				switch (choose)
				{
				case 1:cout << "�����������C���Գɼ���"; break;
				case 2:cout << "����������ĸ����ɼ���"; break;
				case 3:cout << "�����������Ӣ��ɼ���"; break;
				default:cout << "����������ֹ����..." << endl; return;
				}
				cin >> score;
				p->getScore(choose - 1) = score;
				p++;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "�ð༶��û��ѧ���Ļ�����Ϣ���밴���������..." << endl;
			system("pause");
			return;
		}
		cout << "�ð���Ϣ����ɹ����밴���������..." << endl;
		system("pause");
	}
	else if (type == "�о���")
	{
		int choose;
		int flag = 1;    //���ð༶���Ƿ���ѧ����Ϣ
		int score;
		cout << "��������Ҫ����ɼ��Ŀο�Ŀ���γ����-1�����ĳɼ�-2����";
		cin >> choose;
		vector<graduate>::iterator p = stu2.begin();
		while (p != stu2.end())
		{
			if (p->getClassNumber() == class_number && p->getMajorNumber() == major_number)
			{
				flag = 0;
				cout << "������" << p->getName() << endl;
				switch (choose)
				{
				case 1:cout << "����������Ŀγ���Ƴɼ���"; break;
				case 2:cout << "��������������ĳɼ���"; break;
				default:cout << "����������ֹ����..." << endl; return;
				}
				cin >> score;
				p->getScore(choose - 1) = score;
				p++;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "�ð༶��û��ѧ���Ļ�����Ϣ���밴���������..." << endl;
			system("pause");
			return;
		}
		cout << "�ð���Ϣ����ɹ����밴���������..." << endl;
		system("pause");
	}
	else
	{
		cout << "��ѧ����𲻴��ڣ��밴���������..." << endl;
		system("pause");
	}
}

void Interface::Delete_student()
{
	string major_number;
	string class_number;
	int id;
	string type;
	int flag = 1;
	while (flag)
	{
		cout << "������רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
		cin >> major_number;
		vector<major>::iterator p = maj.begin();
		while (p != maj.end())
		{
			if (p->getID() == major_number)
			{
				flag = 0;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "��רҵ��Ų����ڣ����ʵ��������..." << endl;
		}
	}
	flag = 1;
	while (flag)
	{
		cout << "������༶��ţ�ע�⣺�������벻���ڵİ༶��ţ���";
		cin >> class_number;
		vector<Class>::iterator p1 = Cla.begin();
		while (p1 != Cla.end())
		{
			if (p1->getID() == class_number)
			{
				flag = 0;
				break;
			}
			else
				p1++;
		}
		if (flag)
		{
			cout << "�ð༶��Ų����ڣ����ʵ��������..." << endl;
		}
	}
	cout << "������ѧ����ID��";
	cin >> id;
	cout << "������ѧ������о��� or ����������";
	cin >> type;
	if (type == "������")
	{
		vector<undergraduate>::iterator p = stu1.begin();
		while (p != stu1.end())
		{
			if (p->getClassNumber() == class_number && p->getMajorNumber() == major_number && p->getID() == id)
			{
				cout << "�ѳɹ��ҵ�������Ϣ��" << endl;
				p->print();
				char ch;
				cout << "�Ƿ�ȷ��ɾ����y or n����";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					stu1.erase(p++);
					cout << "ɾ���ɹ����밴���������..." << endl;
					system("pause");
					return;
				}
				else
				{
					cout << "�밴������ص��˵���..." << endl;
					system("pause");
					return;
				}
			}
			else
				p++;
		}
	}
	else if (type == "�о���")
	{
		vector<graduate>::iterator p = stu2.begin();
		while (p != stu2.end())
		{
			if (p->getClassNumber() == class_number && p->getMajorNumber() == major_number && p->getID() == id)
			{
				cout << "�ѳɹ��ҵ�������Ϣ��" << endl;
				p->print();
				char ch;
				cin >> ch;
				cout << "�Ƿ�ȷ��ɾ����y or n����";
				if (ch == 'y' || ch == 'Y')
				{
					stu2.erase(p++);
					cout << "ɾ���ɹ����밴���������..." << endl;
					system("pause");
					return;
				}
				else
				{
					cout << "�밴������ص��˵���..." << endl;
					system("pause");
					return;
				}
			}
			else
				p++;
		}
	}
	else
	{
		cout << "��ѧ����𲻴��ڣ����ʵ������..." << endl;
		system("pause");
		return;
	}
	cout << "�����ڸ�����Ϣ�����ʵ..." << endl;
	system("pause");
}

//���������޸�ѧ����Ϣ
void Interface::motify4()   
{
	string name;
	int choose, flag = 1;
	cout << "������ѧ��������";
	cin >> name;
	cout << "������ѡ��ѧ����𣨱�������1  or   �о�����2��" << endl;
	cout << "��ѡ��";
	cin >> choose;
	if (choose == 1)
	{
		vector<undergraduate>::iterator p = stu1.begin();
		while (p != stu1.end())
		{
			if (p->getName() == name)
			{
				cout << "�Ѿ��ҵ�������Ϣ��" << endl;
				flag = 0;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "������Ϣ�����ڣ���˶���������..." << endl;
			system("pause");
			return;
		}
		int choose1 = 1;
		while (choose1)
		{
			p->print();
			cout << "��0���˳�" << endl;
			cout << "��������Ҫ�޸ĵ���Ŀ��0-7����";
			cin >> choose1;
			if (choose1 != 3 && choose1 != 4)
				p->motify(choose1);
			else if (choose1 == 3)
			{
				string id;
				cout << "�������޸ĺ��רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
				cin >> id;
				vector<major>::iterator p2 = maj.begin();
				while (p2 != maj.end())
				{
					if (p2->getID() == id)
					{
						p->getMajorNumber() = id;
						p->getMajor() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == maj.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			else if (choose1 == 4)
			{
				string id;
				cout << "�������޸ĺ�İ༶��ţ�ע�⣺�������벻���ڵİ༶��ţ���";
				cin >> id;
				vector<Class>::iterator p2 = Cla.begin();
				while (p2 != Cla.end())
				{
					if (p2->getID() == id)
					{
						p->getClassNumber() = id;
						p->getClass() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == Cla.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			system("cls");
		}
	}
	else
	{
		vector<graduate>::iterator p = stu2.begin();
		while (p != stu2.end())
		{
			if (p->getName() == name)
			{
				cout << "�Ѿ��ҵ�������Ϣ��" << endl;
				flag = 0;
				break;
			}
			else
				p++;
		}
		if (flag)
		{
			cout << "������Ϣ�����ڣ���˶���������..." << endl;
			system("pause");
			return;
		}
		int choose1 = 1;
		while (choose1)
		{
			p->print();
			cout << "��0���˳�" << endl;
			cout << "��������Ҫ�޸ĵ���Ŀ��0-6����";
			cin >> choose1;
			if (choose1 != 3 && choose1 != 4)
				p->motify(choose1);
			else if (choose1 == 3)
			{
				string id;
				cout << "�������޸ĺ��רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
				cin >> id;
				vector<major>::iterator p2 = maj.begin();
				while (p2 != maj.end())
				{
					if (p2->getID() == id)
					{
						p->getMajorNumber() = id;
						p->getMajor() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == maj.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			else if (choose1 == 4)
			{
				string id;
				cout << "�������޸ĺ�İ༶��ţ�ע�⣺�������벻���ڵİ༶��ţ���";
				cin >> id;
				vector<Class>::iterator p2 = Cla.begin();
				while (p2 != Cla.end())
				{
					if (p2->getID() == id)
					{
						p->getClassNumber() = id;
						p->getClass() = p2->getName();
						break;
					}
					else
						p2++;
				}
				if (p2 == Cla.end())
				{
					cout << "������ı�Ų����ڣ���˶Ժ��������룡" << endl;
					system("pause");
				}
			}
			system("cls");
		}
	}
}
