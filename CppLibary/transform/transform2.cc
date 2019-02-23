//使用自己实现的transform()算法,从而了解该算法的函数原型、实现过程.
#include<iostream>
#include<set>
#include<vector>
using std::endl;
using std::cout;
using std::set;
using std::vector;

//Function在这里是函数指针类型,具体到下面程序,就是int (*)(const int&)类型
//也可以是int (const int&)类型,前者是直接声明,后者是自动转换.
template<class InputIterator, class OutputIterator, class Function>
OutputIterator transform(InputIterator first, InputIterator last,
		OutputIterator result, Function f)
{
	while (first != last)
		*result++ = f(*first++);
	//The return value is an iterator pointing to the element that
	//follows the last element written in the result sequence.
	return result;
}

template<class T>
inline void PrintElements(const T& coll, const char *optcstr = "")
{
	cout<<optcstr<<endl;
	typename T::const_iterator pos;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<' ';
	cout<<endl;
}

int square(const int& value)
{
	return value * value;
}

int main()
{
	set<int> coll;
	vector<int> coll2;

	//insert elements from 1 to 9 into coll
	for (int i = 1; i != 10; ++i)
		coll.insert(i);
	PrintElements(coll, "Initialized: ");

	//transform each elements from coll to coll2,square transformed values
	//back_inserter()的返回值是一个back_insert_iterator<T>类型的迭代器
	transform (coll.begin(), coll.end(), back_inserter(coll2), square);
	PrintElements(coll2, "Squared: ");
	return 0;
}
