template<typename T> class X {};

template<typename T> void TempFun(T t) {}

struct A {} a;

struct
{
	int i;
} b; // b 是匿名类型变量

typedef struct
{
	int i;
} B; // B 是匿名类型

void Fun()
{
	struct C {} c; // C 是局部类型

	X<A> x1; // C++98 通过, C++11 通过
	X<B> x2; // C++98 错误, C++11 通过 // 实际上使用 clang++ -c 2-13-1.cpp 编译通过, clang-1100.0.33.16
	X<C> x3; // C++98 错误, C++11 通过
	TempFun(a); // C++98 通过, C++11 通过
	TempFun(b); // C++98 错误, C++11 通过
	TempFun(c); // C++98 错误, C++11 通过
}
