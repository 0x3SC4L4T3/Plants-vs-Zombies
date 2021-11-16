#include "Entity.h"

Entity::Entity()
{
	this->m_health = -1;
	this->m_level = -1;
	this->m_name = "";

}

Entity::Entity(string _name, int _health)
{
	this->m_name = _name;
	this->m_health = _health;
}

Entity::~Entity()
{

}

string Entity::GetName()
{
	return this->m_name;
}

int Entity::GetHealth()
{
	return this->m_health;
}

void Entity::SetName(string _name)
{
	this->m_name = _name;
}

void Entity::SetHealth(int _health)
{
	this->m_health = _health;
}

ostream& operator<<(ostream& out, Entity& E)
{
	// TODO: insert return statement here
	out << "Name: " << E.m_name << endl;
	out << "Hp: " << E.m_health << endl;

	return out;
}
