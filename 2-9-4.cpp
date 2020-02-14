template<typename T>
class DefenderT
{
	friend T;
public:
	void Defence(int x, int y) {}
	void Tackle(int x, int y) {}

private:
	int pos_x = 15;
	int pos_y = 0;
	int speed = 2;
	int stamina = 120;
};

template<typename T>
class AttackerT
{
	friend T;
public:
	void Move(int x, int y) {}
	void SpeedUp(float ratio) {}

private:
	int pos_x = 0;
	int pos_y = -30;
	int speed = 3;
	int stamina = 100;
};

using Defender = DefenderT<int>; // 普通的类定义, 使用 int 做参数
using Attacker = AttackerT<int>;

#ifdef UNIT_TEST
class Validator;

using DefenderTest = DefenderT<Validator>; // 测试专用的定义, Validator 类成为友元
using AttackerTest = AttackerT<Validator>;

class Validator
{
public:
	void Validate(int x, int y, DefenderTest& d) {}
	void Validate(int x, int y, AttackerTest& a) {}
};

int main()
{
	DefenderTest d;
	AttackerTest a;
	a.Move(15, 30);
	d.Defence(15, 30);
	a.SpeedUp(1.5f);
	d.Defence(15, 30);
	Validator v;
	v.Validate(7, 0, d);
	v.Validate(1, -10, a);
	return 0;
}
#endif
