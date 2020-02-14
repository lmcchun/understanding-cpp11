#include <iostream>

using namespace std;

void Throw() { throw 1; }

void NoBlockThrow() { Throw(); }

void BlockThrow() noexcept { Throw(); }

int main()
{
	try
	{
		Throw();
	}
	catch(...)
	{
		cout << "Found throw." << endl;
	}

	try
	{
		NoBlockThrow();
	}
	catch(...)
	{
		cout << "Throw is not blocked." << endl;
	}

	try
	{
		BlockThrow(); // terminate called after throwing an instance of 'int'
	}
	catch(...)
	{
		cout << "Found throw 1. " << endl;
	}

	return 0;
}
