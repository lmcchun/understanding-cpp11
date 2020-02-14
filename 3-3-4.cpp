#include <iostream>

using namespace std;

class HasPtrMem
{
public:
	HasPtrMem() : d(new int(3))
	{
		cout << "Construct: " << ++n_cstr << endl;
	}
	HasPtrMem(const HasPtrMem& h) : d(new int(*h.d))
	{
		cout << "Copy construct: " << ++n_cptr << endl;
	}
	HasPtrMem(HasPtrMem&& h) : d(h.d) // 移动构造函数
	{
		h.d = nullptr; // 将临时值的指针置空
		cout << "Move construct: " << ++n_mvtr << endl;
	}
	~HasPtrMem()
	{
		delete d;
		cout << "Destruct: " << ++n_dstr << endl;
	}
	int* d;
	static int n_cstr;
	static int n_dstr;
	static int n_cptr;
	static int n_mvtr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_mvtr = 0;

HasPtrMem GetTemp()
{
	HasPtrMem h;
	cout << "Resource from " << __func__ << ": " << hex << h.d << endl;
	return h;
}

int main()
{
	HasPtrMem a = GetTemp();
	cout << "Resource from " << __func__ << ": " << hex << a.d << endl;
	return 0;
}

// 编译选项: clang++ -std=c++11 3-3-4.cpp -fno-elide-constructors
