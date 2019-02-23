//为了处理容器内的元素,STL提供了一些标准算法,包括搜寻、排序、拷贝、修改、
//重新排序、数值运算等十分基本而普通的算法.算法并非容器类别的成员函数,
//而是一种搭配迭代器使用的全局函数.其头文件为<algorithm>.所有算法处理的
//都是半开区间——包含起始元素位置但不包含结尾元素位置,下面的例子都是这样
#include<iostream>  //I/O输入输出流
#include<vector>    //vector序列式容器的头文件
#include<algorithm> //为了调用算法,必须包含该头文件
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> coll;
	vector<int>::iterator pos;

	//insert elements from 1 to 6 in default order
	coll.push_back(2);
	coll.push_back(5);
	coll.push_back(4);
	coll.push_back(1);
	coll.push_back(6);
	coll.push_back(3);

	//find and print minimum and maximum elements
	//min_element()和max_element()需要两个参数,定义出欲处理的元素范围.
	//这两个函数的返回值都是迭代器类型,可以使用*操作符来提取迭代器的值
	pos = min_element(coll.begin(), coll.end());
	cout<<"min: "<<*pos<<endl;
	//pos = max_element(coll.begin(), coll.end());
	//cout<<"max: "<<*pos<<endl; 可以直接这样写:
	cout<<"max: "<<*max_element(coll.begin(), coll.end())<<endl;

	cout<<"排序之前,容器中的元素顺序为:"<<endl;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<" ";
	cout<<endl;
	//sort all elements
	//sort()将由两个参数设定出来的区间内所有元素加以排序.我们还可以传入
	//一个排序准则:缺省的是operator<.因此,排序后所有元素以递增方式排列
	sort(coll.begin(), coll.end());
	cout<<"排序之后,容器中的元素顺序为:"<<endl;
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<" ";
	cout<<endl;

	//find the first element with value 3
	//find()同样返回一个迭代器,指向目标元素.如果失败,返回一个"逾尾"
	//迭代器,也就是成员函数end()的返回值.
	pos = find(coll.begin(), coll.end(), //range
			3); //value,也就是要查找的值,在上面指定的范围内查找

	//reverse(反转) the order of the found element 
    //with value 3 and all following elements
	//例如,3 4 5 6反转之后就是6 5 4 3 
	reverse(pos, coll.end());//要反转的元素从pos开始,直到但不包括coll.end()

	//print all elements after reversed
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<' ';
	cout<<endl;
	return 0;
}
