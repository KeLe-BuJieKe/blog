#include"Person.h"
//class ������
//{
//public:
//	//�������ݳ�Ա���߹��г�Ա�����Ķ��壻
//protected:
//	//�������ݳ�Ա���߱�����Ա�����Ķ��壻
//private:
//	//˽�����ݳ�Ա����˽�г�Ա�����Ķ��壻
//}


//��ʾ�˵��������Ա������
void Person::ShowPerson()
{
	cout << "������" << this->m_name << " �Ա� " << this->m_sex << "���䣺" << this->m_age << endl;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
	cout<<sizeof(Person);
	return 0;
}


class Clock
{
public:
	void SetTime(int h, int m, int s)
	{
		this->m_H = h,this->m_M = m,this->m_S = s;

		m_H = h, m_M = m, m_S = s;

		(*this).m_H = h, (*this).m_M = m, (*this).m_S = s;
	}
private:
	int m_H;	//Сʱ
	int m_M;	//��
	int m_S;	//��
};


class String
{
public:
    String(const char* str = nullptr); // ��ͨ���캯�� 
    String(const String& other); // �������캯�� 
    ~String(void); // �������� 
    String& operator = (const String & other); // ��ֵ���� 
private:
    char* m_data; // ���ڱ����ַ��� 
};
// String ����ͨ���캯��
String::String(const char* str)
{
    if (str == NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
}
// String ����������
String::~String(void)
{
    delete[] m_data;
}
// �������캯�� 
String::String(const String& other)
{
    // ������� other ��˽�г�Ա m_data 
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

// ��ֵ���� 
String& String::operator = (const String & other)
{
    // (1) ����Ը�ֵ 
    if (this == &other)     //ע�ⲻ�� д�� *this=other
    {
        return *this;
    }
    
    // (2) �ͷ�ԭ�е��ڴ���Դ 
    delete[] m_data;

    // ��3�������µ��ڴ���Դ������������ 
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);

    // ��4�����ر���������� 
    return *this;
}



class Complex
{
public:
    Complex(double real = 0.0, double image = 0.0)
    {
        this->real = real;
        this->image = image;
    }
    Complex operator +(Complex B);		//����� + ���س�Ա����
private:
    double real;	//����ʵ��
    double image;	//�����鲿
};

Complex Complex::operator+(Complex B)
{
    return Complex(this->real+B.real,this->image+B.image);
}


class Test
{
public:
    Test(int a, int b)
    {
        this->m_a = a;
        this->m_b = b;
    }
private:
    int m_a;
    int &m_b;
};

