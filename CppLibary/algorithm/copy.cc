//有数个算法需要同时处理多个区间.通常我们必须设定第一个区间的起点和终点,
//至于其它区间,只需设定起点即可,终点通常可由第一区间的元素数量推导出来,
//算法会操作"第一个区间长度"个元素.因此,如果某个算法用来处理多个区间,那么
//当我们调用它时,必须确保第二(以及其它)区间所拥有的元素个数,至少和第一区间
//内的元素个数相同.特别是,执行复制动作时,务必确保目标区间够大.下面的程序
//展示了如何修改目标区间,从而使它有足够的空间.注意,下面两个方法只使用于
//序列式容器,不能用于关联式容器,因为关联式容器不可能被当作覆写型算法的目标
#include<iostream>  //I/O输入输出流
#include<list>      //list容器的头文件
#include<vector>    //vector容器的头文件
#include<deque>     //deque容器的头文件
#include<algorithm> //容器算法的头文件
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::deque;

int main()
{
	list<int> coll1;
	vector<int> coll2;

	//insert elements from 1 to 9
	cout<<"输出coll1的所有元素如下:"<<endl;
	int i;
	for (i = 1; i <= 9; ++i)
	{
		coll1.push_back(i);
		cout<<i<<' ';     //插入的元素值和i是一样,只要把i输出来即可
	}
	cout<<endl;

	//resize destination to have enough room for 
	//the overwriting algorithm
	//resize()的作用是改变容器的元素的个数.
	coll2.resize(coll1.size());
	cout<<"resize之后,输出coll2的所有元素如下,"<<endl;
	cout<<"这是由default构造函数初始化并赋予的初值:"<<endl;
	for (i = 0; i < coll2.size(); ++i)
		cout<<coll2[i]<<' ';
	cout<<endl;

	//copy elements from first into second collection,
	//overwrites existing elements in destination
	copy(coll1.begin(), coll1.end(),  //source
			coll2.begin());           //destination
	cout<<"copy之后,输出coll2的所有元素如下:"<<endl;
	for (i = 0; i != coll2.size(); ++i)
		cout<<coll2[i]<<' ';
	cout<<endl;

	//create third collection with enough room 
	//initial size is passed as parameter
	//在创建的时候指明容器的元素个数,这种方法和resize都会产出新元素并赋初值
	deque<int> coll3(coll1.size());
	cout<<"创建coll3之后,输出其所有元素如下:,"<<endl;
	cout<<"同样是由default构造函数初始化并赋予初值:"<<endl;
	for (i = 0; i != coll3.size(); ++i)
		cout<<coll3[i]<<' ';
	cout<<endl;

	//copy elements from first into third collection
	copy(coll1.begin(), coll1.end(),  //source
			coll3.begin());           //destination
	cout<<"copy之后,输出coll3的所有元素如下:"<<endl;
	for (i = 0; i != coll3.size(); ++i)
		cout<<coll3[i]<<' ';
	cout<<endl;
	return 0;
}
