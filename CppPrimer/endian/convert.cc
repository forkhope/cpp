//大端和小端的相互转换程序
#include<iostream>
using std::cout;
using std::endl;

typedef unsigned short u_16;
typedef unsigned int u_32;

//对16位数据的转换
#define BSWAP_16(x) \
	(u_16) ((((u_16)(x) & 0x00ff) << 8) | \
			(((u_16)(x) & 0xff00) >> 8))

//对32位数据的转换
#define BSWAP_32(x) \
	(u_32) ((((u_32)(x) & 0x000000ff) << 24) | \
			(((u_32)(x) & 0x0000ff00) << 8)  | \
			(((u_32)(x) & 0x00ff0000) >> 8)  | \
			(((u_32)(x) & 0xff000000) >> 24))


int main()
{
	cout<<"0x1234转换之后为: 0x"<<std::hex<<BSWAP_16(0x1234)<<endl;
	printf("使用printf函数输出为: %#x\n", BSWAP_16(0x1234));
	cout<<"--------------------------------"<<endl;
	cout<<"0x12345678转换之后为: 0x"<<std::hex<<BSWAP_32(0x12345678)<<endl;
	return 0;
}
