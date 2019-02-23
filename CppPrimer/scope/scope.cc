//定义在全局作用域中的名字可以在局部作用域中使用，定义在全局作用域中的名字
//和定义在函数的局部作用域中的名字可以在语句作用域中使用，等等。名字还可以
//在内部作用域中重新定义。下面的程序就定义了一个和全局变量名字相同的变量。
//像下面的程序很可能让人大惑不解。在函数内定义一个与函数可能会用到的全局
//变量同名的局部变量总是不好的。局部变量最好使用不同的名字。
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

string s1 = "Hello"; // s1 has global scope

int main()
{
	string s2 = "world";  // s2 has local scope
	cout<<s1<<" "<<s2<<endl;
	int s1 = 42;  // s1 is local and hides(屏蔽) global s1
	//如果全局变量和局部变量同名,则局部变量会屏蔽全局变量,即全局变量不可见
	cout<<s1<<" "<<s2<<endl; //将会输出int型s1,而不是string型s1
	return 0;
}
