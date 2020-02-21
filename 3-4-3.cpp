class ConvertTo {};

class Convertable
{
public:
	explicit operator ConvertTo() const
	{
		return ConvertTo();
	}
};

void Func(ConvertTo ct) {}

int main()
{
	Convertable c;
	ConvertTo ct(c); // 直接初始化, 通过.
	ConvertTo ct2 = c; // 拷贝构造初始化, 编译失败.
	ConvertTo c3 = static_cast<ConvertTo>(c); // 强制强化, 通过.
	Func(c); // 拷贝构造初始化, 编译失败.
}

// 编译选项: g++ -std=c++11 3-4-3.cpp
