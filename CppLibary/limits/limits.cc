//使用模板类numeric_limits<T>来获取数据类型T的数值极值,其静态成员函数
//max()返回数据类型T的极大值,静态成员函数min()返回T的极小值.此外,它还
//有很多成员函数,见《C++标准程序库》第61页,这里不一一列出
#include<iostream>
#include<climits>  //c语言关于数值极值的头文件,也可以写为<limits.h>
#include<limits>   //c++关于数值极值的头文件
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::boolalpha;

int main()
{
	//输出true或者false,如果没有下面一句,当输出结果为假会输出0,为真会输出1
	cout<<boolalpha; //使用这一句,当输出结果为假会输出false,为真则输出true

	//print maximum of integral types
	cout<<"max(short): "<<numeric_limits<short>::max()<<endl;
	//cout<<"max(int): "<<numeric_limits<int>::max()<<endl; //c++的写法
	cout<<"max(int): "<<INT_MAX<<endl; //c的写法,要包含limits.h头文件
	cout<<"max(long): "<<numeric_limits<long>::max()<<endl;
	cout<<endl;

	//print minimum of integral types
	cout<<"min(short): "<<numeric_limits<short>::min()<<endl;
	cout<<"min(int): "<<INT_MIN<<endl; //要使用INT_MIN,要包含limits.h头文件
	cout<<"min(long); "<<numeric_limits<long>::min()<<endl;
	cout<<endl;

	//print maximum of floating-point types
	cout<<"max(float): "<<numeric_limits<float>::max()<<endl;
	cout<<"max(double): "<<numeric_limits<double>::max()<<endl;
	cout<<"max(long double): "<<numeric_limits<long double>::max()<<endl;
	cout<<endl;

	//print whether char is signed,也就是是否有符号
	cout<<"is_signed(char): "<<numeric_limits<char>::is_signed<<endl;

	//print whether numeric_limits for type string exist,也就是是否有极值
	cout<<"is_specialized(string): "
		<<numeric_limits<string>::is_specialized<<endl;
	cout<<endl;
	return 0;
}
