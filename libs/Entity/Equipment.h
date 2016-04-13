/*
* Class: Equipment Class Header
* Description: Prototypes the Equipment Class
*
* Author: David Moore
* Date created: 2-17-2016
* Last Modified: 2-17-2016
*
*/

//Header guard start
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

//Include statement
#include "Object.h"

class Equipment : public Object {

//Variables
private: 
	int slot; //slot occupied when item is equiped; see character class

	/*
	* Used to calc damage bonus for weapons
	* Used to calc damage reduction for armor 
	*/
	float damageModifier;

	/*
	* Used to calc stamina used for an attack
	*/
	int baseStaminaUse;

	/*
	* Used to calculate critical hit chance
	* Could be % change or change base hit chance
	*/
	float critModifier; 

//Funnctions
public:
	float getDamageModifier();
	int getBaseStaminaUse();
	float getCritModifier();
	int getSlot();
//Constructor
public:
	/*
	* Default constructor
	* only use for debug
	*/
	Equipment();

	/* 
	* General use Constructor
	* Sets pickUpable and usable to true
	*/
	Equipment(int slot, float damageModifier, float critModifier);

};

//Header guard end
#endif
