//使用template编写的一个简单程序，功能是传回两数之中的较大数
//程序中，max函数的参数和返回值都是引用值，不知道具体的原因，
//《C＋＋标准程序库》上就是这么写的，可能是为了减少内存空间开销吧
#include<iostream>
using std::endl;
using std::cout;

template<class T>
inline const T& max(const T& a,const T& b) //定义为内联函数
{
	// if a < b then use b else use a
	return a < b ? b : a;
}

int main()
{
	int i = max(5, 7);
	cout<<i<<endl;
	return 0;
}
