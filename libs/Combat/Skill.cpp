/*
* Class: Skill
* Description: Implements the skills class
*		Skills are combat moves
*		most cases general attacks (support only this for now)
*
* Author: David Moore
* Date created: 3-30-2016
* Dare created: 3-30-2016
*
*/

//Include Statements
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Skill.h"
#include "../Entity/Character.cpp"

//General use Constructor
Skill::Skill(std::string name, std::string description, int staminaUse, int damage) {
	this -> name = name;
	this -> description = description;
	this -> staminaUse = staminaUse;
	this -> damage = damage;
};

/*
* Checks if the skill can be used
* returns true if the skill can be used
*
* returns false automaitcally if stamina is 0
*/
bool Skill::canBeUsed(Character User) {
	if (User.getCurrentStat(5) == 0) {
		return false; //if stamina is 0 then false
	}
	return true;
};

/*
* Uses the skill
* returns true if the skill was used
*/
bool Skill::useSkill(Character User, Character Target) {
	//Check if the skill can be used first
	if (canBeUsed(User) == false) {
		return false;
	}
	
	//Determine Accuracy
	float accuracy = 100;
	if (User.getCurrentStat(5) < staminaUse) {
		accuracy = User.getCurrentStat(5) / staminaUse * 100;
	}

	//Apply stamina cost
	User.setCurrentStat(5, (User.getCurrentStat(5) - staminaUse));
	if (User.getCurrentStat(5) < 0) {
		User.setCurrentStat(5, 0);
	}	

	//Determine hit
	srand (time(NULL));
	if ((rand() % 100) > accuracy) {
		//Miss
		return false;
	}

	//Apply Damage to target
	//If user has a weapon
	if (User.getEquipedItem(5) != NULL) {
		Target.setCurrentHealth(Target.getCurrentHealth() - (damage + damage * User.getEquipedItem(5)->getDamageModifier()));
	}
	//User does not have a weapon
	else {
		Target.setCurrentHealth(Target.getCurrentHealth() - damage);
	}
	return true;
};
