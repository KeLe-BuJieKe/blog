#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using  namespace std;

//class Person	//����
//{
//public:
//	//��ʾ������Ϣ
//	void ShowPerson();
//
//private:
//	string m_name;		//����
//	int m_age;			//����
//	string m_sex;		//�Ա� 
//};


class Person	//����
{
public:
	//��ʾ������Ϣ
	void ShowPerson();

private:
	char* m_name;		//����
	int   m_age;		//����
	char* m_sex;		//�Ա�
};