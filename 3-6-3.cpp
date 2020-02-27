#include <iostream>
#include <type_traits>

using namespace std;

struct SLayout1 {};

struct SLayout2
{
private:
	int x;
	int y;
};

struct SLayout3 : SLayout1
{
	int x;
	int y;
	void f();
};

struct SLayout4 : SLayout1
{
	int x;
	SLayout1 y;
};

struct SLayout5 : SLayout1, SLayout3 {};

struct SLayout6
{
	static int y;
};

struct SLayout7 : SLayout6

{
	int x;
};

// 第一个非静态成员和基类均为 SLayout1 类型.
struct NonSLayout1 : SLayout1
{
	SLayout1 x;
	int i;
};

// 基类和派生类都有非静态成员.
struct NonSLayout2 : SLayout2 { int z; };

// 基类不是标准布局.
struct NonSLayout3 : NonSLayout2 {};

// 非静态成员变量的访问权限不同.
struct NonSLayout4
{
public:
	int x;
private:
	int y;
};

int main()
{
	cout << is_standard_layout<SLayout1>::value << endl; // 1
	cout << is_standard_layout<SLayout2>::value << endl; // 1
	cout << is_standard_layout<SLayout3>::value << endl; // 1
	cout << is_standard_layout<SLayout4>::value << endl; // 1
	cout << is_standard_layout<SLayout5>::value << endl; // 1
	cout << is_standard_layout<SLayout6>::value << endl; // 1
	cout << is_standard_layout<SLayout7>::value << endl; // 1
	cout << is_standard_layout<NonSLayout1>::value << endl; // 1
	cout << is_standard_layout<NonSLayout2>::value << endl; // 1
	cout << is_standard_layout<NonSLayout3>::value << endl; // 1
	cout << is_standard_layout<NonSLayout4>::value << endl; // 1
	return 0;
}

// 编译选项: g++ -std=c++11 3-6-3.cpp
