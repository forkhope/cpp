// 几种初始化string对象的方式
// string s1;   默认构造函数,s1为空串
// string s2(s1); 将s2初始化为s1的一个副本
// string s3("value"); 将s3初始化为一个字符串字面值副本
// string s4(n, 'c'); 将s4初始化为字符'c'的n个副本
// 程序展示了string对象这四种构造方式，并进行输出，可以进行比较一下
#include<string>
#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

string s;  // 输出结果为NULL,也就是空串
int main()
{
	string s1("tianxiayouqingren");
	string s2(s1); // 输出结果和s1一样
	string s3(4, 'a');  // 输出4个a
	cout<<"If s is empty? "<<s.empty()<<endl; // 测试字符串是否为空
	cout<<s<<endl<<s1<<endl;;
	cout<<s2<<endl<<s3<<endl;
	cout<<s2[7]<<endl; //返回s2中位置为n的字符,位置从0开始计数
	// s2[n]表示取位置为n的字符,取该字符可以进行输出如上,也可以重新赋值
	for (string::size_type ix=0; ix != s2.size(); ++ix)
		s2[ix] = '*';  // 将位置为ix的字符重新赋值为字符＊
	cout<<s2<<endl;
	cout<<"The size of s1 is "<<s1.size()<<endl; //用size求字符串长度
	cout<<"s1 + s3 = "<<s1+s3<<endl; //两个字符串相加,生成新的字符串
	// 此外，还有一些函数，不一一举例，了解即可
	// 注意，不要把size()函数的返回值赋给int变量，其返回值是size_type型
	return 0;
}
