//使用try块处理异常,try块以关键字try开始，后面是用花括号括起来的语句序列
//块,try块后面是一个或多个catch子句.每个catch子句包括三部分：关键字catch,
//圆括号内单个类型或者单个对象的声明——称为异常说明符，以及通常用花括号括
//起来的语句块.另外,每一个标准库异常类都定义类名为what的成员函数,返回字符串
#include<iostream>
#include<stdexcept>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main()
{
	int i;
	while(cin>>i)
	try
	{
		//下一句初始化runtime_error的string对象,定义runtime_error的what()
		//函数的返回值,这是必不可少的,否则下面的err.what()函数不正常工作
		if (i < 0 || i > 10)
			throw runtime_error("所输入的i必须大于0，小于10");
		cout<<i<<endl;
	}
	catch(runtime_error err)
	{
		//这里err.what()函数的返回值由上面的throw表达式所定义
		cout<<err.what()<<"\nTry Again? Enter y or n"<<endl;
		char c;
		cin>>c;
		if (cin && c == 'n')
			break;
	}
	return 0;
}
