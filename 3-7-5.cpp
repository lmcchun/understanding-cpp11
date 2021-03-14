#include <string>

using namespace std;

union T
{
	string s; // string 有非平凡的构造函数
	int n;
public:
	// 自定义构造函数和析构函数
	T() { new (&s) string; }
	~T() { s.~string(); }
};

int main()
{
	T t; // 构造析构成功
	return 0;
}

// 编译选项: g++ -std=c++11 3-7-5.cpp