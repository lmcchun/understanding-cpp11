#include <string>
#include <iostream>

using namespace std;

const char* hello() { return __func__; }

const char* world() { return __func__; }

// 在参数声明时, __func__ 还没有被定义
// predefined identifier is only valid inside function
//void FuncFail(string func_name = __func__) {}

int main()
{
	cout << hello() << ", " << world() << endl;
	return 0;
}
