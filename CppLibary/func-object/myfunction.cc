#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
using std::cout;
using std::endl;
#endif

//一个打印容器内所有元素的内联函数
template<class T>
inline void PrintElements (const T& coll, const char *optcstr = "")
{
	cout<<optcstr<<endl;

	typename T::const_iterator pos;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<" ";
	cout<<endl;
}

//实现transform()函数
template<class InputIterator, class OutputIterator, class Function>
OutputIterator transform (InputIterator first, InputIterator last,
		OutputIterator result, Function f)
{
	for (; first != last; ++first)
		*result++ = f(*first);
	return result;
}

//实现replace_if()函数,下面的Predicate是一个函数指针,其指向的函数返回bool值
template<class InputIterator, class Predicate, class T>
void replace_if (InputIterator first, InputIterator last,
		Predicate p, const T& newvalue)
{
	for (; first != last; ++first)
		if (p(*first))
			*first = newvalue;
}

//实现remove_if()函数,这里remove_if的意思是:符合条件就删除,保留不符合条件的
template<class InputIterator, class Predicate>
InputIterator remove_if (InputIterator first, InputIterator last,
		Predicate p)
{
	//该函数以result为界,将不符合"删除"条件,也就是要保留的元素移到result的
	//右边,符合"删除"条件的移到result的左边.函数最后返回result作为所给区间
	//的新终点.注意,这里的remove并不是真的删除了元素,它只是改变了元素的顺序
	InputIterator result = first;
	for (; first != last; ++first)
		if (!p(*first))
			*result++ = *first;
	return result;
}

//This is a base class for standard unary function objects
//这是一个所有标准一元函数对象的基类.一元函数对象就是接受一个参数的函数对象
template<class Arg, class Result>
struct unary_function
{
	typedef Arg argument_type;
	typedef Result result_type;
};

//This is a base class for standard binary function objects.
//这是一个所有标准二元函数对象的基类.二元函数对象就是接受两个参数的函数对象
template<class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Result result_type;
};

//在C++中,struct和class有大致相同的含义,都可以用来定义一个类,只是在struct
//中定义的成员默认为public,在class中定义的成员默认为private
template<class T>
struct multiplies : binary_function<T, T, T>
{
	T operator() (const T& x, const T& y) const
	{
		return (x * y);
	}
};

//定义equal_to结构体,其对象为函数对象
template<class T>
struct equal_to : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const
	{
		return (x == y);
	}
};

//定义less结构体,其对象为函数对象
template<class T>
struct less : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const
	{
		return (x < y);
	}
};

//定义binder2nd类,其对象为函数对象,该类用来作为bind2nd()函数的返回值
//Operation是一个二元函数对象,继承自binary_function类
template<class Operation>
class binder2nd 
	: public unary_function<typename Operation::first_argument_type, 
	typename Operation::result_type>
{
protected:
	Operation op;
	typename Operation::second_argument_type value;
public:
	binder2nd (const Operation& x, const typename
			Operation::second_argument_type& y):op(x), value(y) {}
	typename Operation::result_type operator() 
		(const typename Operation::first_argument_type& x) const
	{
		return op(x, value);
	}
};


//定义bind2nd()函数
template<class Operation, class T>
binder2nd<Operation> bind2nd (const Operation& op, const T& x)
{
	return binder2nd<Operation>(op, typename 
			Operation::second_argument_type(x));
}
