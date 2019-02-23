// 展示getline的用法
// getline接受两个参数：一个输入流对象和一个string对象
// getline不忽略空格、制表符，但是忽略换行符
#include<string>
#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string line;
	while (getline(cin,line))
		cout<<line<<endl;
	return 0;
}
