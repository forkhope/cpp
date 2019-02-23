//使用自定义的泛型函数.STL乃是一个可扩展的框架.这意味你可以撰写自己的函数和
//算法,处理群集内的元素.当然,这些操作函数本身也可以是泛型的(generic).如下的
//PrintElements就是一个泛型的函数,用于输出给定容器的所有元素值和提示字符串.
#include<iostream>
#include<vector>
#include<set>
using std::endl;
using std::cout;
using std::vector;
using std::set;

//PrintElements输出所给容器的所有元素值,它会先输出一个C风格的提示字符串
template<class T>
inline void PrintElements(const T& coll, const char *optcstr = "")
{
	//下面pos被声明为"传入之容器类型"内的迭代器类型,关键词typename在此不可
	//或缺,用以表明const_iterator是类型T所定义的一个类型,而不是类型为T的值.
	typename T::const_iterator pos;
	cout<<optcstr<<endl;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<' ';
	cout<<endl;
}

int main()
{
	vector<int> coll;
	set<int> coll2;

	int i = 0;
	while (++i != 7)
	{
		coll.push_back(i);
		coll2.insert(i + 7);
	}

	PrintElements(coll, "输出vector容器的所有元素如下:");
	PrintElements(coll2, "输出set容器的所有元素如下:");
	return 0;
}
