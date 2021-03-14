template <int l> struct A {};

char xxx(int);
char xxx(float);

template <class T>
A<sizeof(xxx((T)0))> f(T) {}

int main()
{
	f(1);
	return 0;
}

// 编译选项: g++ -std=c++11 2-14-2.cpp