/*
* Class: Character Class Header
* Description: Protypes the Character class
* 
* Author: David Moore
* Date created: 2-17-2016
* Last modified: 2-17-2016
*
*/

//Header guard start
#ifndef ADD_H
#define ADD_H

//Include statement
#include "Entity.h"

class Character {

//Variables
private:
	/*
	* Atributes akin to SPECIAL from Fallout 
	* DO NOT CHANGE ATTRIBUTES ARRAY DURING CALCULATIONS
	* Change currentAttribute for calculations
	* Attributes subject to change
	*
	* 0 = strength melee damage & equip requiremet 
	* 1 = dexterity slight melee damage & slight crit chance & equip requirement 
	* 2 = constitution health & slight stamina
	* 3 = agility Stamina & initative
	* 4 = perception range weapons & crit chance
	* 5 = intelligence level up speed or loot amount??? (no direct effect on stats
	*/
	int attributes[5];	
	int currentAttributes[5];	

	/*
	* Stats akin to stats from Fallout
	* Base stats calculated from Atributes
	* DO NOT CHANGE DURING CALCULATIONS
	* Change currentStats for calculations
	* Subject to change
	*
	* 0 = melee
	* 1 = ranged
	* 2 = throwing 
	* 3 = medicine
	* 4 = maxWeight
	* 5 = maxStamina
	*/
	int stats[5];
	int currentStats[5];

	/*
	* Equiped items
	* Array position corrisponds to an equip slot
	* 0 = boots | 1 = legs/waist | 2 = chest/arms | 3 = gloves | 
	* 4 = held in left hand | 5 = held in right hand | 6 = head |
	*/
	object* equipedItems[7];
	
//Functions
protected:
	/*
	* Get method for Atributes
	* value of attributeNumber specifies what attribute info to return
	* returns the attribute's value
	*/
	int getAtribute(int attributeNumber);
	
	/*
	* Get method for stats
	* value of statNumber specifies what stat info to return
	* returns the stat's value
	*/
	int getStat(int statNumber);
	
	/*
	* Get method for current attribute values
	* value of attributeNumber specifies what attribute info to return
	* returns the current value of the attribute
	*/
	int getCurrentAttribute(int attributeNumber);
	
	/*
	* Get method for current stat values
	* value of statNumber specifies what stat info to return
	* returns the current value of the attribute
	*/
	int getCurrentStat(int statNumber);	

	/*
	* Sets a new value for a current attribute
	* The attribute will change to the value specified by amount
	* returns the new value of the attribute
	*/
	int setCurrentAttribute(int attributeNumber, int amount);
	
	/*
	* Sets a new value for a current stat
	* The stat will change to the value specified by amount
	* returns the new value of the stat
	*/
	int setCurrentStat(int statNumber, int amount);
	
	/*
	* Gets the currently equiped item
	* returns the item in slotNumber
	* returns null if no item is in slotNumber
	*/
	Item getItem(int slotNumber)
	
	/*
	* Equips the item specified by Item to equip
	* returns true if the item was equiped
	*/
	bool equipItem(Object itemToEquip);

//Constructor
public:
	/*
	* Default constructor
	* Should have no Character objects
	*/
	Chracter();

};
//Header guard end
#endif
