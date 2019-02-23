//auto_ptr是一种智能型指针，帮助程序员防止"被异常抛出时发生资源泄露"
//auto_ptr是"它所指向的对象"的拥有者，所以，当身为对象拥有者的auto_ptr
//被摧毁时，该对象也将遭到摧毁。auto_ptr要求一个对象只能有一个拥有者
//auto_ptr不再需要delete,内存的释放工作由auto_ptr自己完成,不需要手动释放
#include<iostream>
#include<memory>     //auto_ptr的头文件 
using std::cout;
using std::endl;
using std::auto_ptr;
using std::ostream;

//define output operator for auto_ptr,print object value or NULL 
//下面的重载函数的第二个参数是一个const引用,所以没有发生拥有权的转移
template<class T>
ostream& operator<< (ostream& strm, const auto_ptr<T>& p)
{
	//does p own an object ?
 	if (p.get() == NULL)
		strm<<"NULL";     //NO: print NULL
	else
		strm<<*p;        //YES: print the object
	return strm;
}

int main()
{
	auto_ptr<int> p(new int(42));
	auto_ptr<int> q;

	cout<<"after initialization:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;

	//auto_ptr的赋值工作会将拥有权从右向左转移，左操作数拥有那个new出来
	//的对象，而右操作数不再拥有那个对象。这样，对象就只会被释放一次，
	//在左操作数被销毁的时候。如下所示，赋值并输出以后，我们可以看到q拥有
	//int(42)对象，而p的值为NULL,对象的拥有权被改变了
	q = p;
	cout<<"after assigning auto pointers:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;

	*q += 13; //change value of the object q owns
	p = q;    //再次改变对象的拥有权
	cout<<"after change and reassignment:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;

	//在使用auto_ptr时，有了很重要的地方要注意，那就是不能以一般指针
	//的赋值手法来初始化一个auto_ptr。下面的写法是错误，一定要注意！
	//p = new int(42); //注意，这种写法是错误的，auto_ptr不能这样赋值！

	//在新的C++标准中，return 0是默认的，不写也可以
}
