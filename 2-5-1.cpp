#include <cassert>

using namespace std;

char* ArrayAlloc(int n)
{
	assert(n > 0); // 断言, n 必须大于 0
	return new char[n];
}

int main()
{
	char* a = ArrayAlloc(0);
}
