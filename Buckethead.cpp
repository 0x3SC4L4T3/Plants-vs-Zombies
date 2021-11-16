#include "Buckethead.h"

Buckethead::Buckethead(): Zombie()
{
}

Buckethead::Buckethead(string _name, int _health): Zombie(_name, _health)
{
}

int Buckethead::SpecialAttack()
{
    cout << "buckethead throws its bucket at you!\n";
    return 1;
}
