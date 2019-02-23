//使用自己实现的for_each()算法.(这个函数非原创,是从下面的网址找到的)
//网址为 http://www.cplusplus.com/reference/algorithm/for_each/
#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

//下面Function类型,在具体应用中为函数指针类型,就是指向传进来的函数的指针
template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
	for(; first != last; ++first)
		f(*first);
	//该函数的返回值和f相同.The Return value is same as f.
	return f; 
}

void print(int elem)
{
	cout<<elem<<' ';
}

int main()
{
	vector<int> coll;

	//insert elements from 1 to 9
	for (int i = 1; i != 10; ++i)
		coll.push_back(i);

	//在引用函数名但又没有调用该函数时,函数名将被自动解释为指向函数的指针
	//print是函数首地址,因此传进去的是一个函数指针
	for_each (coll.begin(), coll.end(), print);
	cout<<endl;
	return 0;
}
