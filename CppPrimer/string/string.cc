// C++标准库定义了string类型,该类型支持长度可变的字符串
// 程序中展示了stirng的基本用法
#include<string>   // 该头文件包含string类型
#include<iostream>
using std::string;  // 使用string声明
using std::cin;
using std::cout;
using std::endl;

int main()
{
	// string类型的输入操作符：
	// 读取并忽略开头所有的空白字符（如空格，换行符，制表符）
	// 读取字符直至再次遇到空白字符，读取终止
	// 如果输入到程序的是"    Hello World!   "，则实际输出为"Hello"
	string s;
	while(cin>>s)
		cout<<s<<endl;
	return 0;
}
