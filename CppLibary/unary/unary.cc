//unary: 单一元素的、单一构成的、一元的.
//算法有一种特殊的辅助函数叫做predicates(判断式).所谓predicates,就是返回布尔
//值(boolean)的函数.它们通常被用来指定排序准则和搜寻准则.Predicates可能有一
//个或两个操作数,视具体情况而定.下面是一个Unary Predicates(一元判断式)的例子
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>     // for abs(),该函数返回一个绝对值
using std::endl;
using std::cout;
using std::vector;

//predicate(判断,依据), which returns whether an integer is a prime number
bool IsPrime(int number)
{
	//ignore negative sign
	number = abs(number); 

	//0 and 1 are no prime numbers
	if (0 == number || 1 == number)
		return false;

	//find divisor thar divides without a remainder
	int divisor;
	for (divisor = number / 2; number % divisor != 0; --divisor)
		;  // do nothing

	//if no divisor greater than 1 is found, it is a prime number
	return 1 == divisor;
}

int main()
{
	vector<int> coll;

	for (int i = 24; i != 31; ++i)
		coll.push_back(i);

	//search for prime number
	//在这个例子中,find_if()算法在左闭右开区间内寻找使"被传入之一元判断式"
	//运算结果为true的第一个元素.本例中的predicate是IsPrime()函数,它会检查
	//某数是否为质数.通过她,这个算法可以返回给定区间内的第一个质数.如果没有
	//任何元素能够匹配这个条件,find_if()算法就返回区间终点(即函数的第二参数)
	vector<int>::iterator pos;
	pos = find_if (coll.begin(), coll.end(), IsPrime);

	(pos != coll.end()) ? cout<<*pos<<" is first prime number found"
		: cout<<"no prime number found";
	cout<<endl;
	return 0;
}
