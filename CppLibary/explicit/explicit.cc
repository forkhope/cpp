//该程序主要展示了C++的单参数构造函数带来的隐式类型转换是怎么进行的
//并介绍了explicit关键字的作用,该关键字能抑制上述隐式类型转换的进行
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Size
{
public: 
	int size;
public:
	//C++语言定义了内置类型之间的几个自动转换.也可以定义如何将其它类型的
	//对象隐式转换为我们的类类型,或将我们的类类型的对象隐式转换为其它类型.
	//单参数构造函数定义了从形参类型到该类类型的一个隐式转换,也就是说可以
	//用形参类型来构造该类的一个对象,下面的代码就展示这种情况的应用
	Size(const int& data)
	{
		size = data;
	}
};


//如果要抑制由单参数构造函数定义的隐式转换,我们可以将构造函数
//声明为explicit,如下所示:
class OtherSize
{
public:
	int size;
	explicit OtherSize(const int& data)
	{
		size = data;
	}
};

int main()
{
	Size object(5);
	cout<<object.size<<endl;
	object = 10;  //将形参类型隐式的转换为类类型
	cout<<object.size<<endl;

	OtherSize OtherObject(8);
	cout<<OtherObject.size<<endl;
	//OtherObject = 9; //注意,这里编译会出错,现在已经不能进行隐式转换
	return 0;
}
