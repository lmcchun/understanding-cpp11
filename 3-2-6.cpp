#include <list>
#include <vector>
#include <deque>

using namespace std;

class TDConstructed
{
public:
	TDConstructed(vector<short>& v) : TDConstructed(v.begin(), v.end()) {}
	TDConstructed(deque<int>& d) : TDConstructed(d.begin(), d.end()) {}

private:
	template<class T> TDConstructed(T first, T last) : l(first, last) {}
	list<int> l;
};
