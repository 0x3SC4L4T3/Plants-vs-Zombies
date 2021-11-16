#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include <cstring>
Game::Game()
{
	this->m_curRoom = START_ROOM;
	this->m_curZombie = nullptr;
	this->m_myPlant = nullptr;
	this->m_numRests = NUM_RESTS;
	this->m_numSpecial = NUM_SPECIAL;
}

Game::Game(string fileName)
{
	this->m_curRoom = START_ROOM;
	this->m_curZombie = nullptr;
	this->m_myPlant = nullptr;
	this->m_numRests = NUM_RESTS;
	this->m_numSpecial = NUM_SPECIAL;
	LoadMap(fileName);
	StartGame();
}

Game::~Game()
{
	if (this->m_curZombie) {
		delete this->m_curZombie;
		this->m_curZombie = NULL;
	}
	if (this->m_myPlant) {
		delete this->m_myPlant;
		this->m_myPlant = NULL;
	}

	for (auto r : this->m_myMap)
	{
		delete r;
	}
	this->m_myMap.clear();

}

void Game::LoadMap(string fileName)
{
	ifstream infile;
	string room;
	vector <string> tokens;
	char str[2046];
	infile.open(fileName);
	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, room);
			if (room == "") {
				break;
			}
			strcpy(str, room.c_str());
			char* token = strtok(str, "|");
			while (token != NULL)
			{
				tokens.push_back(token);
				token = strtok(NULL, "|");
			}
			this->m_myMap.push_back(new Room(stoi(tokens.at(0)), tokens.at(1), tokens.at(2), stoi(tokens.at(3)), stoi(tokens.at(4)), stoi(tokens.at(5)), stoi(tokens.at(6))));
			tokens.clear();
			room.clear();
		}
	}
	else {
		cout << "unable to load map file\n";
	}
	infile.close();
}

void Game::PlantCreation()
{
	cout << "Plant Name: ";
	string pName;
	cin >> pName;
	cout << "Select a choice: \n";
	cout << "1. Peashooter\n2. Chomper\n3. Sunflower\n4. No class\n";
	int choice = 0;
	while (choice < 1 || choice > 4) {
		cin >> choice;
	}

	if (choice == 1) {
		this->m_myPlant = new Peashooter(pName, PEASHOOTER_HEALTH);
	}
	else if (choice == 2) {
		this->m_myPlant = new Chomper(pName, CHOMPER_HEALTH);
	}
	else if (choice == 3) {
		this->m_myPlant = new Sunflower(pName, SUNFLOWER_HEALTH);
	}
	else {
		this->m_myPlant = new Plant(pName, PLANT_HEALTH);
	}

	this->m_myMap.at(this->m_curRoom)->PrintRoom();
	int possibleZombie = rand() % (101);
	if (possibleZombie <= 25) {
		this->m_curZombie = RandomZombie();
	}
	else {
		cout << "It is peaceful here\n";
	}
}

void Game::StartGame()
{
	PlantCreation();
	Action();
}

void Game::Action()
{
	int option = 0;
	while (option != 6 && (this->m_myPlant->GetHealth() >= 1)) {
		cout << "What would you like to do?\n";
		cout << "1. Look\n2. Move\n3. Attack Zombie\n4. Rest\n5. Stats\n6. Quit\n";
		cin >> option;
		if (option == 1) { 
			this->m_myMap.at(this->m_curRoom)->PrintRoom();
		}
		else if (option == 2) {
			Move();
		}
		else if (option == 3) {
			Attack();
		}
		else if (option == 4) {
			if (this->m_numRests > 0) {
				Rest();
			}else{
				cout << "Not enough Rests remaining. Either move or attack!!\n";
			}
		}
		else if (option == 5) {
			cout << "Name: " << this->m_myPlant->GetName() << endl;
			cout << "HP: " << this->m_myPlant->GetHealth() << endl;
			cout << "Rests: " << this->m_numRests<< endl;
			cout << "Special: " << this->m_numSpecial << endl;
		}
	}

	cout << "Good bye\n";

}

Entity* Game::RandomZombie()
{
	int random = rand() % 4;
	if (random == 1) {
		cout << "A buckethead zombie teaters here with a bucket on his head." << endl;
		return new Buckethead("BucketHead", BUCKETHEAD_HEALTH);
	}
	else if (random == 2) {
		cout << "A dirty imp licks his lips and glares at you.\n";
		return new Imp("Imp", IMP_HEALTH);
	}
	
	cout << "A large zombie stands here wearing khakis with a sign that says ENGINEER.\n";
	return  new Engineer("Engineer", ENGINEER_HEALTH);
}

void Game::Rest()
{
	if (this->m_curRoom >= 0 && this->m_curZombie == nullptr) {
		this->m_numRests -= 1;
		this->m_myPlant->SetHealth(this->m_myPlant->GetHealth() + REST_HEAL);
	}
	else {
		cout << "There's a " << this->m_curZombie->GetName() << " in here!! Either move or attack!\n";
	}
}

void Game::Move()
{
	this->m_curZombie = nullptr;
	char dir;
	bool invalid = true;
	int roomNo;
	while (invalid) {
		cout << "Which direction? ( N E S W): ";
		cin >> dir;
		roomNo = this->m_myMap.at(this->m_curRoom)->CheckDirection(dir);

		if (roomNo == -1) {
			cout << "Invalid Movement\n";
		}
		else {
			invalid = false;
		}
	}
		this->m_curRoom = roomNo;
		this->m_myMap.at(roomNo)->PrintRoom();
		int possibleZombie = rand() % (101);
		if (possibleZombie <= 25) {
			this->m_curZombie = RandomZombie();
		}
		else {
			cout << "It is peaceful here\n";
		}
}

void Game::Attack()
{
	bool defeated = false;
	if (this->m_curZombie == NULL) {
		cout << "No zombie in here!\n";
		return;
	}
	int attackType = 0;
	cout << "1. Normal Attack\n2. Special Attack\n";
	cin >> attackType;
	if (attackType == 1) {
		int attackDone = this->m_myPlant->Attack();
		cout << this->m_myPlant->GetName() << " deals " << attackDone << " point of damage\n";
		int zombieAttack = this->m_curZombie->Attack();
		this->m_myPlant->SetHealth(this->m_myPlant->GetHealth() - (zombieAttack));
		this->m_curZombie->SetHealth(this->m_curZombie->GetHealth() - (attackDone));
		if (this->m_curZombie->GetHealth() < 1) {
			defeated = true;
			cout << "You have defeated the " << this->m_curZombie->GetName() << endl;
			delete this->m_curZombie;
			this->m_curZombie = NULL;
		}
		if (this->m_myPlant->GetHealth() < 1) {
			cout << "You have been defeated by " << this->m_curZombie->GetName() << endl;
			return;
		}
		if (!defeated) {
			cout << this->m_myPlant->GetName() << " health: " << this->m_myPlant->GetHealth() << endl;
			cout << this->m_curZombie->GetName() << " health: " << this->m_curZombie->GetHealth() << endl;
		}

	}
	else if (attackType == 2 && m_numSpecial > 0) {
		this->m_numSpecial--;
		int attackDone = this->m_myPlant->SpecialAttack();
		cout << this->m_myPlant->GetName() << " deals " << attackDone << " point of damage\n";
		int zombieAttack = this->m_curZombie->SpecialAttack();
		cout << this->m_curZombie->GetName() << " deals " << zombieAttack << " point of damage\n";
		this->m_curZombie->SetHealth(this->m_curZombie->GetHealth() - (attackDone));
		this->m_myPlant->SetHealth(this->m_myPlant->GetHealth() - (zombieAttack));
		if (this->m_curZombie->GetHealth() < 1) {
			cout << "You have defeated the " << this->m_curZombie->GetName() << endl;
			delete this->m_curZombie;
			this->m_curZombie = NULL;
			defeated = true;
		}
		if (this->m_myPlant->GetHealth() < 1) {
			cout << "You have been defeated by " << this->m_curZombie->GetName() << endl;
			return;
		}
		if (!defeated) {
			cout << this->m_myPlant->GetName() << " health: " << this->m_myPlant->GetHealth() << endl;
			cout << this->m_curZombie->GetName() << " health: " << this->m_curZombie->GetHealth() << endl;
		}

	}
	else {
		if (m_numSpecial < 1) {
			cout << "No special attacks remaining!!\n";
		}
		else {
			cout << "Invalid Input\n";
		}

	}
}

void Game::Stats()
{
}
