#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//template<class ������ 1,class ������ 2,...>
//��������  ������(�βα�)
//{
//	������;
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
	cout << "������ͨ����" << endl;
}

template<class T>
void  myPrint(T x, T y)
{
	cout << "����ģ�庯��" << endl;
}


template<class T>
void  myPrint(T x, T y, T z)
{
	cout << "�������ص�ģ�庯��" << endl;
}

void test01()
{
	int a = 10;
	int b = 20;

	//���ȵ�����ͨ����
	myPrint(a, b);

	//ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b);

	//����ģ��Ҳ���Է�������
	myPrint(a, b, 100);

	//�������ģ��������õ�ƥ�䣬���ȵ��ú���ģ��
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}

//�ܽ᣺�����ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ�����
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}

//template< ģ������� >
//class ����
//{
//	��Ա��;
//};


//template< ģ������� >
//����  ����  < ģ��������� >::������(������)
//{
//	������;
//}

//��ģ���� <ģ�����ֵ��> ��������;

#include<iostream>
template<class T>
class Stack
{
public:
	Stack(int size= 10);

	//��������
	~Stack()
	{
		delete[]this->m_space;
	}
	int ma(int);
	bool push(const T& element);

	T pop();

	//�п�
	bool IsEmpty() const
	{
		return this->m_top == this->m_size;
	}

	//����
	bool IsFull() const
	{
		return this->m_top == 0;
	}
private:
	int m_size;		//Ԫ�ظ���
	int m_top;		//ջ��
	T* m_space;		//ջ
};

//���캯��
template<class T>
Stack<T>::Stack(int size)
{
	this->m_size = size;
	this->m_space = new T[size];
	this->m_top = size;
}

//��ջ
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

//��ջ
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