//对Default Template Parameters(缺省模板参数)的使用。Template classes
//可以有缺省参数。如果没有给缺省参数赋值，则使用缺省参数，如下程序所示
#include<iostream>
#include<vector>
#include<string>    //该头文件保存string数据类型,该数据类型在标准库中
using std::string;  //这一句必不可少，否则找不到string类型
using std::vector;
using std::cout;
using std::endl;

//此处，C缺省为string型的容器,另外注意，在<string> >这里的
//两个">"之间必须有一个空格，否则">>"会被解读为移位运算符
template<class T, class C = vector<string> > 
class TheClass
{
public:
	T t;
	C c;
};

int main()
{
	TheClass<int> obj1;    //template第二个参数缺省为char型
	obj1.t = 8;
	obj1.c.push_back("Hello, I am lixianyi"); //为容器追加元素
	cout<<obj1.t<<", "<<obj1.c[0]<<endl;

	TheClass<int, string> obj2;//template的第二个参数被指定为string型
	obj2.t = 4;
	obj2.c = "This is a template program"; //为string型数据赋值
	cout<<obj2.t<<", "<<obj2.c<<endl;
	return 0;
}
