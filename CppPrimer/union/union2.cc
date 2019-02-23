#include<iostream>
#pragma pack(1)     //该预处理指令指定按1字节对齐
using std::cout;
using std::endl;
int main()
{
	cout<<"这里的输出使用按1字节对齐方式"<<endl;
	//易知,sizeof(u)的值是4
	union
	{
		int i;
		char a;
	}u;
	//int型的4个字节,char型的1个字节,short型的2个字节,可知sizeof(s)的值是7
	struct 
	{
		int i;
		char a;
		short c;
	}s;
	cout<<"union u的长度: "<<sizeof(u)<<endl;
	cout<<"struct s的长度: "<<sizeof(s)<<endl;

	//使用1字节对齐之后,sizeof(o)的长度就是数组a的长度,值为11
	union other
	{
		int i;
		char a[11];
	};
	other o;
	cout<<"union other的长度: "<<sizeof(o)<<endl;

	//使用1字节对齐,也就是没有进行字节扩展,所以结构体t和结构体s的长度相等
	//sizeof(t) == sizeof(char) + sizeof(int) + sizeof(short) == 7
	struct two
	{
		char a;
		int i;
		short c;
	};
	two t;
	cout<<"struct two的长度: "<<sizeof(t)<<endl;
	return 0;
}
