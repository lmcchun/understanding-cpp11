struct A
{
	A(int i) {}
	A(double d, int i) {}
	A(float f, int i, const char* c) {}
	// ...
};

struct B : A
{
	using A::A;
	int d{0};
};

int main()
{
	B b(356); // b.d 被初始化为 0
	return 0;
}
