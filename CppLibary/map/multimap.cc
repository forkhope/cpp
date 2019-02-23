//map和set一样,也属于关联式容器,其元素是成对的键值/实值(key/value)
//其元素实际上pair类型,map的用法和set差不多,这里不再多说.同样,map不允许
//重复元素,multimap允许重复元素.这是一个multimap的示例程序
#include<iostream>
#include<map>    //map容器和multimap容器的头文件都是<map>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::make_pair;

int main()
{
	typedef std::multimap<int, string> IntStringMMap;

	IntStringMMap coll;

	//insert some elements,使用make_pair()来生成一对pair值
	coll.insert(make_pair(5, "tagged"));
	coll.insert(make_pair(2, "a"));
	coll.insert(make_pair(1, "this"));
	coll.insert(make_pair(4, "of"));
	coll.insert(make_pair(6, "strings"));
	coll.insert(make_pair(1, "is"));
	coll.insert(make_pair(3, "multimap"));

	IntStringMMap::const_iterator iter;  //定义一个只读迭代器
	//由于map迭代器所指的是"键值/实值"对组(key/value pair),因此我们不能
	//直接打印它们,而是必须取出pair的成员,也就是first和second,如下所示:
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		cout<<iter->second<<' ';
	cout<<endl;
	return 0;
}
