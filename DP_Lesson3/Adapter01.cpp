#include <iostream>
using namespace std;

class Unique_Weapon_v_1{
	int ammunition;		// боезапас
	int damage;			// урон
public:
	Unique_Weapon_v_1():damage(555) {}
	int getDamage() {
		return damage;
	}
};

class Player_Weapon {
public:
	virtual ~Player_Weapon() {}
	virtual int getDamage(int) = 0;
};

class Unique_Weapon_v_2 : public Player_Weapon{
	int ammunition;			// боезапас
	int	range_of_fire;		// дальность стрельбы
	float penetrating_power;// пробивающая способность
public:
	Unique_Weapon_v_2() :range_of_fire(1000), penetrating_power(4.4f) {}
	int getDamage(int distance) {
		if (distance > range_of_fire)
			return 0;
		return (range_of_fire - distance)*penetrating_power;
	}
};

class Factory {
public:
	virtual Player_Weapon* addWeapon() = 0;
	virtual ~Factory() {}
};

class FactoryUniqueWeapon_v_2 :public Factory {
public:
	Player_Weapon *addWeapon() {
		return new Unique_Weapon_v_2;
	}
};

class FactoryUniqueWeapon_v_1 :public Factory {
public:
	Player_Weapon *addWeapon() {
		return new Adapter(new Unique_Weapon_v_1);
	}
};

class Adapter : public Player_Weapon {
public:
	Adapter(Unique_Weapon_v_1* p) : p_UW1(p) {
	}
	~Adapter() {
		delete p_UW1;
	}
	int getDamage(int distance) {
		if (distance > 500)
			return 0;
		return p_UW1->getDamage()*(distance/255.);
		//return p_UW1->getDamage();
	}
private:
	Unique_Weapon_v_1* p_UW1;
};

int main(){
	setlocale(LC_ALL, "RUSSIAN");
	FactoryUniqueWeapon_v_1 *Weapon_v_1_Factory = new FactoryUniqueWeapon_v_1;
	FactoryUniqueWeapon_v_2 *Weapon_v_2_Factory = new FactoryUniqueWeapon_v_2;

	Player_Weapon* p = Weapon_v_1_Factory->addWeapon();
	int distance = 123;
	cout << "Урон по врагу находящемуся на расстоянии "<< distance <<" метров = " << p->getDamage(distance) << endl;
	delete p;

	p = Weapon_v_2_Factory->addWeapon();
	cout << "Урон по врагу находящемуся на расстоянии " << distance << " метров = " << p->getDamage(distance) << endl;
	delete p;

	cin.get();
}