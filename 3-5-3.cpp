#include <initializer_list>

using namespace std;

void Fun(initializer_list<int> iv) {}

int main()
{
	Fun({1, 2});
	Fun({}); // 空列表
}

// 编译选项: g++ -std=c++11 3-5-3.cpp
