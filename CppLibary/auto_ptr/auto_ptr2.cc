//这个例子展示了const auto_ptr的特性
#include<iostream>
#include<memory>
using std::cout;
using std::endl;
using std::auto_ptr;
using std::ostream;

template<class T>
ostream& operator<< (ostream& strm, const auto_ptr<T>& p)
{
	//does p own an object ?
	if (p.get() == NULL)
		strm<<"NULL";   //NO: print NULL
	else
		strm<<*p;      //YES: print the object
	return strm;
}

int main()
{
	const auto_ptr<int> p(new int(42));
	const auto_ptr<int> q(new int(0));
	const auto_ptr<int> r;

	cout<<"after initialization:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;
	cout<<"r: "<<r<<endl;

	*q = *p;
	//*r = *p; //ERROR: undefined behavior
	*p = -77;
	cout<<"after assigning values:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;
	cout<<"r: "<<r<<endl;

	//q = p; //ERROR at compile time,q和p被定义为常量指针,不能改变
	//r = p; //ERROR at compile time,但是它们指向的对象值可以改变
	return 0;
}
