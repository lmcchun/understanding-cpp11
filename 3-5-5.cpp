#include <iostream>

using namespace std;

const int x = 1024;
const int y = 10;

char a = x; // 收窄, 但可以通过编译
char* b = new char(1024); // 收窄, 但可以通过编译

char c = {x}; // 收窄, 无法通过编译
char d = {y}; // 可以通过编译

unsigned char e{-1}; // 收窄, 无法通过编译
unsigned char j(-1);

float f{7}; // 可以通过编译
int g{2.0f}; // 收窄, 无法通过编译
float* h = new float{1e48};
float i = 1.2L; // 可以通过编译

int main()
{
	cout << (int)j << endl;
	cout << f << endl;
	cout << i << endl;
	return 0;
}

// 编译选项, g++ -std=c++11 3-5-5.cpp
