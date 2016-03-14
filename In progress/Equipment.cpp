/*
* Class: Equipment Class 
* Description: General outline of game Equipment
*
* Author: Garrett Raab
* Date created: 2-21-2016
* Last Modified: 2-21-2016
*
*/

//Include statements
#include "Object.h"
#include "Equipment.h"

/*
*Contructor for an equipment object
*
*/

Equipment::Equipment(int slot, float damageModifier, float critModifier) {
	this->getSlot(slot);
	this->getDamageModifier(damageModifier);
	this->critModifier = critModifier;
	
}

/*
*This method returns the slot number default to each specific items
*returns as an int
*
*/

int Equipment::getSlot() {
	return slot;
}

/*
*Returns the damage modifier 
*
*/

float Equipment::getDamageModifier() {
	return damageModifier;
}

/*
*Returns the base stamina use
*
*/

int Equipment::getBaseStaminaUse() {
	return baseStaminaUse;
}

/*
*Returns the critMotifier which is used to calculate a critical hit chance
*
*/

float Equipment::getCritModifier() {
	return critModifier;
}

