#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//int main()
//{
//	int* pi = new int(10);		//piָ��һ����ʼֵΪ10�� int �͵Ķ���
//	
//	//Ҳ����ʹ�÷ֿ����壬����
//	int* pj;
//	pj = new int(10);
//	system("pause");
//	return 0;
//}


int main()
{

	int* pa;
	pa = new int[5];	//paָ��5��δ��ʼ����int�����ݶ�����׵�ַ
	//�����Ҫ��pa�ڴ���ʱ�ͳ�ʼ����Ӧ��Ϊ���´���
	pa = new int[5]{ 1,2,3,4};	//��ʱ��һ��int�͵Ķ����ֵ��Ϊ1��ͬ�����Ķ���������{}�и�����ֵ
	//��{}�и�������ֵ�ĸ���С�ڴ����Ķ������ʱ���Ὣ��ֵĬ�ϳ�ʼ��Ϊ0

	return 0;
}