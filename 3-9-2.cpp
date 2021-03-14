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
		//
	}

	// 打开一些内部名字空间
	using namespace Basic;
	using namespace Toolkit;
}

// LiLei 决定对该 class 进行特化
namespace Jim
{
	template<>
	class SwissArmyKnife<Knife> {}; // 编译失败
}

using namespace Jim;

int main()
{
	SwissArmyKnife<Knife> sknife;
	return 0;
}

// 编译选项: g++ 3-9-2.cpp