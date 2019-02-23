//该程序读取未知数目的输入.输入流是有状态的.当输入数据为operator>>右操作数
//类型时,输入有效,否则即是输入无效.例如operator>>的右操作数为int,输入为char
//则流的状态为无效,如下程序所示.
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int value;
	int sum = 0;

	//当我们使用istream对象作为条件,结果是测试流的状态.如果流是有效的(也
	//就是说,如果读入下一个输入是可能的)那么测试成功.遇到文件结束符(EOF)
	//或遇到无效输入时,如读取一个不是整数的值,则istream对象是无效的.处于
	//无效状态的istream对象将导致条件失败.如下程序可输入一个字母结束输入.
	while (cin>>value)
		sum += value;

	cout<<"输入的数字总和为: "<<sum<<endl;
	return 0;
}
