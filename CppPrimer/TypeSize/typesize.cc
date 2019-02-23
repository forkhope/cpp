//介绍C++基本内置类型及其对应的最小存储空间. 如此而已
//C++内置类型与其在计算机上的存储器中的表示方式紧密相关.计算机以位序列存储
//数据,每一位存储0或1.在位这一级上,存储器是没有结构的.让存储具有结构的最基
//本方法是用块处理存储.大部分计算机都使用特定位数的块来处理存储,块的位数一
//般是2的幂.一个8位的块称为一个字节.大多数计算机将存储器中的每一个字节和一
//个称为地址的数关联起来.由此我们知道两个地址之间隔有8个位,则在32位的机器上
//int数组的两个相邻元素之间隔有4*8个位(因为32位机器上,int一般占4个字节).
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//C++内置类型及其对应的最小存储空间为,char:8 bits; wchar_t: 16 bits
	//short: 16 bits; int: 16 bits; long: 32 bits; float: 6位有效数字;
	//double: 10位有效数字; long double: 10位有效数字.
	cout<<"以下的输出以字节为单位:"<<endl;
	cout<<"size of bool: "<<sizeof(bool)<<endl; 
	cout<<"size of char: "<<sizeof(char)<<endl;
	cout<<"size of wchar_t: "<<sizeof(wchar_t)<<endl;
	cout<<"size of short: "<<sizeof(short)<<endl;
	cout<<"size of int: "<<sizeof(int)<<endl;
    cout<<"size of unsigned int: "<<sizeof(unsigned int)<<endl;
	cout<<"size of long: "<<sizeof(long)<<endl;
	cout<<"size of float: "<<sizeof(float)<<endl;
	cout<<"size of double: "<<sizeof(double)<<endl;
	cout<<"size of long double: "<<sizeof(long double)<<endl;

	//展示wchar_t的使用,wchar_t是宽字符型,用于扩展字符集,比如汉字.
	//char a = '天'; //这一句编译器会给出编译警告,提示会出现溢出
	wchar_t b = L'天';//为了让编译器识别多字符集(Unicode)字符串,要加一个'L'
	return 0;
}
