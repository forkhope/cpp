//Examples of using deques. The following program is a simple example that
//shows abilities of deques. OK, that's all(The program is really simple).
#include<iostream>
#include<deque>
#include<string>
#include<algorithm>  //copy()函数需要这个头文件
#include<iterator>   //ostream_iterator迭代器需要这个头文件
using std::cout;
using std::endl;
using std::deque;
using std::string;
using std::ostream_iterator;

int main()
{
	//create empty deque of strings
	deque<string> coll;

	//insert several elements;
	coll.assign(3, "string"); //执行这一句,coll中将有3个元素,值都是"string"
	coll.push_back("last string");
	coll.push_front("first string");

	//print elements separated by newlines
	copy (coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));
	cout<<endl;
	
	//remove last and first element
	coll.pop_back();
	coll.pop_front();

	//insert "another" into every element but the first
	for (int i = 1; i < coll.size(); ++i)
		coll[i] = "another " + coll[i];   //deque容器可以直接使用[]存取

	//change size to four elements
	coll.resize(4, "resized string");
	
	//print elements separated by newlines
	copy (coll.begin(), coll.end(), ostream_iterator<string>(cout, "\n"));
	return 0;
}
