//程序主要介绍枚举类型.枚举类型实际上就是一组整数常量集合,并为每一个整数常量
//定义了一个标识符.枚举的定义包括关键字enum,其后是一个可选的枚举类型名,和一
//个用花括号括起来、用逗号分开的枚举成员列表.默认地,第一个枚举成员赋值为0,后
//面的每个枚举成员赋的值比前面的大1.
//枚举成员是常量,每个enum都定义一种唯一的类型.和其他类型一样,可以定义和初始
//化enum所定义类型的对象,也可以以不同的方式使用这些对象.枚举类型对象的初始化
//或赋值,只能通过其枚举成员或同一枚举类型的其他对象来进行.
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	//以下weekday使用默认赋值,则sun=0,mon=1,tue=2,wed=3,the=4,fri=5,sat=6
	enum weekday {sun, mon, tue, wed, thu, fri, sat};
	weekday today = fri;      //使用枚举成员为枚举类型对象赋值
	weekday yesterday = thu;
	weekday tomorrow = sat;
	//weekday day = 3;//error:注意把3赋给weekday对象是非法的,即使wed的值为3

	cout<<"今天是星期"<<today<<", 昨天是星期"<<yesterday
		<<", 明天是星期"<<tomorrow<<endl;
	cout<<4+today<<endl; //枚举成员就是整数常量,当作整数常量来使用就好
	
	//枚举成员值可以相等.如下,枚举成员wo显式初始化为2.下一个枚举成员xia默认
	//初始化,即它的值比前一枚举成员的值大1,因此xia初始化为3.而you显式初始化
	//为3,则枚举成员xia和you的值相等,这是允许的.后面的tian,guang的则值为4,5
	enum word {wo = 2, xia, you = 3, tian, guang};
	cout<<"wo = "<<wo<<", xia = "<<xia<<", you = "<<you
		<<", tian = "<<tian<<", guang = "<<guang<<endl;
	return 0;
}
