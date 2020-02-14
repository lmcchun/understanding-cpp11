class P;

template<typename T>
class People
{
	friend T;
};

People<P> PP; // 类型 P 在这里是 People 类型的友元
People<int> Pi; // 对于 int 类型模板参数, 友元声明被忽略
