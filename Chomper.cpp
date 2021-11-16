#include "Chomper.h"

Chomper::Chomper() : Plant()
{
}

Chomper::Chomper(string _name, int _health) : Plant(_name, _health)
{

}

Chomper::~Chomper()
{
}

int Chomper::SpecialAttack()
{
	cout << "Chomper performs a sneak attack! CHOMP\n";
	int damage = rand() % (12 - 2 + 1) + 2;
	return damage;
}
