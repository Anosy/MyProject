#include"Data.h"
//Person�ຯ��ʵ��

int &Person::getID()
{
	return id;
}

string &Person::getName()
{
	return name;
}

string &Person::getSex()
{
	return sex;
}

string &Person::getMajorNumber()
{
	return major_number;
}

string &Person::getClassNumber()
{
	return class_number;
}

string &Person::getMajor()
{
	return major;
}

string &Person::getClass()
{
	return Class;
}

int &Person::getScore(int n)
{
	return sco.getScore(n);
}


void Person::motify(int n)
{
	int temp;
	switch (n) {
	case 1:cout << "��������ȷ�����֣�"; cin >> temp; name = temp; break;
	case 2:cout << "��������ȷ���Ա�"; cin >> temp; sex = temp; break;
	}
}

int &Person::getRanking1()
{
	return gradeRanking;
}

int &Person::getranking2()
{
	return classRanking;
}


//�������ຯ��ʵ��

void undergraduate::Display()
{
	cout << setw(7) << id << setw(7) << name << setw(5) << sex << setw(11) << major_number << setw(7) << class_number << setw(11) << major << setw(12) << Class << setw(7) << sco.getScore(0) << setw(10) << sco.getScore(1) << setw(10) << sco.getScore(2) << setw(10) << sco.getScore(3) << setw(10) << classRanking << setw(10) << gradeRanking << endl;
}

void undergraduate::print()
{
	cout << "��A��ID�� " << id << endl;
	cout << "��1�����֣� " << name << endl;
	cout << "��2���Ա� " << sex << endl;
	cout << "��3��רҵ��ţ�" << major_number << endl;
	cout << "��B��רҵ���ƣ�" << major << endl;
	cout << "��4���༶��ţ� " << class_number << endl;
	cout << "��C���༶���ƣ�" << Class << endl;
	cout << "��5��C���Գɼ��� " << sco.getScore(0) << endl;
	cout << "��6�������ɼ��� " << sco.getScore(1) << endl;
	cout << "��7��Ӣ��ɼ��� " << sco.getScore(2) << endl;
	cout << "��D���ܳɼ��� " << sco.getScore(3) << endl;
	cout << "��E���༶������ " << gradeRanking << endl;
	cout << "��F���꼶������ " << classRanking << endl;
}

void undergraduate::motify(int n)
{
	if (n <= 4)
	{
		Person &p = *this;
		p.Person::motify(n);
	}
	else
	{
		string temp;
		int score;
		switch (n)
		{
		case 5:cout << "��������ȷ��C���Գɼ���"; cin >> score; sco.getScore(0) = score; break;
		case 6:cout << "��������ȷ�ĸ����ɼ���"; cin >> score; sco.getScore(1) = score; break;
		case 7:cout << "��������ȷ��Ӣ��ɼ���"; cin >> score; sco.getScore(2) = score; break;
		case 0:cout << "�޸Ľ������밴������ص��˵�����" << endl; break;
		}
		sco.calculation();  
	}
	cout << "�޸ĳɹ���" << endl;
}


//�о����ຯ��ʵ��

void graduate::Display()
{
	cout << setw(7) << id << setw(7) << name << setw(5) << sex << setw(11) << major_number << setw(7) << class_number << setw(11) << major << setw(12) << Class << setw(9) << sco.getScore(0) << setw(12) << sco.getScore(1) << setw(10) << sco.getScore(2) << setw(7) << classRanking << setw(10) << gradeRanking << endl;
}

void graduate::print()
{
	cout << "��A��ID�� " << id << endl;
	cout << "��1�����֣� " << name << endl;
	cout << "��2���Ա� " << sex << endl;
	cout << "��3��רҵ��ţ�" << major_number << endl;
	cout << "��B��רҵ���ƣ� " << major << endl;
	cout << "��4���༶��ţ� " << class_number << endl;
	cout << "��C���༶���ƣ� " << Class << endl;
	cout << "��5���γ��ۺϳɼ��� " << sco.getScore(0) << endl;
	cout << "��6�����ĳɼ��� " << sco.getScore(1) << endl;
	cout << "��D���ܳɼ��� " << sco.getScore(2) << endl;
	cout << "��E���༶������ " << gradeRanking << endl;
	cout << "��F���꼶������ " << classRanking << endl;
}

void graduate::motify(int n)
{
	if (n <= 4)
	{
		Person &p = *this;
		p.Person::motify(n);
	}
	else
	{
		int score;
		switch (n)
		{
		case 5:cout << "��������ȷ�Ŀγ���Ƴɼ���"; cin >> score; sco.getScore(0) = score; break;
		case 6:cout << "��������ȷ�����ĳɼ���"; cin >> score; sco.getScore(1) = score; break;
		case 0:cout << "�޸Ľ������밴������ص��˵�����" << endl; break;
		}
		sco.calculation();
	}
}


//�༶�ຯ��ʵ��

void Class::Display() const
{
	cout << setw(15) << major_number << setw(11) << major << setw(17) << id << setw(17) << name << endl;
}

string &Class::getMajor_number()
{
	return major_number;
}

string &Class::getMajor()
{
	return major;
}

string &Class::getName()
{
	return name;
}

string &Class::getID()
{
	return id;
}

//�꼶�ຯ��ʵ��

void major::Display() const
{
	cout << setw(14) << id << setw(12) << name << endl;
}

string &major::getName()
{
	return name;
}

string &major::getID()
{
	return id;
}
