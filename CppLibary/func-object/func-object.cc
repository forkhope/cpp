//函数对象(Function Objects):函数对象是一个对象,只是它的行为表现像函数.一般
//而言,它是由一个重载了operator()的类所实例化得来的对象.所谓函数行为,是指可
//以"使用小括号传递参数,藉以调用某个东西",可以和函数func(arg1)一般被调用.
#include<iostream>
#include<list>
using std::cout;
using std::endl;
using std::list;

//下面的Function类型为函数指针类型.
template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
	for (; first != last; ++first)
		f(*first);
	return f;
}

class PrintInt
{
public:
	//函数后面加const,是给隐含的this指针加const,表示这个this指向的对象是
	//const的,也就是说这个函数不能改动数据成员.const能够保证该成员函数不会
	//改变对象的数据成员.总之,const意味着"只读",表明函数不能修改数据成员.
	void operator()(int elem) const
	{
		cout<<elem<<' ';
	}
};

int main()
{
	list<int> coll;

	//insert elements from 1 to 9
	for (int i = 1; i != 10; ++i)
		coll.push_back(i);

	//PrintInt()表达式产生出此类的一个临时对象,当做for_each()算法的一个参数
	for_each(coll.begin(), coll.end(), PrintInt());
	cout<<endl;
	return 0;
}
