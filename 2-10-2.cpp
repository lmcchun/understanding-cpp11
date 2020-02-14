struct Object
{
	virtual void fun() = 0;
};

struct Base : public Object
{
	void fun() final; // 声明为 final
};

struct Derived : public Base
{
	void fun(); // 无法通过编译
	//void fun(int x); // 重定义是允许的
};
