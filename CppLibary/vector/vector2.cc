//Examples of using vectors. 恩,如此而已......
#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ostream_iterator;

int main()
{
	//create empty vector for strings
	vector<string> sentence;

	//reserve memory for five elements to avoid reallocation
	sentence.reserve(5);

	//append some elements
	sentence.push_back("Hello,");
	sentence.push_back("how");
	sentence.push_back("are");
	sentence.push_back("you");
	sentence.push_back("?");

	//print elements separated with spaces
	copy (sentence.begin(), sentence.end(),
			ostream_iterator<string>(cout, " "));
	cout<<endl;

	//print "technical data"
	cout<<"max_size(): "<<sentence.max_size()<<endl;
	cout<<"size():     "<<sentence.size()<<endl;
	cout<<"capacity(): "<<sentence.capacity()<<endl;

	//swap second and fourth element. vector容器可以直接用[]进行存取
	swap (sentence[1], sentence[3]);

	//insert element "always" before element "?"
	sentence.insert (find(sentence.begin(), sentence.end(), "?"),
				"always");

	//assign "!" to the last element. 对最后的元素进行重新赋值
	sentence.back() = "!";

	//print elements separated with spaces
	copy (sentence.begin(), sentence.end(),
			ostream_iterator<string>(cout, " "));
	cout<<endl;

	//print "technical data" again. 注意capacity()函数返回值的变化
	//vector和string容器在进行扩展时,它们的容量一般会翻倍扩展
	cout<<"max_size(): "<<sentence.max_size()<<endl;
	cout<<"size():     "<<sentence.size()<<endl;
	cout<<"capacity(): "<<sentence.capacity()<<endl;
	return 0;
}
