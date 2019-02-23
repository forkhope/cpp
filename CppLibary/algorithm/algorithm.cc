//C++算法程序库(定义于头文件<algorithm>)内含三个辅助函数，一个用来在两值
//之中挑选较大者,另一个用来在两值之中挑选较小者,第三个用来交换两值
#include<iostream>
#include<algorithm>
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::swap;

int main()
{
	int x = 20;
	int y = 10;
	cout<<"max(x, y) is: "<<max(x, y)<<endl;
	cout<<"min(x, y) is: "<<min(x, y)<<endl;
	cout<<"交换之前，x = "<<x<<", y = "<<y<<endl;
	swap(x, y);
	cout<<"交换之后，x = "<<x<<", y = "<<y<<endl;
	return 0;
}
