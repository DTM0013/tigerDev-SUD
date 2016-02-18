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
#ifndef ADD_H
#define ADD_H

//Include statement
#include "Object.h"

class Equipment {

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
protected:
	int getSlot();
	float getDamageModifier();
	int getBaseStaminaUse();
	float getCritModifier;
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
