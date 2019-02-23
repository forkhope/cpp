//set属于关联式容器,关联式容器依据特定的排序准则,自动为其元素排序.排序准则
//以函数形式呈现,用来比较元素值(value)或元素键(key).缺省情况下以operator<
//进行比较,也就是以递增方式排列,不过你也可以提供自己的比较函数,定义出不同
//的排序准则.通常关联式容器由二叉排序树来存储.
//另外,set中的元素值只能出现一次,不允许重复;而multiset则允许重复元素.
#include<iostream>
#include<set>   //set容器和multiset容器的头文件都是<set>

int main()
{
	typedef std::set<int> IntSet;

	IntSet coll;

	//insert elements to set container
	//关联式容器安插新元素,应该使用insert()函数,不能使用序列式容器的
	//push_back()和push_front()函数,因为关联式容器的元素位置是自动排列的
	coll.insert(3);
	coll.insert(1);
	coll.insert(5);
	coll.insert(4);
	coll.insert(1); //插入的这个1将被丢弃,因为set容器不允许重复元素
	coll.insert(6);
	coll.insert(2);

	//print all elements
	IntSet::const_iterator iter; //定义一个只读迭代器
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		std::cout<<*iter<<' ';
	std::cout<<std::endl;

	//关于multiset的示例程序不写了,和set类似,区别在于如何处理重复元素
	return 0;
}
