#include <string>

using namespace std;

class Cls
{
public:
	Cls() = default;
	//Cls() {} // 非平凡的 Cls()
	Cls(int n_) : n(n_) {}

private:
	int n/* = 0*/;
	// Cls 如果是非受限联合体的成员且 n 就地初始化,
	// 则非受限联合体的构造函数会被删除.
};

union T
{
	string s; // string 有非平凡的构造函数
	//Cls c;
	int n;
};

int main()
{
	T t; // 构造失败, 因为 T 的构造函数被删除了
	return 0;
}

// 编译选项: g++ -std=c++11 3-7-4.cpp