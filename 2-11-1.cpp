#include <iostream>

using namespace std;

// 定义一个函数模板
template<typename T>
void TempFun(T a)
{
	cout << a << endl;
}

void DefParm(int m = 3) {} // C++98 编译通过, C++11 编译通过

template<typename T = int> class DefClass {}; // C++98 编译通过, C++11 编译通过

template<typename T = int> void DefTempParm() {} // C++98 编译失败, C++11 编译通过

int main()
{
	TempFun(1); // 实例化为 TempFun<const int>(1)
	TempFun("1"); // 实例化为 TempFun<const char*>("1")
	return 0;
}
