#include "Imp.h"

Imp::Imp() : Zombie()
{
}

Imp::Imp(string _name, int _health) : Zombie(_name, _health)
{
}

int Imp::SpecialAttack()
{
	cout << "Imp blasts you with their Impkata attack!\n";
	return 4;
}
