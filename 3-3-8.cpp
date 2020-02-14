#include <iostream>
#include <utility>

using namespace std;

struct Maythrow
{
	Maythrow() {}
	Maythrow(const Maythrow&)
	{
		cout << "Maythrow copy constructor." << endl;
	}
	Maythrow(Maythrow&&)
	{
		cout << "Maythrow move constructor." << endl;
	}
};

struct Nothrow
{
	Nothrow() {}
	Nothrow(const Nothrow&)
	{
		cout << "Nothrow copy constructor." << endl;
	}
	Nothrow(Nothrow&&) noexcept
	{
		cout << "Nothrow move constructor." << endl;
	}
};

int main()
{
	Maythrow m;
	Nothrow n;
	Maythrow mt = move_if_noexcept(m); // Maythrow copy constructor.
	Nothrow nt = move_if_noexcept(n); // Nothrow move constructor.
	return 0;
}

// 编译选项: g++ -std=c++11 3-3-8.cpp
