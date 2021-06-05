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
//void Person::ShowPerson()
//{
//	cout << "������" << this->m_name << " �Ա� " << this->m_sex << "���䣺" << this->m_age << endl;
//}
//
//int main()
//{
//    int a, b;
//    std::cin >> a >> b;
//	cout<<sizeof(Person);
//	return 0;
//}


//class Clock
//{
//public:
//	void SetTime(int h, int m, int s)
//	{
//		this->m_H = h,this->m_M = m,this->m_S = s;
//
//		m_H = h, m_M = m, m_S = s;
//
//		(*this).m_H = h, (*this).m_M = m, (*this).m_S = s;
//	}
//
//private:
//	int m_H;	//Сʱ
//	int m_M;	//��
//	int m_S;	//��
//};
//

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


//class Test
//{
//public:
//    Test(int a, int b)
//    {
//        this->m_a = a;
//        this->m_b = b;
//    }
//private:
//    int m_a;
//    int &m_b;
//};
//

//class B;            //ǰ����������
//class A             //A��Ķ���
//{
//public:
//    void funA(B b); //��B�����bΪ�βεĳ�Ա����
//};
//
//class B             //B��Ķ���
//{
//public:
//    void funB(A a); //��A�����aΪ�βεĳ�Ա����
//};


#include<iostream>

class TrainTrip;        //ǰ����������
class Clock
{
    friend class TrainTrip;            //TrainTrip����ΪClock����Ԫ��
public:
    void ShowTime();            //��ʾʱ�亯��
    void SetTime(int h=0, int m=0, int s=0);      //����ȱʡֵ������ʱ�亯��

    Clock(int h = 0, int m = 0, int s = 0);       //����ȱʡֵ�Ĺ��캯��

private:
    int m_hour;         //Сʱ
    int m_minute;       //����
    int m_second;       //��
};

void Clock::ShowTime()
{
    std::cout << this->m_hour << "  :" << this->m_minute << "  :" << this->m_second << std::endl;
}

void Clock::SetTime(int h , int m, int s)
{
    this->m_hour = h;
    this->m_minute = m;
    this->m_second = s;
}

Clock::Clock(int h, int m, int s)
{
    this->m_hour = h;
    this->m_minute = m;
    this->m_second = s;
}

class TrainTrip
{
public:
    TrainTrip(char* No, Clock S, Clock E);          //���캯��
    Clock  TripTime();
private:
    char* m_TrainNo;         //����
    Clock m_StartTime;        //����ʱ��
    Clock m_EndTime;          //����ʱ��
};

TrainTrip::TrainTrip(char* No, Clock S, Clock E)
{
    this->m_TrainNo = No;
    this->m_StartTime = S;
    this->m_EndTime = E;
}

Clock TrainTrip::TripTime()
{
    int tmpH;
    int tmpM;
    int tmpS;
    int carry = 0;
    Clock tmpTime;
    if ((tmpS=this->m_EndTime.m_second - this->m_StartTime.m_second) > 0)
    {
        carry = 0;
    }
    else
    {
        tmpS += 60;
        carry = 1;
    }

    if ((tmpM = this->m_EndTime.m_minute - this->m_StartTime.m_minute-carry) > 0)
    {
        carry = 0;
    }
    else
    {
        tmpM += 60;
        carry = 1;
    }


    if ((tmpH = this->m_EndTime.m_hour - this->m_StartTime.m_hour - carry) > 0)
    {
        carry = 0;
    }
    else
    {
        tmpH += 24;
        
    }
    tmpTime.SetTime(tmpH, tmpM, tmpS);
    return tmpTime;

}

int main()
{
    Clock c1(8, 10, 10), c2(6, 1, 2);
    Clock c3;
    TrainTrip t1((char*)"G663",c1, c2);
    c3 = t1.TripTime();
    c3.ShowTime();
    return 0;
}