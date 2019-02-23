//程序展示int向unsigned int的转换,以及把负值赋给unsigned int对象的处理方法,
//对于unsigned类型来说,负数总是超出其取值范围.但在C++中,把负值赋给unsigned
//int对象是完全合法的,其结果是该负数对该类型的取值个数求模后的值.所以,如果
//把－1赋给8位的unsigned char,那么结果是255,因为255是-1对256求模或的值(负数
//求模时,余数要求和除数同号),下面程序运算时,int型会自动转换为unsigned int型.
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	unsigned int a = 6;
	int b = -20;
	(a + b > 6) ? cout<<">6"<<endl : cout<<"<=6"<<endl;
	cout<<a + b<<endl; //32位机器,-14%2的32次方,余数要和除数同号,可得结果
	return 0;
}
