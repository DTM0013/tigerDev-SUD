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
#ifndef Character_H
#define Character_H

//Include statement
#include "Entity.h"
#include "Object.h"
#include "Equipment.h"
#include <vector>


class Character : public Entity {

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
	int attributes[6];	
	int currentAttributes[6];
	
	/*
	*vector for skills
	*/
	int skillNumber;
	vector<int> skills; //empty vector of ints

	/**
 	* Attributes that will be manipulated in methods then assigned
 	* to their respective indexes in currentAttriubutes array.
 	*/
 	
 	int strengthAttr;
 	int dexterityAttr;
 	int constitutionAttr;
 	int agilAttr;
 	int perceptionAttr;
 	int intellAttr;

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
	int stats[6];
	int currentStats[6];
	
	/*
	* Stats that will be manipulated in methods then assigned
	* to their respective indexes in currentStats array.
	*/
	int meleeStat;
	int rangedStat;
	int throwStat;
	int medStat;
	int maxWeightStat;
	int maxStaminaStat;

	/*
	* Equiped items
	* Array position corrisponds to an equip slot
	* 0 = boots | 1 = legs/waist | 2 = chest/arms | 3 = gloves | 
	* 4 = held in left hand | 5 = held in right hand | 6 = head |
	*/
	Object* equipedItems[7];
	
//Functions
public:
	/*
	* Get method for Atributes
	* value of attributeNumber specifies what attribute info to return
	* returns the attribute's value
	*/
	int getAttribute(int attributeNumber);
	
	/*
	*Get method for Skills
	*value of skillNumber specifies which skill to retern
	*returns the skills value
	*/
	int getSkill(int skillNumber);
	
	/*
	*set method for skills
	*the skill will change to the value specified by amount
	*returns the new value of the skill
	*/
	int setSkill(int skillNumber, int amount);
	
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
	
	/**
	 * Get method for entire currentAttribute array
	 * returns currentAttribute array
	 */
	 int * getCurrentAttributeArray();
	
	/*
	* Get method for current stat values
	* value of statNumber specifies what stat info to return
	* returns the current value of the attribute
	*/
	int getCurrentStat(int statNumber);
	
	/**
	 * Get method for entire currentStat array
	 * Returns currentStat array
	 */
	 int * getCurrentStatArray();

	/*
	* Sets a new value for a current attribute
	* The attribute will change to the value specified by amount
	* returns the new value of the attribute
	*/
	int setCurrentAttribute(int attributeNumber, int amount);
	
	/**
	 * Method sets new currentAttribute aray
	 *returns new currentAttribute array
	 */
	 void setCurrentAttributeArray(int attrArray[]);
	
	/*
	* Sets a new value for a current stat
	* The stat will change to the value specified by amount
	* returns the new value of the stat
	*/
	int setCurrentStat(int statNumber, int amount);
	
	/**
	 * Method sets new currentStat array
	 */
	void setCurrentStatsArray(int statsArray[]);
	
	/**
	 * Method used to distribute attribute points at the beginning
	 * of character creation or when character levels up
	 */
	 void distributeAttributePoints(int attrArray[]);
	 
	 /**
	 * Method used to distribute stat points at the
	 * begininng of character creation or when character levels
	 * up.
	 */
	 void distributeStatPoints(int statsArray[]);
	
	/*
	* Gets the currently equiped item
	* returns the item in slotNumber
	* returns null if no item is in slotNumber
	*/
	Equipment* getEquipedItem(int slotNumber);
	
	/*
	* Equips the item specified by Item to equip
	* returns true if the item was equiped
	*/
	bool equipItem(Equipment itemToEquip);
	
	/*
	*Vector that will store a skill at a certain indexes
	*
	*/
	

};
//Header guard end
#endif
