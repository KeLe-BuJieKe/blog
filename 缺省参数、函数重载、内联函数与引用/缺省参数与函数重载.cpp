#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//void test()
//{
//
//}
//int main()
//{
//	test("Hello world","zhangsan","10");
//	system("pause");
//	return 0;
//}

//void Test(int x=10)
//{
//	std::cout << x << std::endl;
//}
//
//int main()
//{
//	Test();			//没有传参数时，使用参数默认值，则输出结果为10；
//	Test(100);		//当有传入参数时，使用给定的参数，则输出结果为100
//	return 0;
//}

//void TestFunc(int a, int b = 20, int c = 30)
//{
//    std::cout << "a = " << a<<" ";
//    std::cout << "b = " << b << " ";
//    std::cout << "c = " << c << std::endl << std::endl;
//}
//int main()
//{
//    //TestFunc();     //error  编译时会出错，因为a没有缺省值，所以必须传参。
//    TestFunc(1);
//    TestFunc(1,2);
//    TestFunc(1,2,3);
//    return 0;
//}

//int add(int x, int y)
//{
//	std::cout << "(int,int)\t";
//	return x + y;
//}
//
//double add(double x, double y)
//{
//	std::cout << "(double,double)\t";
//	return x + y;
//}
//
//int add(int x, double y)
//{
//	std::cout << "(int,double)\t";
//	return x + y;
//}
//
//double add(double x, int y)
//{
//	std::cout << "(double,int)\t";
//	return x + y;
//}
//int main()
//{
//	std::cout << add(9, 8) << std::endl;
//	std::cout << add(9.0, 8.0) << std::endl;
//	std::cout << add(9, 8.0) << std::endl;
//	std::cout << add(9.0, 8) << std::endl;
//	return 0;
//}

//void fun(int a,int b,int c=10)
//{
//
//}
//
//
//void fun(int a,int b)
//{
//
//}
//int main()
//{
//	fun(1, 2);
//	return 0;
//}


#include<iostream>

//inline double CirAree(double radius)
//{
//	return 3.14 * radius * radius;
//}
//
//int main()
//{
//	double r1(1.0);
//	double r2(2);
//	std::cout << CirAree(r1) << std::endl;
//	std::cout << CirAree(r1+r2) << std::endl;
//
//	int x;
//	int& rx = x;
//	return 0;
//}

#include<iostream>

int& max(int array[], int n)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (array[i] > array[t])
		{
			t = i;
		}
	}
	return array[t];
}
