#include <iostream>

using namespace std;

// 这是 Jim 编写的库, 用了 Jim 这个名字空间
namespace Jim
{
	inline namespace Basic // 内联的名字空间
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

	inline namespace Toolkit
	{
		template<typename T>
		class SwissArmyKnife {};
	}

	namespace Other
	{
		Knife b; // Knife in Basic
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

	// 打开一些内部名字空间
	using namespace Basic;
	using namespace Toolkit;
}

// LiLei 决定对该 class 进行特化
namespace Jim
{
	template<>
	class SwissArmyKnife<Knife> {}; // 编译通过
}

using namespace Jim;

int main()
{
	SwissArmyKnife<Knife> sknife;
	return 0;
}

// 编译选项: g++ -std=c++11 3-9-3.cpp