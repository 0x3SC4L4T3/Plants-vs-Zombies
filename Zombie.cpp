#include "Zombie.h"

Zombie::Zombie() : Entity()
{
}

Zombie::Zombie(string _name, int _health) : Entity (_name, _health)
{
}

int Zombie::Attack()
{
	cout << this->GetName() << " deals 1 point of damage!\n";
	return 1;
}
