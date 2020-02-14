#include <string>

using namespace std;

class Mem
{
public:
	Mem(int i) : m(i) {}

private:
	int m;
};

class Group
{
public:
	Group() {} // 这里就不需要初始化 data, mem, name 成员了
	Group(int a) : data(a) {} // 这里就不需要初始化 mem, name 成员了
	Group(Mem m) : mem(m) {} // 这里就不需要初始化 data, name 成员了
	Group(int a, Mem m, string n) : data(a), mem(m), name(n) {}

private:
	int data = 1;
	Mem mem{0};
	string name{"Group"};
};
