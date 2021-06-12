#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//template<class 类型名 1,class 类型名 2,...>
//返回类型  函数名(形参表)
//{
//	函数体;
//}


template<class T>
void Swap(T &val1, T &val2)
{
	T temp = val1;
	val1 = val2;
	val2 = temp;
}



template<class T,int size>
T sum(T a)
{

}

//int main()
//{
//	sum<int,100>(100);
//	return 0;
//}
//


void  myPrint(int x, int y)
{
	cout << "调用普通函数" << endl;
}

template<class T>
void  myPrint(T x, T y)
{
	cout << "调用模板函数" << endl;
}


template<class T>
void  myPrint(T x, T y, T z)
{
	cout << "调用重载的模板函数" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;

	//优先调用普通函数
	myPrint(a, b);

	//通过空模板参数列表，强制调用函数模板
	myPrint<>(a, b);

	//函数模板也可以发生重载
	myPrint(a, b, 100);

	//如果函数模板产生更好的匹配，优先调用函数模板
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

//总结：既让提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//template< 模板参数表 >
//class 类名
//{
//	成员名;
//};


//template< 模板参数表 >
//类型  类名  < 模板参数名表 >::函数名(参数表)
//{
//	函数体;
//}

//类模板名 <模板参数值表> 对象名称;

#include<iostream>
template<class T>
class Stack
{
public:
	Stack(int size= 10);

	//析构函数
	~Stack()
	{
		delete[]this->m_space;
	}
	int ma(int);
	bool push(const T& element);

	T pop();

	//判空
	bool IsEmpty() const
	{
		return this->m_top == this->m_size;
	}

	//判满
	bool IsFull() const
	{
		return this->m_top == 0;
	}
private:
	int m_size;		//元素个数
	int m_top;		//栈顶
	T* m_space;		//栈
};

//构造函数
template<class T>
Stack<T>::Stack(int size)
{
	this->m_size = size;
	this->m_space = new T[size];
	this->m_top = size;
}

//入栈
template<class T>
bool Stack<T>::push(const T& element)
{
	if (!IsFull())
	{
		this->m_space[--this->m_top] = element;
		return true;
	}
	else
	{
		return false;
	}
}

//出栈
template<class T>
T Stack<T>::pop()
{
	return this->m_space[this->m_top++];
}


int main()
{
	Stack<char>s1(4);
	s1.push('x');
	s1.push('y');
	s1.push('z');
	s1.push('u');
	while (!s1.IsEmpty())
	{
		std::cout << s1.pop() << endl;
	}
	return 0;
}