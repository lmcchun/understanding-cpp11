#include <vector>
#include <string>

using namespace std;

enum Gender {boy, girl};

class People
{
public:
	People(initializer_list<pair<string, Gender>> l) // initializer_list 的构造函数
	{
		auto i = l.begin();
		for (; i != l.end(); ++i)
		{
			data.push_back(*i);
		}
	}

private:
	vector<pair<string, Gender>> data;
};

People ship2012 = {{"Garfield", boy}, {"HelloKitty", girl}};

// 编译选项: g++ -c -std=c++11 3-5-2.cpp
