#include <iostream>

using namespace std;

template<typename T, typename U>
void PerfectForward(T&& t, U& func)
{
	cout << t << "\tforwarded..." << endl;
	func(forward<T>(t));
}

void RunCode(double&& m) {}

void RunHome(double&& h) {}

void RunComp(double&& c) {}

int main()
{
	PerfectForward(1.5, RunComp);
	PerfectForward(8, RunCode);
	PerfectForward(1.5, RunHome);
	return 0;
}

// 编译选项: g++ -std=c++11 3-3-10.cpp
