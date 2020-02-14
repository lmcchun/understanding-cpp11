#include <climits>
#include <cstdio>

using namespace std;

int main()
{
	long long ll_min = LLONG_MIN;
	long long ll_max = LLONG_MAX;
	unsigned long long ull_max = ULLONG_MAX;
	printf("min of long long: %lld\n", ll_min);
	printf("max of long long: %lld\n", ll_max);
	printf("max of unsigned long long: %llu\n", ull_max);
	return 0;
}
