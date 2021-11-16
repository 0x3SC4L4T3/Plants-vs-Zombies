#include "Peashooter.h"

Peashooter::Peashooter() : Plant()
{
}

Peashooter::Peashooter(string _name, int _health) : Plant (_name, _health)
{
}

Peashooter::~Peashooter()
{
}

int Peashooter::SpecialAttack()
{
	cout << "Shooter spins up doing GATLING DAMAGE\n";
	int damage = rand() % (12 - 3 + 1) + 3;
	return damage;
}
