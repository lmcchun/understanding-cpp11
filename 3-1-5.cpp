struct A { A(int) {} };

struct B { B(int) {} };

struct C : A, B
{
	using A::A;
	using B::B;
};

int main()
{
	C c{0};
	return 0;
}
