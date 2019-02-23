//使用C++标准程序库预先定义的函数对象,并通过一些特殊的函数配接器(function 
//adaptors),将预先定义的函数对象和其它数值组合在一起,或使用特殊状况.如下:
#include<iostream>
#include<set>
#include<deque>
#include<algorithm>
using namespace std;

//一个打印容器内所有元素的内联函数
template<class T>
inline void PrintElements(const T& coll, const char *optcstr = "")
{
	cout<<optcstr<<endl;

	typename T::const_iterator pos;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<" ";
	cout<<endl;
}

int main()
{
	//关联容器的缺省排序准则是operator<,该准则使用函数对象less<>实现;下面的
	//greater<>函数对象让关联容器的排序准则变为operator>,也就是由大到小排列
	set<int, greater<int> > coll;
	deque<int> coll2;

	//insert elements from 1 to 9
	for (int i = 1; i != 10; ++i)
		coll.insert(i);
	PrintElements (coll, "初始化后,coll的所有元素值为: ");

	//transform all elements into coll2 by multiplying 10
	//bind2nd()就是一个函数配接器,在进行multiples<int>运算时,以源群集的元素
	//作为第一参数,10作为第二参数.看func-object4.cc能更好地理解该函数的原理
	transform (coll.begin(), coll.end(), back_inserter(coll2),
			bind2nd (multiplies<int>(), 10));
	PrintElements(coll2, "转换后,coll2的所有元素值为: ");

	//replace value equal to 70 with 42
	replace_if (coll2.begin(), coll2.end(), 
			bind2nd (equal_to<int>(), 70), 42);
	PrintElements(coll2, "替换后,coll2的所有元素为: ");

	//remove all elements with values less than 50
	coll2.erase (remove_if (coll2.begin(), coll2.end(), 
				bind2nd (less<int>(), 50)), coll2.end());
	PrintElements(coll2, "删除后,coll2的所有元素为: ");
	return 0;
}
