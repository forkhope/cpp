//vector将其元素置于一个dynamic array中加以管理.它允许随机存取,也就是说
//可以利用索引直接存取任何一个元素.其头文件为<vector>,命名空间为std
#include<vector>
#include<string>
#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
	string word;
	vector<string> text;
	while (cin>>word)
		text.push_back(word); //push_back(t)向text的末尾增加一个值为t的元素
	// 注意，下标操作不添加元素，下标只能用于获取已存在的元素
	for (vector<string>::size_type ix=0; ix != text.size(); ++ix)
		cout<<text[ix]<<" "; //取位置为ix的元素
	cout<<endl;
	// 除了使用下标操作，还可以使用迭代器(iterator)来检查容器内元素并
	// 遍历元素，迭代器适用于所有容器，而下标操作只适用于部分容器
	// 每一种容器都定义了一对begin和end函数，来返回迭代器类型，如果容器中
	// 有元素，由begin返回的迭代器指向第一个元素；end返回的迭代器指向
	// vector的”末端元素的下一个”，它并不指向vector中任何实际的元素。
    // 下面定义一个vector<string>类型的迭代器，并取出vector<string>中的元素
	for (vector<string>::iterator iter=text.begin();
			iter != text.end(); ++iter)
		cout<<*iter<<" ";  // 用＊号来访问迭代器指向的元素,和指针一样
	cout<<endl;
	return 0;
}
