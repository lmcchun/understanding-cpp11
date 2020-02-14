#include <cassert>
#include <iostream>

using namespace std;

enum FeatureSupports
{
	C99		= 0x0001,
	ExtInt		= 0x0002,
	SAssert		= 0x0004,
	NoExcept	= 0x0008,
	SMAX		= 0x0010,
};

struct Compiler
{
	const char* name;
	int spp; // 使用 FeatureSupports 枚举
};

int main()
{
	// 检查枚举是否完备
	assert((SMAX - 1) == (C99 | ExtInt | SAssert | NoExcept));
	Compiler a = {"abc", (C99 | SAssert)};
	if (a.spp & C99)
	{
		cout << "XXX" << endl;
	}
	return 0;
}
