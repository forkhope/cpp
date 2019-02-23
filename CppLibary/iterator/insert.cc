//insert iterators(安插型迭代器),可称为inserters.inserters可以使算法以安插
//(insert)方式而非覆写(overwrite)方式运作.C++标准程序库预定义了3种inserters
#include<iostream>
#include<list>
#include<vector>
#include<deque>
#include<set>
#include<algorithm>
using std::cout;
using std::endl;
using std::list;
using std::deque;
using std::set;
using std::vector;

int main()
{
	list<int> coll1;

	//insert elements from 1 to 9 into the first collection
	int i;
	cout<<"输出coll1的所有元素如下:"<<endl;
	for (i = 1; i <= 9; ++i)
	{
		coll1.push_back(i);
		cout<<i<<' ';
	}
	cout<<endl;

	//copy the elements of coll1 into coll2 by appending them
	//back_inserter(安插于容器最尾端),该迭代器的内部调用push_back(),
	//向容器尾端插入元素.当然,只有在提供有push_back()成员函数的容器中,
	//才能使用back_inserter.这样的容器有三:vector, deque, list.
	vector<int> coll2;
	copy (coll1.begin(), coll1.end(),   //source
			back_inserter(coll2));      //destination
	cout<<"输出coll2的所有元素如下:"<<endl;
	for (i = 0; i != coll2.size(); ++i)
		cout<<coll2[i]<<' ';
	cout<<endl;

	//copy the elements of coll1 into coll3 by inserting them
	//at the front--reverses the order of the elements
	//front_inserter(安插于容器最前端),将元素安插于容器最前端,该迭代器
	//只能用于提供有push_front()成员函数的容器,这样的容器有deque和list
	deque<int> coll3;
	copy (coll1.begin(), coll1.end(),   //source
			front_inserter(coll3));     //destination
	cout<<"输出coll3的所有元素如下:"<<endl;
	deque<int>::iterator iter;
	for (iter = coll3.begin(); iter != coll3.end(); ++iter)
		cout<<*iter<<' ';
	cout<<endl;

	//copy elements of coll1 into coll4--only inserter that
	//works for associative collections(关联式容器)
	//inserter(一般性安插器),它的作用是将元素插入表达式所接受第二个参数
	//所指位置的前方.inserter内部调用成员函数insert(),并将新值和新位置作
	//为参数.所有STL容器都提供有insert()成员函数,因此,inserter具有一般性
	//其算式为inserter(container, pos),使用insert()在pos位置上安插元素.
	set<int> coll4;   
	copy (coll1.begin(), coll1.end(),        //source
			inserter(coll4, coll4.begin())); //destination
	cout<<"输出coll4的所有元素如下:"<<endl;
	set<int>::iterator pos;
	for (pos = coll4.begin(); pos != coll4.end(); ++pos)
		cout<<*pos<<' ';
	cout<<endl;
	return 0;
}
