/*
* Class: Skill Header
* Description: Prototypes the skills class
*		Skills are moves used in combat
*		In general attacks
*
* Author: David Moore
* Date created: 3-30-2016
* Date created: 3-30-2016
*
*/

//Header guard start
#ifndef ADD_SKILL
#define ADD_SKILL

//Include statements
#include <string>
#include "Entity/Character.h"

class Skill {

//Variables
private:
	std::string name;
	std::string description;
	int staminaUse;
	int damage;

//Functions
private:
	/*
	* Checks if a skill can be used by User
	* if it can be true; returns true
	* otherwise returns false
	*
	* Automaticly return false if currentStamina is 0
	*/
	bool canBeUsed(Character User);

	/*
	* Uses the skill
	* returns true if the skill was used succesfully
	*
	* Don't forget to apply stamina use of skill
	*
	* (idea below)
	* Skill can be used if currentStamina <  staminaUse
	*	however, accuracy lost linearly
	*/
	bool useSkill(Character User, Character Target);

//Constructor
public:
	/*
	* Defualt Constructor
	*/
	Skill();

	/*
	* General use constructor
	*/
	Skill(std::string name, std::string desciption, int staminaUse, int damage);
};

//Header guard end
#endif
