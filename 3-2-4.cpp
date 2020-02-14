class Info
{
public:
	Info() : Info(1, 'a') {}
	Info(int i) : Info(i, 'a') {}
	Info(char e) : Info(1, e) {}

private:
	Info(int i, char e) : type(i), name(e) { /* 其他初始化 */ }
	int type;
	char name;
	// ...
};
