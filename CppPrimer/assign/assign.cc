//关于C++几个你可能没注意到的小知识.包括:C++内置类型的两种赋值方式;数组首
//地址的地址加1的意义;C++中,字符串字面值的数据类型,大致如此.
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	//C++支持两种初始化变量的形式：复制初始化(copy-initialization)
	//和直接初始化(direct-initialization).复制初始化使用等号(=),直接
	//初始化则是把初始化式放在括号中.另外,在C++中,"初始化不是赋值"
	int i(9);   //i将等于9,建议采用复制初始化方式进行初始化
	int j = 8;  //j将等于8
	cout<<"i = "<<i<<endl;
	cout<<"j = "<<j<<endl;

	//关于数组首地址的地址加1的意义
	cout<<"-----------------------------"<<endl;
	int a[5] = {1, 2, 3, 4, 5};
	int *p = (int*)(&a + 1); //p = &a + 1指向数组末尾元素的下一个位置
	cout<<"数组长度为: "<<p-a<<endl;//由p的意义,可知p-a等于5,正好是数组长度
	cout<<"*(p-2) = "<<*(p-2)<<endl;//此时p - 2指向数组倒数第二个元素,为4

	//C++中,用char*指针指向字符串字面值时,编译器会给出警告,但是能通过编译,
	//也能运行.所以最好是用const char*指针来指向字符串字面值,这样就没问题了
	cout<<"-----------------------------"<<endl;
	//char *cp = "tian xia you qing ren";  //这一句会给出编译警告
	const char *cp = "tian xia you qing ren";
	cout<<cp<<endl;
	return 0;
}
