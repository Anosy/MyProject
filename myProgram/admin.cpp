#include"interface.h"

/*=======================================רҵ����ģ��==========================================*/

//������רҵ
void Interface::creatMajor()  
{
	string name, id;
	char ch;
	while (1) {
		cout << "��������רҵ�����ƣ�";
		cin >> name;
		cout << "��������רҵ��רҵ��ţ�";
		cin >> id;
		major Maj(name, id);
		maj.push_back(Maj);
		count4++;
		cout << "����ɹ���" << endl;
		cout << "�Ƿ�������루y or n��:";
		cin >> ch;
		if (ch == 'n' || ch == 'N' || ch == 50)
			return;
	}
}

//ɾ��ĳרҵ�Լ���ذ༶����Ա
void Interface::Delete_Major()  
{
	int flag = 0;
	string name, id;
	cout << "��������Ҫɾ����רҵ��Ϣ�����ƣ�";
	cin >> name;
	cout << "������רҵ��ţ�";
	cin >> id;
	vector<major>::iterator p = maj.begin();
	while (p != maj.end())
	{
		if (name == p->getName() && id == p->getID())
		{
			cout << "�Ѿ��ҵ���רҵ�������Ϣ(ע�⣺���ɾ���������רҵ��صİ༶�Լ���Ա����һ��ɾ��)" << endl;
			cout << "�Ƿ�ȷ��ɾ����y or n����";
			char ch;
			cin >> ch;
			if (ch == 'Y' || ch == 'y') {
				maj.erase(p++);
				count4--;
				cout << "ɾ���ɹ���" << endl;
				flag = 1;
				break;
			}
			else
			{
				cout << "û��ɾ����¼��׼���ص��˵�ҳ��..." << endl;
				system("pause");
				return;
			}
		}
		else
			p++;
	}
	if (flag == 0)
	{
		cout << "û���ҵ���רҵ�������Ϣ��׼���ص��˵�ҳ��..." << endl;
		system("pause");
		return;
	}
	//ɾ����רҵ�����а༶��Ϣ
	vector<Class>::iterator p2 = Cla.begin();
	while (p2 != Cla.end())
	{
		if (name == p2->getMajor() && id == p2->getMajor_number())
		{
			p2 = Cla.erase(p2);
			count3--;
		}
		else
			p2++;
	}
	cout << "�Ѿ�ɾ�����רҵ��ص����а༶��Ϣ" << endl;
	//ɾ����רҵ��������Ա��Ϣ
	vector<undergraduate>::iterator p3 = stu1.begin();
	while (p3 != stu1.end())
	{
		if (name == p3->getMajor() && id == p3->getMajorNumber())
		{
			p3 = stu1.erase(p3);
			count1--;
		}
		else
			p3++;
	}
	cout << "�Ѿ�ɾ�����רҵ��ص����б�������Ϣ" << endl;
	vector<graduate>::iterator p4 = stu2.begin();
	while (p4 != stu2.end())
	{
		if (name == p4->getMajor() && id == p4->getMajorNumber())
		{
			p4 = stu2.erase(p4);
			count2--;
		}
		else
			p4++;
	}
	cout << "�Ѿ�ɾ�����רҵ��ص������о�����Ϣ" << endl;
	cout << "������Ϣ�Ѿ�ɾ���ɹ����밴������ص��˵���..." << endl;
	system("pause");
}

//�޸�ĳרҵ�Լ���ذ༶����Ա
void Interface::motify1()
{
	int flag = 0;
	string name, id;
	string name1, id1;
	cout << "��������Ҫ�޸���Ϣ��רҵ��ţ�";
	cin >> id;
	cout << "��������Ҫ�޸���Ϣ��רҵ���ƣ�";
	cin >> name;
	vector<major>::iterator p = maj.begin();
	while (p != maj.end())
	{
		if (name == p->getName() && id == p->getID())
		{
			flag = 1;
			cout << "�Ѿ��ҵ���רҵ�������Ϣ��ע�⣺�����޸ģ����һ���޸��������רҵ��صİ༶����Ա����Ϣ��" << endl;
			cout << "�Ƿ�ȷ���޸ģ�y or n����";
			char ch;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				cout << "�������޸ĺ��רҵ���ƣ�";
				cin >> name1;
				cout << "�������޸ĺ��רҵ��ţ�";
				cin >> id1;
				p->getID() = id1;
				p->getName() = name1;
				cout << "�޸ĸ�רҵ����Ϣ�ɹ���" << endl;
				break;
			}
		}
		else p++;
	}
	if (flag == 0)
	{
		cout << "û���ҵ����רҵ��ص���Ϣ���밴������ص��˵���..." << endl;
		system("pause");
		return;
	}
	//�޸ĸ�רҵ�����а༶��Ϣ
	vector<Class>::iterator p2 = Cla.begin();
	while (p2 != Cla.end())
	{
		if (name == p2->getMajor() && id == p2->getMajor_number())
		{
			p2->getMajor_number() = id1;
			p2->getMajor() = name1;
		}
		else
			p2++;
	}
	cout << "�Ѿ��޸����רҵ��ص����а༶��Ϣ" << endl;
	//�޸ĸ�רҵ��������Ա��Ϣ
	vector<undergraduate>::iterator p3 = stu1.begin();
	while (p3 != stu1.end())
	{
		if (name == p3->getMajor() && id == p3->getMajorNumber())
		{
			p3->getMajor() = name1;
			p3->getMajorNumber() = id1;
		}
		else
			p3++;
	}
	cout << "�Ѿ��޸����רҵ��ص����б�������Ϣ" << endl;
	vector<graduate>::iterator p4 = stu2.begin();
	while (p4 != stu2.end())
	{
		if (name == p4->getMajor() && id == p4->getMajorNumber())
		{
			p4->getMajor() = name1;
			p4->getMajorNumber() = id1;
		}
		else
			p4++;
	}
	cout << "�Ѿ��޸����רҵ��ص������о�����Ϣ" << endl;
	cout << "������Ϣ�Ѿ��޸ĳɹ����밴������ص��˵���..." << endl;
	system("pause");
}


/*=======================================�༶����ģ��========================================*/

void Interface::creatClass()
{
	string name, id;   //�༶���ƣ��༶���
	string majorName, number;     //רҵ���ƣ�רҵ���
	cout << "�������°༶�����ƣ�";
	cin >> name;
	cout << "�������°༶�ı�ţ�";
	cin >> id;
	int flag = 0;
	while (!flag)
	{
		cout << "������ð༶��רҵ��ţ�ע�⣺�������벻���ڵ�רҵ��ţ���";
		cin >> number;
		cout << "������ð༶��רҵ���ƣ�ע�⣺�������벻���ڵ�רҵ���ƣ���";
		cin >> majorName;
		vector<major>::iterator p = maj.begin();
		while (p != maj.end())
		{
			if (p->getID() == number && p->getName() == majorName)
			{
				flag = 1;
				break;
			}
			else
				p++;
		}
		if (!flag)
		{
			cout << "�����רҵ��Ϣ�����ڣ����������룡" << endl;
		}
	}
	Class class1(number, majorName, name, id);
	Cla.push_back(class1);
	count3++;
	cout << "��ӳɹ���" << endl;
	system("pause");
}

//ɾ��ĳ�༶�Լ��༶����Ա
void Interface::Delete_Class()
{
	string id;
	string number;
	int flag = 1;
	cout << "�������Ӧ�İ༶��ţ�";
	cin >> id;
	cout << "�������Ӧ��רҵ��ţ�";
	cin >> number;
	vector<Class>::iterator p = Cla.begin();
	while (p != Cla.end())
	{
		if (p->getID() == id && p->getMajor_number() == number)
		{
			Cla.erase(p++);
			cout << "�ð༶��Ϣɾ���ɹ���" << endl;
			flag = 0;
			break;
		}
		else
			p++;
	}
	if (flag)
	{
		cout << "û���ҵ���صİ༶��Ϣ����˶������Ϣ�Ƿ�����" << endl;
		system("pause");
		return;
	}
	//ɾ���ð༶�����б�����
	vector<undergraduate>::iterator p2 = stu1.begin();
	while (p2 != stu1.end())
	{
		if (p2->getClassNumber() == id && p2->getMajorNumber() == number)
		{
			p2 = stu1.erase(p2);
		}
		else
			p2++;
	}
	// ɾ���ð༶�������о���
	vector<graduate>::iterator p3 = stu2.begin();
	while (p3 != stu2.end())
	{
		if (p3->getClassNumber() == id && p3->getMajorNumber() == number)
		{
			p3 = stu2.erase(p3);
		}
		else
			p3++;
	}
	cout << "�ð༶�ĵ�������Ա��Ϣ����ȫ��ɾ�����밴���������..." << endl;
	system("pause");
}

////�޸�ĳ�༶�Լ������Ա
void Interface::motify2()
{
	int flag = 0;
	string name1, id1;
	string name, id, number;
	cout << "��������Ҫ�޸���Ϣ�İ༶��ţ�";
	cin >> id;
	cout << "�������Ӧ�İ༶���ƣ�";
	cin >> name;
	cout << "�������Ӧ��רҵ��ţ�";
	cin >> number;
	vector<Class>::iterator p = Cla.begin();
	while (p != Cla.end())
	{
		if (p->getID() == id && p->getMajor_number() == number && p->getName() == name)
		{
			flag = 1;
			cout << "�Ѿ��ҵ��ð༶�������Ϣ��ע�⣺�����޸ģ����һ���޸�������ð༶��ص���Ա����Ϣ��" << endl;
			cout << "�Ƿ�ȷ���޸ģ�y or n����";
			char ch;
			cin >> ch;
			if (ch == 'y' || ch == 'Y')
			{
				cout << "�������޸ĺ�İ༶���ƣ�";
				cin >> name1;
				cout << "�������޸ĺ�İ༶��ţ�";
				cin >> id1;
				p->getID() = id1;
				p->getName() = name1;
				cout << "�޸ĸð༶����Ϣ�ɹ���" << endl;
				break;
			}
		}
		p++;
	}
	//�޸���ð༶��Ϣ��صı�������Ϣ���о�����Ϣ
	vector<undergraduate>::iterator p2 = stu1.begin();
	while (p2 != stu1.end())
	{
		if (p2->getClassNumber() == id && p2->getClass() == name && p2->getMajorNumber() == number)
		{
			p2->getClass() = name1;
			p2->getClassNumber() = id1;
		}
		else
			p2++;
	}
	vector<graduate>::iterator p3 = stu2.begin();
	while (p3 != stu2.end())
	{
		if (p3->getClassNumber() == id && p3->getClass() == name && p3->getMajorNumber() == number)
		{
			p3->getClass() = name1;
			p3->getClassNumber() = id1;
		}
		else
			p3++;
	}
	cout << "��ð༶��ص���Ա��Ϣ��ȫ���޸ĳɹ���" << endl;
	system("pause");
}