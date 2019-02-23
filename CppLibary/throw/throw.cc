//使用throw表达式抛出异常。throw表达式由关键字throw以及尾随的表达式组成,
//throw表达式的类型决定了所抛出异常的类型。
#include<iostream>
#include<stdexcept>
using std::runtime_error; 
using std::cout;
using std::endl;
using std::cin;

int main()
{
	int i;
	cin>>i;
	//runtime_error:运行时错误,仅在运行时才能检测到问题
	//该表达式的头文件为<stdexcept>,命名空间为std.
	if (i < 0 || i > 10)
		throw runtime_error("所输入的i必须大于0，小于10");
	cout<<i<<endl;
	return 0;
}
