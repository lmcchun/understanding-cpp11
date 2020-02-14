#include <cstring>

using namespace std;

#define assert_static(e)\
	do {\
		enum { assert_static__ = 1 / (e) };\
	} while(0)

template<typename T, typename U>
void bit_copy(T& a, U& b)
{
	assert_static(sizeof(b) == sizeof(a));
	//static_assert(sizeof(b) == sizeof(a), "The parameters of bit_copy must have same width.");
	memcpy(&a, &b, sizeof(b));
}

int main()
{
	int a = 0x2468;
	double b;
	bit_copy(a, b);
	return 0;
}
