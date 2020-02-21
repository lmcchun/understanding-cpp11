#include <iostream>

using namespace std;

void RunCode(int&& m) { cout << "rvalue ref" << endl; }

void RunCode(int& m) { cout << "lvalue ref" << endl; }

void RunCode(const int&& m) { cout << "const rvalue ref" << endl; }

void RunCode(const int& m) { cout << "const lvalue ref" << endl; }

template<typename T>
void PerfactForward(T&& t)
{
	RunCode(forward<T>(t));
}

int main()
{
	int a;
	int b;
	const int c = 1;
	const int d = 0;
	PerfactForward(a);
	PerfactForward(move(b));
	PerfactForward(c);
	PerfactForward(move(d));
	return 0;
}

// 编译选项: g++ -std=c++11 3-3-9.cpp
