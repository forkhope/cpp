//调用remove成员函数删除元素.在使用C++标准库的时候,就算我们符合种种条件,得以
//使用某个算法,那也未必就一定是好.容器本身可能提供功能相似而性能更佳的成员函
//数.如果追求高效率,就应该优先选用成员函数.前提是我们确定某个容器存在效率上
//明显突出的成员函数.如要删除list的元素时,成员函数remove就比算法remove要好.
#include<iostream>
#include<list>
#include<algorithm>
#include<iterator> //ostream_iterator需要这个头文件
using std::cout;
using std::endl;
using std::list;
using std::ostream_iterator;  //这一句必不可少

int main()
{
	list<int> coll;

	//insert elements from 6 to 1 and 1 to 6
	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	cout<<"删除元素之前,输出coll的所有元素为:"<<endl;
	copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	//使用remove算法删除所有元素值为3的元素,this is a poor performance.
	//需要额外调用erase成员函数来改变容器的长度,从而让end()函数指向新终点
	coll.erase (remove(coll.begin(), coll.end(), 3), coll.end());

	//使用remove成员函数删除所有元素值为4的元素,this is a good performance
	//remove成员函数会真的移除"被移除的元素",进而改变容器的长度
	coll.remove (4); //接受一个参数,为所要删除的元素值

	cout<<"删除元素之后,输出coll的所有元素为:"<<endl;
	copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	return 0;
}
