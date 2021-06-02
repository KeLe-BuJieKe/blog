#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using  namespace std;

//class Person	//人类
//{
//public:
//	//显示基本信息
//	void ShowPerson();
//
//private:
//	string m_name;		//姓名
//	int m_age;			//年龄
//	string m_sex;		//性别 
//};


class Person	//人类
{
public:
	//显示基本信息
	void ShowPerson();

private:
	char* m_name;		//姓名
	int   m_age;		//年龄
	char* m_sex;		//性别
};