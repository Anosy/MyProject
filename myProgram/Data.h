#pragma once
//#ifdef _DATA
//#define _DATA
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class Score
{
private:
	vector<int> sco;
public:
	Score(vector<int>::const_iterator beg, vector<int>::const_iterator end)
	{
		while (beg != end)
		{
			sco.push_back(*beg);
			beg++;
		}
	}
	Score(int n)
	{
		sco.resize(n);
		vector<int>::iterator beg = sco.begin();
		while (beg != sco.end())
		{
			*beg = -1;
			beg++;
		}
	}

	void print() const     
	{
		vector<int>::const_iterator p = sco.begin();
		for (; p != sco.end(); p++)
			cout << *p << setw(3);
	}

	int getTotalScore() const  
	{
		vector<int>::const_iterator p = sco.end() - 1;
		return *p;
	}

	int &getScore(int n)
	{
		return sco[n];
	}

	void calculation()  
	{
		unsigned i;
		int sum;
		for (i = 0; i < sco.size() - 1; i++)  
		{
			if (sco[i] == -1)
				return;
		}
		for (i = 0, sum = 0; i < sco.size() - 1; i++) 
		{
			sum += sco[i];
		}
		sco[i] = sum;
	}
};


class Person    //Person��
{
protected:
	int id;                 //ѧ��
	string name;            //����
	string sex;             //�Ա�
	string major_number;    //רҵ���
	string class_number;    //�༶���
	string major;           //רҵ����
	string Class;           //�༶����
	string type;            //ѧ������
	int gradeRanking;       //�꼶����
	int classRanking;       //�༶����
	Score sco;
public:
	Person(int i, string na, string se, string num1, string num2, string maj, string cla, int rank1, int rank2, vector<int>::const_iterator begin, vector<int>::const_iterator end) :id(i), name(na), sex(se), major_number(num1), class_number(num2), major(maj), Class(cla), gradeRanking(rank1), classRanking(rank2), sco(begin, end)  
	{}
	Person(int i, string na, string se, string num1, string num2, string maj, string cla, int rank1, int rank2, int n) :id(i), name(na), sex(se), major_number(num1), class_number(num2), major(maj), Class(cla), gradeRanking(rank1), classRanking(rank2), sco(n)
	{}
	virtual void motify(int n);            //Ϊ���޸ĸ�����Ϣ����
	int &getID();            //���»�ȡ��Ϣ�ķŻ�ֵ������Ϊ������������ֵΪ�˷����޸�
	string &getName();       //��ȡ����
	string &getSex();        //��ȡ�Ա�
	string &getMajorNumber();//��ȡרҵ���
	string &getClassNumber();//��ȡ�༶���
	string &getMajor();      //��ȡרҵ����
	string &getClass();      //��ȡ�༶����
	int &getRanking1();      //��ȡ�꼶����
	int &getranking2();      //��ȡ�༶����
	int &getScore(int n);    //��ȡ���Ƴɼ�
};


class undergraduate :virtual public Person   //��������
{
public:
	undergraduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, vector<int>::const_iterator begin, vector<int>::const_iterator end) :Person(i, na, se, num1, num2, major, Class, rank1, rank2, begin, end)
	{}
	undergraduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, int n) :Person(i, na, se, num1, num2, major, Class, rank1, rank2, n)
	{}
	virtual void Display();      //��ʾ��������Ϣ
	virtual void print();        //��ʾ������Ϣ
	virtual void motify(int n);  //�޸ĸ�����Ϣ
};


class graduate :virtual public Person     //�о�����
{
public:
	graduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, vector<int>::const_iterator begin, vector<int>::const_iterator end) :Person(i, na, se, num1, num2, major, Class, rank1, rank2, begin, end)
	{}
	graduate(int i, string na, string se, string num1, string num2, string major, string Class, int rank1, int rank2, int n) :Person(i, na, se, num1, num2, major, Class, rank1, rank2, n)
	{}
	virtual void Display();      //��ʾ��������Ϣ
	virtual void print();        //��ʾ������Ϣ
	virtual void motify(int n);  //�޸ĸ�����Ϣ
};

class Class   //�༶��
{
private:
	string major_number;  //רҵ���
	string major;         //רҵ����
	string name;          //�༶����
	string id;            //�༶���
public:
	Class(string number, string maj, string na, string i) :major_number(number), major(maj), name(na), id(i)
	{}
	void Display() const;           //��ʾ���еİ༶����
	string &getMajor_number();      //��ȡרҵ���  
	string &getMajor();             //��ȡרҵ����
	string &getName();              //��ȡ�༶����
	string &getID();                //��ȡ�༶���
};

class major  //רҵ��
{
private:
	string name;        //רҵ����
	string id;          //רҵ���
public:
	major(string na, string i) :name(na), id(i)      //���캯��
	{}
	void Display() const;                         //��ʾ����
	string &getName();                            //��ȡרҵ����
	string &getID();                              //��ȡרҵ���
};

//#endif
