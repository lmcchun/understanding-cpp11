#include <iostream>

using namespace std;

// 这是 Jim 编写的库, 用了 Jim 这个名字空间
namespace Jim
{
	namespace Basic
	{
		struct Knife
		{
			Knife()
			{
				cout << "Knife in Basic." << endl; 
			}
		};
		class CorkScrew {};
	}

	namespace Toolkit
	{
		template<typename T>
		class SwissArmyKnife {};
	}

	namespace Other
	{
		Knife b; // 无法通过编译
		struct Knife
		{
			Knife()
			{
				cout << "Knife in Other." << endl;
			}
		};
		Knife c; // Knife in Other
		Basic::Knife k; // Knife in Basic
	}
}

// 这是 LiLei 在使用 Jim 的库
using namespace Jim;

int main()
{
	Toolkit::SwissArmyKnife<Basic::Knife> sknife;
	return 0;
}

// 编译选项: g++ 3-9-1.cpp