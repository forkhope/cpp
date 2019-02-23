//结构(struct)和联合(union)是两种构造类型数据,它们都由成员组成.成员可以具有
//不同的数据类型.在结构中,各成员都占有自己的内存空间,它们是同时存在的.一个
//结构变量的总长度(用sizeof操作符计算出的长度)等于所有成员长度只和.在联合中,
//所有成员不能同时占用它的内存空间,它们不能同时存在.联合变量的长度等于最长的
//成员的长度.然而,使用sizeof操作符计算出来的结果并不一定和上面的结果相符.这
//取决于编译器的设定.编译器一般会对结构和联合的变量的存储空间进行字节对齐.
#include<iostream>
using std::cout;
using std::endl;
int main()
{
	cout<<"这里的输出使用编译器默认的对齐方式"<<endl;
	//union的长度为最长的成员长度,所以sizeof(u)的值是4
	union
	{
		int i;
		char a;
	}u;
	//下面的结构体中,int型在前面,占4个字节;char型和short型在后面,占3个字节,
	//向int对齐之后,占4个字节,所以sizeof(s)的值是8.
	struct 
	{
		int i;
		char a;
		short c;
	}s;
	cout<<"union u的长度: "<<sizeof(u)<<endl;
	cout<<"struct s的长度: "<<sizeof(s)<<endl;

	//由上可知,sizeof(o)的长度等于数组a的长度11,对齐之后sizeof(o)的值是12
	union other
	{
		int i;
		char a[11];
	};
	other o;
	cout<<"union other的长度: "<<sizeof(o)<<endl;

	//改变变量的声明顺序,使用sizeof操作符求得的结果也不一样.char型在前,占1个
	//字节(没有对齐之前),int型在中间,占4个字节,short型在后面,占2个字节,对齐
	//之后,char型和short型都要占4个字节,所以sizeof(t)的值是12.
	//结构体t和结构体s的区别在于:在s中,char型和short的存储地址是相连的,这两
	//个的内存大小加起来小于4,所以可以放在一起进行对齐;而t中,char型和short型
	//是分开,char型后面是int型,不能放在一起进行对齐,否则会超出默认的对齐大小
	//因此t中的char型对齐之后,占4个字节,short型也占4个字节,所以sizeof(t)=12
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
