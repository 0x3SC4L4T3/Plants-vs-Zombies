#include "Room.h"

Room::Room(int _id, string _name, string _descrip, int x, int y, int w, int z)
{
	this->m_ID = _id;
	this->m_name = _name;
	this->m_desc = _descrip;
	this->m_direction[0] = x;
	this->m_direction[1] = y;
	this->m_direction[2] = w;
	this->m_direction[3] = z;
}

string Room::GetName()
{
	return this->m_name;
}

int Room::GetID()
{
	return this->m_ID;
}

string Room::GetDesc()
{
	return this->m_desc;
}

int Room::CheckDirection(char myDirection)
{
	if (myDirection == 'n' || myDirection == 'N') {
		return this->m_direction[0];
	}
	else if (myDirection == 'e' || myDirection == 'E') {
		return this->m_direction[1];
	}
	else if (myDirection == 's' || myDirection == 'S') {
		return this->m_direction[2];
	}
	else if( myDirection == 'w' || myDirection == 'W') {
		return this->m_direction[3];
	}
	return -1;
}

void Room::PrintRoom()
{
	cout << "Room Name: " << this->m_name << endl;
	cout << "Room Description: " << endl;
	cout << this->m_desc << endl;
	cout << "Possible exit(s): ";
	if (this->m_direction[0] != -1) {
		cout << "N";
	}
	if (this->m_direction[1] != -1) {
		cout << "E";
	}
	if (this->m_direction[2] != -1) {
		cout << "S";
	}
	if (this->m_direction[3] != -1) {
		cout << "W";
	}
	cout << endl;
}
