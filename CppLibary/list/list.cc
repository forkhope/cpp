//list是双向链表的模板类,list不提供随机存取,其头文件为<list>,
//命名空间为std,使用方法和vector和deque差不多.恩,大致如此
#include<iostream>
#include<list>
using std::cout;
using std::endl;
using std::list;
using std::iterator;

int main()
{
	list<char> collect; //list container for character elements

	//append elements from 'a' to 'z'
	for (char c = 'a'; c <= 'z'; ++c)
		collect.push_back(c);

	//use iterator to print all elements
	//container::iterator 定义一个"读／写"模式的迭代器
	list<char>::const_iterator iter; //定义一个"只读"的迭代器
	for (iter = collect.begin(); iter != collect.end(); ++iter)
		cout<<*iter<<" ";
	cout<<endl;

	//list模板类不支持随机存取,所以不能通过下标来存取list中的元素
	//除了使用iterator之外,要想输出list中的所有元素,可以采用下面的方法
	while (!collect.empty())
	{
		cout<<collect.front()<<' ';
		collect.pop_front(); //弹出当前的表头元素
	}
	cout<<endl;
	return 0;
}
