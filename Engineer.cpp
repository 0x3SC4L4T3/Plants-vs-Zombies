#include "Engineer.h"

Engineer::Engineer() : Zombie()
{
}

Engineer::Engineer(string _name, int _health) : Zombie (_name, _health)
{
}

int Engineer::SpecialAttack()
{
	cout << "Engineer blasts you with their steam blaster!\n";
	return 2;
}
