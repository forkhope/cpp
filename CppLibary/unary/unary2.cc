//使用自己实现的find_if()算法.
#include<iostream>
#include<list>
#include<cstdlib>   // for abs()
using std::cout;
using std::endl;
using std::list;

//Predicate在这里是一个函数指针类型
template<class InputIterator, class Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate p)
{
	for (; first != last; ++first)
		if (p(*first))  //如果传进来的一元判断式为真,则找到,跳出
			break;
	return first;
}

bool IsPrime(int number)
{
	number = abs(number);

	//0 and 1 are no prime numbers
	if (number == 0 || number == 1)
		return false;

	//find divisor thar divides without a remainder
	int divisor;
	for (divisor = number / 2; number % divisor != 0; --divisor)
		; // do nothing

	//if no divisor greater than 1 is found, it is a prime number
	return 1 == divisor;
}

int main()
{
	list<int> coll;

	//insert elements from 24 to 30
	for (int i = 24; i != 31; ++i)
		coll.push_back(i);

	list<int>::iterator pos;
	pos = find_if(coll.begin(), coll.end(), IsPrime);

	(pos != coll.end()) ? cout<<*pos<<" is first prime number found"<<endl
		: cout<<"no prime number found"<<endl;
	return 0;
}
