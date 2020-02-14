#include <iostream>

using namespace std;
using std::cout;

class Info
{
public:
	Info() { InitRest(); }
	Info(int i) : Info() { type = i; }
	Info(char e) : Info() { name = e; }
	void PrintType() { cout << "PrintType: " << type << endl; }

private:
	void InitRest()
	{
		type += 1;
		cout << "InitRest: " << type << endl;
		/* 其他初始化 */
	}
	int type{1};
	char name{'a'};
	// ...
};

int main()
{
	Info info{3};
	info.PrintType();
	return 0;
}
