//stream iterator是一种用来读写stream的迭代器(stream(流)是一个用来表现
//I/O通道的对象),它们提供了必要的抽象性,使得来自键盘的输入像是个群集,你
//能够从中读取内容.同样道理,你也可以把一个算法的输出结果重新导向到某个
//文件或屏幕上
#include<iostream>   //I/O输入输出流
#include<vector>     //vector类型的头文件
#include<string>     //string类型的头文件
#include<algorithm>  //copy()函数的头文件
#include<iterator>   //书上没有这一句,但不加的话会编译失败
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
	vector<string> coll;

	//istream_iterator<string>(cin)产生一个可从"标准输入流cin"读取数据的
	//stream iterator.期中的template参数string表示这个stream iterator读取
	//该种类型的元素.istream_iterator<string>()调用istream iterators的
	//default构造函数,产生一个代表"流结束符号"的迭代器,它代表的意义是:你
	//不能再从中读取任何东西,这个可用来确认输入区间终点.
	copy(istream_iterator<string>(cin),   //start of source
			istream_iterator<string>(),   //end of source
			back_inserter(coll));         //destination
	cout<<endl;

	//sort elements
	sort(coll.begin(), coll.end());

	//ostream_iterator<string>(cout, "\n")会产生一个output stream iterator,
	//透过operator<<向cout写入strings.cout之后的第二个参数(可有可无)被用来
	//作为元素之间的分割符.使用的时候,注意这都是template组件,要写上参数类型
	unique_copy(coll.begin(), coll.end(),           //source
			ostream_iterator<string>(cout, "\n"));   //destination
	return 0;
}
