//函数对象比起一般函数有如下优点:函数对象是"smart functions(智能型函数)".函
//数对象可拥有成员函数和成员变量,这意味函数对象拥有状态.另外,我们可以在执行
//期(runtime)初始化它们;每个函数对象都有自己的类型;函数对象通常比一般函数快.
#include<iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

template<class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
	for (; first != last; ++first)
		f(*first);
	return f;
}

template<class T>
inline void PrintElements(const T& coll, const char *optcstr = "")
{
	cout<<optcstr<<endl;
	//注意,coll传进来是const型,迭代器也要定义为const型
	typename T::const_iterator pos; 
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout<<*pos<<' ';
	cout<<endl;
}

class AddValue
{
private:
	int theValue;  //the value to add
public: 
	//constructor initializes the value to add
	AddValue(int v):theValue(v) {}

	//重载operator(),让对象具有函数行为,也就是让对象成为函数对象
	void operator()(int& elem) const
	{
		elem += theValue;
	}
};

int main()
{
	vector<int> coll;

	//insert elements from 1 to 9
	for (int i = 1; i != 10; ++i)
		coll.push_back(i);

	PrintElements (coll, "Initialized:");

	//add value 10 to each element
	//表达式AddValue(10)会生出一个AddValue对象,并以10为初值.AddValue构造函数
	//将这个值保存在变量theValue中.而在for_each()之内,针对coll的每一个元素
	//调用"()",实际上就是对传入的那个AddValue临时对象调用operator(),并以容器
	//元素作为参数,从而将每个元素加10.
	for_each (coll.begin(), coll.end(), AddValue(10));

	PrintElements (coll, "After adding 10:");

	//add value of first element to each element
	//表达式AddValue(*coll.begin())生出另外一个AddValue对象,该对象和上面的
	//AddValue(10)对象不同,区别在于theValue变量值并不相同.
	//注意,一个类可以生成不同的函数对象.函数对象是有状态的.
	for_each (coll.begin(), coll.end(), AddValue(*coll.begin()));

	PrintElements (coll, "After adding first element:");
	return 0;
}
