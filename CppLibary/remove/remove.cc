//使用remove算法来删除元素,它有一些要注意的问题,见下面的程序.
#include<iostream>
#include<list>
#include<iterator>   //ostream_iterator需要这个头文件
#include<algorithm>
using std::cout;
using std::endl;
using std::list;
using std::ostream_iterator;

int main()
{
	list<int> coll;

	//insert elements from 6 to 1 and 1 to 6
	for (int i = 1; i <= 6; ++i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	//print all elements of the collection
	//要输出容器元素可以采用copy算法和ostream_iterator,而不必再使用
	//for循环和cout语句.这不是必须的,只是程序这样写会显得简洁而已
	cout<<"删除元素之前，输出coll的所有元素如下:"<<endl;
	copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	//remove all elements with value 3
	//remove算法返回容器删除元素之后的新终点,我们可以利用该终点获得新区间,
	//缩减后的容器大小,或是获得被删除元素的个数.如下end保存了这个新终点
	list<int>::iterator end = remove (coll.begin(), coll.end(), 3);

	//print resulting elements of the collection
	//remove算法虽然会删除元素,但是它并不会改变容器的长度,coll.end()依然返回
	//coll原有末尾元素的下一个位置,但是删除元素,逻辑上容器长度要发生改变,因
	//此,输出时正确的结束位置为end所保存的新终点.注意,end不等于coll.end()
	cout<<"删除元素之后，使用end做终点输出元素如下:"<<endl;
	copy (coll.begin(), end, ostream_iterator<int>(cout, " "));
	cout<<endl<<"而使用coll.end()做终点输出元素如下:"<<endl;
	copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;

	//print number of resulting elements 
	//distance是针对迭代器而设计的辅助函数,其作用是返回两个迭代器之间的距离
	cout<<"number of removed elements: "<<distance(end, coll.end())<<endl;

	//remove "removed" elements
	//erase()可以删除"参数所指示区间"之内的全部元素,从而改变容器的长度
	coll.erase (end, coll.end());

	//print all elements of the modified collection
	cout<<"擦除新终点后面的元素之后,使用coll.end()做终点输出元素为:"<<endl;
	copy (coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
	cout<<endl;
	return 0;
}
