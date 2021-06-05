#include"Person.h"
//class 类名：
//{
//public:
//	//公有数据成员或者公有成员函数的定义；
//protected:
//	//保护数据成员或者保护成员函数的定义；
//private:
//	//私有数据成员或者私有成员函数的定义；
//}


//显示人的姓名、性别和年龄
//void Person::ShowPerson()
//{
//	cout << "姓名：" << this->m_name << " 性别： " << this->m_sex << "年龄：" << this->m_age << endl;
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
//	int m_H;	//小时
//	int m_M;	//分
//	int m_S;	//秒
//};
//

class String
{
public:
    String(const char* str = nullptr); // 普通构造函数 
    String(const String& other); // 拷贝构造函数 
    ~String(void); // 析构函数 
    String& operator = (const String & other); // 赋值函数 
private:
    char* m_data; // 用于保存字符串 
};
// String 的普通构造函数
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
// String 的析构函数
String::~String(void)
{
    delete[] m_data;
}
// 拷贝构造函数 
String::String(const String& other)
{
    // 允许操作 other 的私有成员 m_data 
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

// 赋值函数 
String& String::operator = (const String & other)
{
    // (1) 检查自赋值 
    if (this == &other)     //注意不能 写成 *this=other
    {
        return *this;
    }
    
    // (2) 释放原有的内存资源 
    delete[] m_data;

    // （3）分配新的内存资源，并复制内容 
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);

    // （4）返回本对象的引用 
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
    Complex operator +(Complex B);		//运算符 + 重载成员函数
private:
    double real;	//复数实部
    double image;	//复数虚部
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

//class B;            //前向引用声明
//class A             //A类的定义
//{
//public:
//    void funA(B b); //以B类对象b为形参的成员函数
//};
//
//class B             //B类的定义
//{
//public:
//    void funB(A a); //以A类对象a为形参的成员函数
//};


#include<iostream>

class TrainTrip;        //前向引用声明
class Clock
{
    friend class TrainTrip;            //TrainTrip声明为Clock的友元类
public:
    void ShowTime();            //显示时间函数
    void SetTime(int h=0, int m=0, int s=0);      //带有缺省值的设置时间函数

    Clock(int h = 0, int m = 0, int s = 0);       //带有缺省值的构造函数

private:
    int m_hour;         //小时
    int m_minute;       //分钟
    int m_second;       //秒
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
    TrainTrip(char* No, Clock S, Clock E);          //构造函数
    Clock  TripTime();
private:
    char* m_TrainNo;         //车次
    Clock m_StartTime;        //出发时间
    Clock m_EndTime;          //到达时间
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