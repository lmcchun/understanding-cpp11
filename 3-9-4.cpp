#include <iostream>

using namespace std;

// 这是 Jim 编写的库, 用了 Jim 这个名字空间
namespace Jim
{
#if __cplusplus == 201103L
	inline
#endif
	namespace cpp11
	{
		struct Knife
		{
			Knife()
			{
				cout << "Knife in C++11." << endl; 
			}
		};
		class CorkScrew {};
	}

#if __cplusplus < 201103L
	inline
#endif
	namespace oldcpp
	{
		struct Knife
		{
			Knife()
			{
				cout << "Knife in old C++." << endl;
			}
		};
	}
}

using namespace Jim;

int main()
{
	Knife a; // Knife in C++11. (默认版本)
	cpp11::Knife b; // Knife in C++11. (强制使用 cpp11 版本)
	oldcpp::Knife c; // Knife in old C++. (强制使用 oldcpp 版本)
	return 0;
}

// 编译选项: g++ -std=c++11 3-9-4.cpp