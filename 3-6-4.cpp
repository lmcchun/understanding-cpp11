#include <iostream>
#include <type_traits>

using namespace std;

union U {};
union U1 { U1() {} };
enum E{};
typedef double* DA;
typedef void (*PF)(int, double);

int main()
{
	cout << is_pod<U>::value << endl; // 1
	cout << is_pod<U1>::value << endl; // 0
	cout << is_pod<E>::value << endl; // 1
	cout << is_pod<int>::value << endl; // 1
	cout << is_pod<DA>::value << endl; // 1
	cout << is_pod<PF>::value << endl; // 1
	return 0;
}

// 编译选项: g++ -std=c++11 3-6-4.cpp
