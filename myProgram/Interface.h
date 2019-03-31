#pragma once
//#ifdef INTERFACE
//#define INTERFACE
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<vector>
#include<cstdlib>
#include"Data.h"

class Interface
{
private:
	vector<undergraduate>stu1;    //������
	vector<graduate>stu2;         //�о���
	vector<Class>Cla;             //�༶
	vector<major>maj;             //רҵ
	static int count1;    //��¼������������
	static int count2;    //��¼�о���������
	static int count3;    //��¼�༶������
	static int count4;    //��¼רҵ������
public:
	Interface();          //���ļ����Ҷ�ȡ�ļ�����
	void menu();          //���˵�����
	void menu1();         //����Ա�˵�����
	void menu2();         //��ʦ����˵�����
	void menu3();
	void menu4();
	void menu5();
	void menu6();
	void menu7(int n);
	void menu8();
	void run();                //��������
	void save();               //�رճ��򲢱�������
	void Administrator();      //רҵ/�༶������
	void Teacher();          //רҵ���༶��Ա������
	void creatMajor();         //����רҵ
	void Delete_Major();       //ɾ��רҵ�Լ������Ա����Ϣ
	void motify1();            //�޸�רҵ��Ϣ
	void creatClass();         //����һ���µİ༶
	void Delete_Class();       //ɾ��һ���༶����Ϣ
	void motify2();          //�޸İ༶��Ϣ
	template<class T>void getPage(int page, T begin, T end);   //��ȡ��ǰҳ����������Ϣ
	template<class T>void Display(int n, int count, T begin, T end);       //��ʾ����רҵ���༶�Լ�����ѧ���������Ϣ
	void Input();    //���ӱ����������о����Ļ���������Ϣ
	void InputScore();       //�������뱾���������о����ɼ�
	void motify3();          //����ѧ���޸�ѧ�������Ϣ
	void motify4();          //���������޸�ѧ�������Ϣ
	void Delete_student();   //����ѧ��ɾ��ѧ����Ϣ
	void DisplayByClass();   //������༶��ѧ����Ϣ
	void DisplayByMajor();   //�����רҵ��ѧ����Ϣ
	void DisplayByName();    //�����������ѧ����Ϣ
	void DisplayByID();      //����ѧ�Ų�ѯ������Ϣ
	void DisplayFailStudent();  //��ѯĳ�༶��ĳ��Ŀ�����������
	static bool comparing1(undergraduate s1, undergraduate s2);  //�Ƚ϶����ܳɼ���С
	static bool comparing2(graduate s1, graduate s2);  //�Ƚ϶����ܳɼ���С
	static bool comparing3(undergraduate s1, undergraduate s2);  //�Ƚ϶���ѧ��
	static bool comparing4(graduate s1, graduate s2);  //�Ƚ�ѧ��
	void sortUndergraduate();   //����ȫ��������
	void sortGraduate();        //����ȫ���о���
	void sortByClass_undergraduate();        //���򱾿����༶
	void sortByClass_graduate();      //�����о����༶
	void statistic1();                //ͳ��ĳ�༶ƽ���֡���߷ֺ���ͷ�
	void statistic2();                //ͳ��ĳ�༶����ƽ���ֵ������Լ�����
	void statistic3();                //ͳ��ĳ�༶ĳ��Ŀ�����������������
	void statistic4();                //ͳ��ĳ�༶ĳ��Ŀ��ͬ�ȼ���ѧ������
	void motify5();                   //�޸ĸ���רҵ���
	void motify6();                   //�޸ĸ��˰༶���
};

//#endif

// ��ȡ��ǰ��ҳ��,pageΪ��ǰ��ҳ��
template<class T>
void Interface::getPage(int page, T begin, T end) 
{
	T beg = begin;
	int count = 0, page1, page2;
	page1 = (page - 1) * 10;
	page2 = (page) * 10;
	while (beg != end)
	{
		count++;
		if (count > page1)
			break;
		beg++;
	}
	while (beg != end && count <= page)
	{
		beg->Display();
		count++;
		beg++;
	}
}

// ��ʾ����ѧ������Ϣ��nΪ��ʾ����
template<class T>     
void Interface::Display(int n, int count, T begin, T end)    
{
	int page = 1, allpage;
	int choose;
	if (count <= 10 && count > 0)
	{
		allpage = 1;
	}
	else if (count == 0)
	{
		allpage = 0;
		cout << "û�����ѧ����Ϣ���밴���������..." << endl;
		system("pause");
		system("pause");
		return;
	}
	else if (count % 10)
	{
		allpage = count / 10 + 1;
	}
	else
	{
		allpage = count / 10;
	}
	do {
		if (page == 1 && allpage == 1) {
			printf("======================================================================\n");
			menu7(n);
			printf("----------------------------------------------------------------------\n");
			getPage(page, begin, end);
			printf("----------------------------------------------------------------------\n");
			printf("             ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��0������\n", page, allpage);
			printf("======================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf_s("%d", &choose);
				if (choose != 0)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		else if (page == 1 && allpage > 1) {
			printf("=============================================================================\n");
			menu7(n);
			getPage(page, begin, end);
			printf("-----------------------------------------------------------------------------\n");
			printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��2����һҳ ��4��βҳ ��0���˳�\n", page, allpage);
			printf("==============================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf_s("%d", &choose);
				if (choose != 0 && choose != 2 && choose != 4)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		else if (page > 1 && page != allpage) {
			printf("================================================================================================\n");
			menu7(n);
			getPage(page, begin, end);
			printf("------------------------------------------------------------------------------------------------\n");
			printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��2����һҳ ��3����ҳ ��4��βҳ ��0���˳�\n", page, allpage);
			printf("================================================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf_s("%d", &choose);
				if (choose != 0 && choose != 2 && choose != 4 && choose != 1 && choose != 3)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		else if (page == allpage) {
			printf("=============================================================================\n");
			menu7(n);
			getPage(page, begin, end);
			printf("-----------------------------------------------------------------------------\n");
			printf("  ��ǰҳΪ��%dҳ  ��ҳ��Ϊ%dҳ ��1����һҳ ��3����ҳ��0���˳�\n", page, allpage);
			printf("=============================================================================\n");
			do {
				printf("��ѡ��>>");
				scanf_s("%d", &choose);
				if (choose != 0 && choose != 1 && choose != 3)
					printf("��������������ѡ��...\n");
				else break;
			} while (1);
		}
		if (choose == 1)
			page--;
		if (choose == 2)
			page++;
		if (choose == 3)
			page = 1;
		if (choose == 4)
			page = allpage;
		if (choose == 0)break;
		system("cls");
	} while (1);
	cout << "��ѯ�������밴���������..." << endl;
	system("pause");
	system("cls");
}
