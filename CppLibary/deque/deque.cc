//deque是"double-ended queue"的缩写.它是一个dynamic array,可以向两端发展,
//deque属于顺序容器,其头文件为<deque>,命名空间为std,大致如此,此外无他
#include<iostream>
#include<deque>
using std::cout;
using std::endl;
using std::deque;
using std::iterator;

int main()
{
	//定义一个浮点型的deque容器对象
	deque<float> collect; //deque container for floating-point elements
	int i;
	//insert elements from 1.1 to 6.6 each at the front
	//在写for循环时,尽可能用前置式递增++i的方式,因为它比"后置式递增"i++
	//效率高.后者需要一个额外的临时对象,因为它必须存放i的原本值并将它返回
	//所以一般情况下最好使用++i,不要用i++
	for (i = 1; i <= 6; ++i)
		collect.push_front(i * 1.1); //insert at the front
	
	//print all elements followed by a space
	//插入时是从头部插入,所以后插入的反而在前面,输出时是插入次序的逆序
	for (i = 0; i != collect.size(); ++i)
		cout<<collect[i]<<" ";
	cout<<endl;

	//insert elements from 1.1 to 6.6 each at the rear
	for (i = 1; i <= 6; ++i)
		collect.push_back(i * 1.1); //insert at the back

	//use iterator(迭代器) to print the all elements
	deque<float>::iterator iter;
	for (iter = collect.begin(); iter != collect.end(); ++iter)
		cout<<*iter<<" ";
	cout<<endl;
	return 0;
}
