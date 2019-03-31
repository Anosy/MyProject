#include"interface.h"

Interface::Interface()
{
	ifstream student1("data/undergraduate");
	if (!student1)
	{
		cout << "can not open the file1 !" << endl;
		return;
	}
	ifstream student2("data/graduate");
	if (!student2)
	{
		cout << "can not open the file2 !" << endl;
		return;
	}
	ifstream Major("data/major");
	if (!Major)
	{
		cout << "can not open the file3 !" << endl;
		return;
	}
	ifstream cla("data/Class");
	if (!cla)
	{
		cout << "can not open the file4 !" << endl;
		return;
	}
	int id;
	string id1;
	string name1;
	string sex1;
	string major_number1;
	string class_number1;
	string major1;
	string Class1;
	int gradeRanking1;
	int classRanking1;

	//��ȡ�������ļ��е�����
	vector<int>score(4, 0);
	student1 >> id >> name1 >> sex1 >> major_number1 >> class_number1 >> major1 >> Class1 >> gradeRanking1 >> classRanking1 >> score[0] >> score[1] >> score[2] >> score[3];
	while (!student1.eof())
	{
		undergraduate student(id, name1, sex1, major_number1, class_number1, major1, Class1, gradeRanking1, classRanking1, score.begin(), score.end());
		stu1.push_back(student);
		count1++;   
		student1 >> id >> name1 >> sex1 >> major_number1 >> class_number1 >> major1 >> Class1 >> gradeRanking1 >> classRanking1 >> score[0] >> score[1] >> score[2] >> score[3];
	}

	//��ȡ�о����ļ��е�����
	score.clear();
	score.resize(3);
	student2 >> id >> name1 >> sex1 >> major_number1 >> class_number1 >> major1 >> Class1 >> gradeRanking1 >> classRanking1 >> score[0] >> score[1] >> score[2];
	while (!student2.eof())
	{
		graduate student(id, name1, sex1, major_number1, class_number1, major1, Class1, gradeRanking1, classRanking1, score.begin(), score.end());
		stu2.push_back(student);
		count2++;    
		student2 >> id >> name1 >> sex1 >> major_number1 >> class_number1 >> major1 >> Class1 >> gradeRanking1 >> classRanking1 >> score[0] >> score[1] >> score[2];

	}

	//��ȡ�༶��Ϣ�ļ��е�����
	string major_number;
	cla >> major_number >> major1 >> name1 >> id1;
	while (!cla.eof())
	{
		Class class1(major_number, major1, name1, id1);
		Cla.push_back(class1);
		count3++;     
		cla >> major_number >> major1 >> name1 >> id1;
	}

	//��ȡרҵ��Ϣ�ļ��е�����
	Major >> name1 >> id1;
	while (!Major.eof())
	{
		major maj1(name1, id1);
		maj.push_back(maj1);
		count4++;     
		Major >> name1 >> id1;
	}

	student1.close();
	student2.close();
	Major.close();
	cla.close();
}

//�����ļ�
void Interface::save()   
{
	ofstream out1("undergraduate");
	if (!out1)
	{
		cout << "���ļ�1ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out2("graduate");
	if (!out2)
	{
		cout << "���ļ�2ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out3("major");
	if (!out3)
	{
		cout << "���ļ�3ʧ�ܣ��޷���������" << endl;
		return;
	}
	ofstream out4("Class");
	if (!out4)
	{
		cout << "���ļ�4ʧ�ܣ��޷���������" << endl;
		return;
	}
	//�洢��������Ϣ
	vector<undergraduate>::iterator p = stu1.begin();
	while (p != stu1.end())
	{
		out1 << p->getID() << " " << p->getName() << " " << p->getSex() << " " << p->getMajorNumber() << " " << p->getClassNumber() << " " << p->getMajor() << " " << p->getClass() << " " << p->getRanking1() << " " << p->getranking2() << " " << p->getScore(0) << " " << p->getScore(1) << " " << p->getScore(2) << " " << p->getScore(3) << endl;
		p++;
	}
	printf("�ɹ��洢%dλ����������Ϣ��\n", count1);
	out1.close();

	//�洢�о�����Ϣ
	vector<graduate>::iterator p2 = stu2.begin();
	while (p2 != stu2.end())
	{
		out2 << p2->getID() << " " << p2->getName() << " " << p2->getSex() << " " << p2->getMajorNumber() << " " << p2->getClassNumber() << " " << p2->getMajor() << " " << p2->getClass() << " " << p2->getRanking1() << " " << p2->getranking2() << " " << p2->getScore(0) << " " << p2->getScore(1) << " " << p2->getScore(2) << endl;
		p2++;
	}
	out2.close();
	printf("�ɹ��洢%dλ�о�������Ϣ��\n", count2);

	//�洢רҵ��Ϣ
	vector<major>::iterator p3 = maj.begin();
	while (p3 != maj.end())
	{
		out3 << p3->getName() << " " << p3->getID() << endl;
		p3++;
	}
	out3.close();
	printf("�ɹ��洢%d��רҵ��Ϣ��\n", count4);

	//�洢�༶��Ϣ
	vector<Class>::iterator p4 = Cla.begin();
	while (p4 != Cla.end())
	{
		out4 << p4->getMajor_number() << " " << p4->getMajor() << " " << p4->getName() << " " << p4->getID() << endl;
		p4++;
	}
	out4.close();
	printf("�ɹ��洢%d���༶��Ϣ��\n", count3);
}