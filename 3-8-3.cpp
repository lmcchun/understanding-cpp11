struct Watt { unsigned int v; };

Watt operator""_w(unsigned long long v)
{
	return {(unsigned int)v};
}

int main()
{
	Watt capacity = 1024_w;
}

// 编译选项: g++ -std=c++11 3-8-3.cpp