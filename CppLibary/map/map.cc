//这个例子将map容器用做关联式数组(associative arrays).所谓关联式数组就是:
//索引可以采用任何类别,而map容器是一种模板类,其键值可为任意类别,这正是关
//联式数组的接口.
#include<iostream>  //I/O输入输出流
#include<map>       //map容器的头文件
#include<string>    //string类型的头文件
using std::cout;
using std::endl;
using std::string;

int main()
{
	//当我们声明map或者multimap容器类型的时候,必须同时指定键值(key)
	//和实值(value)的类别,这两种类别组成一个pair对组.
	typedef std::map<string, float> StringFloatMap;
	StringFloatMap coll;

	//insert some elements into the collection
	//map允许我们使用operator[]安插新元素,而multimap不能这么做
	coll["VAT"] = 0.15;
	coll["Pi"]  = 3.1415;
	coll["an number"] = 4983.223;
	coll["NULL"] = 0;

	//print all elements, iterator over all elements, element member 
	//first is the key, element member second is the value,如下所示:
	StringFloatMap::iterator iter;
	for (iter = coll.begin(); iter != coll.end(); ++iter)
		cout<<"Key: \""<<iter->first<<"\" "<<"Value: "<<iter->second<<endl;
	return 0;
}
