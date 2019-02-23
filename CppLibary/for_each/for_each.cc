//以函数作为算法的参数.一些算法可以接受用户定义的辅助性函数,由此提高其灵活性
//和能力.这些函数将在算法内部调用.下面的for_each()算法就是一个这样的算法.它
//针对区间内的每一个元素,调用一个由用户指定的函数(是由算法自身遍历所有元素).
#include<iostream>
#include<vector>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;

//function that prints the passed argument
void print (int elem)
{
	cout<<elem<<' ';
}

int main()
{
	vector<int> coll;

	//insert elements from 1 to 9;
	for (int i = 1; i != 10; ++i)
		coll.push_back(i);

	//这里的for_each()函数针对[coll.begin(), coll.end()]区间内的每个元素调用    //print()函数(再强调一遍,是for_each算法自身来遍历区间内的每个元素).
	for_each(coll.begin(), coll.end(), print);
	cout<<endl;
	return 0;
}
