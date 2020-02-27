#include <iostream>

using namespace std;

struct B1 {};
struct B2 {};

struct D1 : B1
{
	B1 b; // 第一个非静态变量跟基类相同
	int i;
};

struct D2 : B1
{
	B2 b;
	int i;
};

int main()
{
	D1 d1;
	D2 d2;
	cout << hex;
	cout << reinterpret_cast<long long>(&d1) << endl; // 7ffff3850b38
	cout << reinterpret_cast<long long>(&d1.b) << endl; // 7ffff3850b39
	cout << reinterpret_cast<long long>(&d1.i) << endl; // 7ffff3850b3c
	cout << reinterpret_cast<long long>(&d2) << endl; // 7ffff3850b40
	cout << reinterpret_cast<long long>(&d2.b) << endl; // 7ffff3850b40
	cout << reinterpret_cast<long long>(&d2.i) << endl; // 7ffff3850b44
	return 0;
}

// 编译选项: g++ -std=c++11 3-6-2.cpp
