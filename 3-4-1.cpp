#include <iostream>

using namespace std;

struct Rational1
{
	Rational1(int n = 0, int d = 1) : num(n), den(d)
	{
		cout << __func__ << "(" << num << "/" << den << ")" << endl;
	}
	int num; // Numerator(被除数)
	int den; // Denominator(除数)
};

struct Rational2
{
	explicit Rational2(int n = 0, int d = 1) : num(n), den(d)
	{
		cout << __func__ << "(" << num << "/" << den << ")" << endl;
	}
	int num;
	int den;
};

void Display1(Rational1 ra)
{
	cout << "Numerator: " << ra.num << " Denominator: " << ra.den << endl;
}

void Display2(Rational2 ra)
{
	cout << "Numerator: " << ra.num << " Denominator: " << ra.den << endl;
}

int main()
{
	Rational1 r1_1 = 11;
	Rational1 r1_2(12);

	//Rational2 r2_1 = 21; // 无法通过编译
	Rational2 r2_2(22);

	Display1(1);

	//Display2(2); // 无法通过编译
	Display2(Rational2(2));

	return 0;
}

//编译选项: g++ -std=c++11 3-4-1.cpp
