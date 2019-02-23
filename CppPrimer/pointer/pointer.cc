//介绍指针加减运算的一个小问题.指针类型的不同,相同的语句得到的结果也不同.
//下面的程序可以使用多种不同的数据类型来进行比较,我懒,就省略了这个步骤.
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	int i = 1;
	cout<<"i的地址为:"<<&i<<endl;

    //p的值将是&i的值加上8个字节之后的值,正好等于2 * sizeof(int)
	int *p = &i + 2;  //&i + 2的结果并不是&i的值加2,而是加2 * sizeof(int) 
	cout<<"p = &i + 2的值为: "<<p<<endl;

	//下面,p - &i的值是2,而不是8,说明指针运算所得的结果会除以sizeof(int).
	//但我们还是要知道,在p和&i之间隔了8个字节,而不是2个字节.
	//p和&i相减所得的2表示的是,这两个地址之间隔了2个int型的数据.
	cout<<"两个int型指针相减:p - &i =  "<<p - &i<<endl;

	//将这两个指针转换为char型指针后,相减的结果会除以sizeof(char),等于8.
	cout<<"将这两个指针转换为char型指针,相减的结果为: "<<endl;
	cout<<"(char*)p - (char*)&i = "<<(char*)p - (char*)&i<<endl;
	return 0;
}
