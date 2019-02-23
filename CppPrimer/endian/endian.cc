//写一个函数判断系统是大端还是小端.若处理器是Big_endian的,则返回0;若是
//Little_endian的,则返回1.
//大端模式:在这种模式中,字数据的高字节存储在低地址中,而字数据的低字节则存放
//在高地址中; 小端模式:与大端模式相反,在小端存储格式中,低地址中存放的是字数
//据的低字节,高地址存放的是字数据的高字节.
#include<iostream>
using std::cout;
using std::endl;

//方法1:
void CheckEndian()
{
	//联合union的存放顺序是所有成员都从低地址开始存放
	union
	{
		int i;
		char a;
	}u;
	u.i = 1;
	//若处理器是小端模式,则1==0x00000001在内存中的存放次序为:第1个字节是0x01
	//第2、3、4个字节都是0x00,又因为union的存放顺序是所有成员都从低地址开始
	//存放,而char型只取一个字节,所以此时u.a==0x01==1,下面的返回值是1.若处理
	//器是大端模式,则类似地,第1个字节是最高位的0x00,此时u.a==0x00,返回值为0
	(u.a == 1) ? cout<<"该系统是小端模式"<<endl
		: cout<<"该系统是大端模式"<<endl;
}

//方法2:
void CheckEndian2()
{
	int i = 1;
	//看下面的语句,&i是取i的地址.那么对跨越多字节的对象,一般它所占的字节都是
	//连续的,它的地址等于它所占字节的最低地址.若处理器是小端模式,则int型的i
	//所占字节的最低地址中存放0x01,将该地址(也就是指针)用char*转换为char型指
	//针,再用*提取该指针指向的值,则该值是1,条件判断式为真.若处理器是大端模
	//式,则i所占字节的最低地址中存放0x00,最终的条件判断式为假.可知输出结果.
	(*(char*)&i == 1) ? cout<<"该系统是小端模式"<<endl
		: cout<<"该系统是大端模式"<<endl;
}

//方法3:
void CheckEndian3()
{
	int i = 1;
	//方法3和方法2差不多,将int型的i转换为char型,会发生截断,截掉高字节的部分
	//所以i就等于它原来所占4个字节中第一个字节的值,是1则是小端,是0则是大端.
	i = (char)i;
	(i == 1) ? cout<<"该系统是小端模式"<<endl
		: cout<<"该系统是大端模式"<<endl;
}

int main()
{
	//CheckEndian()函数的返回值为真,则是小端模式,为假,则是大端模式
	CheckEndian();
	CheckEndian2();
	CheckEndian3();
	return 0;
}
