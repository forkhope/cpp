//在以函数为参数的算法中,算法以数种态度来面对这些辅助函数:有的视之为可有可
//无,有的视之为必要.你可以利用它们来指定搜寻准则、排序准则或定义某种操作,
//以便将某个容器内的元素转换至另一个容器.如下的transform()算法.
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using std::endl;
using std::cout;
using std::set;
using std::vector;

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
	transform (coll.begin(), coll.end(), back_inserter(coll2), square);
	PrintElements(coll2, "Squared: ");
	return 0;
}
