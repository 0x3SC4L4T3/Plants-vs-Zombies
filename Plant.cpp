#include "Plant.h"

Plant::Plant() : Entity()
{

}

Plant::Plant(string _name, int _health) : Entity(_name, _health)
{
}

Plant::~Plant()
{
}

int Plant::Attack()
{
	int damage = rand() % (12 - 2 + 1) + 2;
	cout << this->GetName() << " attacks dealing " << damage << "\n";
	return damage;
}

int Plant::SpecialAttack()
{
	cout << "Plants does not have special attack\n";
	return 0;
}
