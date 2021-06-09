#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//int main()
//{
//	int* pi = new int(10);		//pi指向一个初始值为10的 int 型的对象
//	
//	//也可以使用分开定义，如下
//	int* pj;
//	pj = new int(10);
//	system("pause");
//	return 0;
//}


int main()
{

	int* pa;
	pa = new int[5];	//pa指向5个未初始化的int型数据对象的首地址
	//如果想要将pa在创建时就初始化好应改为如下代码
	pa = new int[5]{ 1,2,3,4};	//此时第一个int型的对象的值就为1，同理后面的对象依次是{}中给出的值
	//当{}中给初的数值的个数小于创建的对象个数时，会将其值默认初始化为0

	return 0;
}