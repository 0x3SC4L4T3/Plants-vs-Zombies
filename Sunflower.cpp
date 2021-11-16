#include "Sunflower.h"

Sunflower::Sunflower() : Plant()
{
}

Sunflower::Sunflower(string _name, int _health) : Plant(_name, _health)
{
}

Sunflower::~Sunflower()
{
}

int Sunflower::SpecialAttack()
{
	cout << "Sunflower uses a high beam turret - **SUNBEAM**\n";
	int damage = rand() % (8 - 1 + 1) + 1;
	return damage;
}
