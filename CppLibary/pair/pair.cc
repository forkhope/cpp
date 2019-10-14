// 展示了pair类型的使用，该类型的头文件是utility，命名空间是std，
// pair类型属于模板类型，它有两个成员，first和second，对应两个值
#include<iostream>
#include<utility>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::make_pair;

pair<int, string> ReturnTwoValue()
{
	pair<int, string> p(20, "Hello, World.");
	return p;
}

void Compare(const pair<int, string>& obj, const pair<int, string>& obj2)
{
	// 两个pair类型之间可以直接进行比较
	// 只有两个值都相等时，两个pair类型之间才是相等
	if (obj == obj2) 
		cout<<"obj == obj2"<<endl;
	else if (obj > obj2)
		cout<<"obj > obj2"<<endl;
	else
		cout<<"obj < obj2"<<endl;
}

int main()
{
	pair<int, string> obj = ReturnTwoValue();
	cout<<obj.first<<" "<<obj.second<<endl;

	pair<int, string> obj2(17, "Hello");
	Compare(obj, obj2);

	// make_pair()使我们无需写出类别，就可以生成一个pair对象
	// 下面使用make_pair()传递一个参数给Compare()函数
	// 此外,make_pair()经常用于给map容器插入元素
	Compare(obj, make_pair(20, "AdGyhnUi"));
	Compare(obj, make_pair(20, "Hello, World."));
	return 0;
}
