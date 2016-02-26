/**
* Class: Character Class
* Description: Basic outline for Character
*
* Author: Jonathan Sims
* Date created: 2/23/2016
* Last modified: 2/23/2016
*
*/

// Include Statements
#include "Entity/Entity.h"
#include "Entity/Entity.cpp"
#include "Character.h"
#include <string>
#include <array>

// CONSTANTS
const int DEFAULT_HEALTH = 1000;
const int INITIAL_ATTRIBUTE_POINTS = 20;
const int INITIAL_SKILL_POINTS = 20;


/**
* Default constructor
* Should only be used for debugging
*/

Character::Character() {

};


/**
* Main constructor for Character.cpp
* Set health, current attributes, current skills
*/
Character::Character(std::int maxHealth, std::array<int, 6> attrArray,
                     std::array<int, 6> skillArray) {
   this->Entity::setMaxHealth(DEFAULT_HEALTH);
   this->Entity::setCurrentHealth(DEFAULT_HEALTH);
   this->Character::setCurrentAttributeArray(attrArray);
   this->Character::setCurrentStatArray(skillArray);
};


/**
* Distribute attribute points after character creation.
* I plan to use a switch case for the currentAttr array, switching with int point.
* For whichever point is selected, I plan to increment the respective attribute and
* decrement INITIAL_ATTRIBUTE_POINTS.
*/
int Character::distributeAttributePoints(std::array<int, 6> attributeArray) {
   int point; // case to be switched
   cout << "Choose Attributes:" << endl;
   cout << "Strength: 0" << endl;
   cout << "Dexterity: 1" << endl;
   cout << "Constitution: 2" << endl;
   cout << "Agility: 3" << endl;
   cout << "Perception: 4" << endl;
   cout << "Intelligence: 5" << endl;
   cin >> point;
   do
   {
      switch(point)
      {
         case 0:
            {
               cout << "Point added to Strength" << endl;
               strengthAttr++;
               INITIAL_ATTRIBUTE_POINTS--;
               break;
            }
         case 1:
            {
               cout << "Point added to Dexterity" << endl;
               dexterityAttr++;
               INITIAL_ATTRIBUTE_POINTS--;
               break;
            }
         case 2:
            {
               cout << "Point added to Constitution" << endl;
               constitutionAttr++;
               INITIAL_ATTRIBUTE_POINTS--;
               break;
            }
         case 3:
            {
               cout << "Point added to Agility" << endl;
               agilAttr++;
               INITIAL_ATTRIBUTE_POINTS--;
               break;
            }
         case 4:
            {
               cout << "Point added to Perception" << endl;
               perceptionAttr++;
               INITIAL_ATTRIBUTE_POINTS--;
               break;
            }   
         case 5:
            {
               cout << "Point added to Intelligence" << endl;
               intellAttr++;
               INITIAL_ATTRIBUTE_POINTS--;
               break;
            }
         default:
            {
               cout << "Invalid Input. Must enter a number 0-5" << endl;
               break;
            }   
      }
   }while(INITIAL_ATTRIBUTE_POINTS > 0);
};
