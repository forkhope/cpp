//reverse iterators(逆向迭代器),会以逆向方式进行所有操作.它将++运算转换
//为--运算,反之亦然.所有容器都可以透过成员函数rbegin()和rend()产生出
//reverse iterators.如下程序所示:
#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>   //ostream_iterator需要这个头文件
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main()
{
	vector<int> coll;

	//insert elements from 1 to 9
	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	//print all elements in reverse order
	//coll.rbegin()返回一个由coll定义的reverse iterator.这个迭代器可作为
	//"对群集coll的元素逆向遍历"的起点.它指向群集的结尾位置.因此,表达式
	//*coll.rbegin()返回的是最后一个元素的值.对应地,表达式coll.rend()返回
	//的reverse iterator,可作为"对群集coll的元素逆向遍历"的终点.它指向的是
	//容器内第一个元素的前一个位置.所以表达式*coll.rend()没有定义.
	copy(coll.rbegin(), coll.rend(),           //source
			ostream_iterator<int>(cout, " ")); //destination
	cout<<endl;
	return 0;
}
