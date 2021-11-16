#ifndef _PEASHOOTER_H_
#define _PEASHOOTER_H_

#include "Plant.h"

//The traditional plant that shoots its own peas. Yikes
class Peashooter: public Plant {
 public:
  // Name: Peashooter() - Default Constructor
  // Description: Creates a new peashooter
  // Preconditions: None
  // Postconditions: Can create a peashooter
  Peashooter();
  // Name: Peashooter(string name, int hp)
  // Description: Creates a new peashooter
  // Preconditions: None
  // Postconditions: Can create a peashooter
  Peashooter(string, int);
  // Name: ~Peashooter - Virtual Destructor
  // Description: Makes sure everything in child class is deallocated
  // Preconditions: None
  // Postconditions: Everything dynamically allocated is deallocated
  ~Peashooter();
  // Name: SpecialAttack
  // Description: Defines the Peashooter's special attack
  // Preconditions: None
  // Postconditions: Returns damage from special attack
  int SpecialAttack();
};
#endif
