#include <iostream>

using namespace std;

class HasPtrMem
{
public:
	HasPtrMem() : d(new int(0)) {}
	HasPtrMem(const HasPtrMem& h) : d(new int(*h.d)) {} // 拷贝构造函数, 从堆中分配内存, 并用 *h.d 初始化
	~HasPtrMem() { delete d; }
	int* d;
};

int main()
{
	HasPtrMem a;
	HasPtrMem b(a);
	cout << *a.d << endl;
	cout << *b.d << endl;
	return 0;
} // 正常析构
