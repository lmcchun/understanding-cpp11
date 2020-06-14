#include <iostream>

using namespace std;

union T
{
	static long Get()
	{
		return 32;
	};
};

int main()
{
	cout << T::Get() << endl;
}

// 编译选项: g++ -std=c++11 3-7-2.cpp