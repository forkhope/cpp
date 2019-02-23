//更易型算法(指那些会移除remove、重排resort、修改modify元素的算法)用于关联式
//容器上会出问题.那么如何从关联容器中删除元素?很简单:调用它们的成员函数,如用
//erase()来移除元素.注意erase()是成员函数,而remove()是算法,定义于algorithm中
#include<iostream>
#include<set>
#include<iterator>  //ostream_iterator需要这个头文件
#include<algorithm>
using std::cout;
using std::endl;
using std::set;
using std::ostream_iterator; //这一句必不可少

int main()
{
	set<int> coll;

	//insert elements fromt 1 to 9
	for (int i = 1; i <= 9; ++i)
		coll.insert(i); //不需要指定输入位置,关联式容器的元素位置会自动排列

	cout<<"删除元素之前,coll的所有元素为:"<<endl;
	copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	//注意,容器类型提供了多个不同的erase()成员函数.其中一种形式是以"待删除
	//的元素值"为唯一参数,它会返回被删除的元素个数.
	int num = coll.erase (3); //3为要删除的元素值

	cout<<"number of removed elements: "<<num<<endl;
	cout<<"删除元素之后,coll的所有元素为:"<<endl;
	copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	return 0;
}
