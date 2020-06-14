union T
{
	int x;
	double d;
	char b[sizeof(double)];
};

T t = {0}; // 到底是初始化第一个成员还是所有成员呢?

// 编译选项: g++ -std=c++98 -c 3-7-3.cpp