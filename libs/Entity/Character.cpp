/**
* Class: Character Class
* Description: Basic outline for Character
*
* Author: Jonathan Sims & David Moore
* Date created: 2/23/2016
* Last modified: 2/28/2016
*
*/

// Include Statements
#include "Entity.h"
#include "Entity.cpp"
#include "Character.h"
#include <string>

/**
* Default constructor
* Should only be used for debugging
*/

Character::Character() {

};

/*
* Get method for base Attributes
* Returns the Base attribute's value
*/
int Character::getAttribute(int attributeNumber) {
	return attributes[attributeNumber];
};

/*
* Get method for base stats
* Returns the base stat's value
*/
int Character::getStat(int statNumber) {
	return stats[statNumber];
};

/*
* Get method for current Attributes
* Returns the current attribute's value
*/
int Character::getCurrentAttribute(int attributeNumber) {
	return currentAttributes[attributeNumber];
};

/*
* Get method for current stats
* Returns the stat's current value
*/
int Character::getCurrentStat(int statNumber) {
	return currentStats[statNumber];
};

/*
* Get method for the array of attributes
*/
int * Character::getCurrentAttributeArray() {
	return currentAttributes;
};

/*
* Get method for the array of stats 
*/
int * Character::getCurrentStatArray() {
	return currentStats;
};

/*
* Sets a new value for the current attribute
* returns the new value of the Attribute
*/
int Character::setCurrentAttribute(int attributeNumber, int amount) {
	currentAttributes[attributeNumber] = amount;
	return currentAttributes[attributeNumber];
};

/*
* Sets a new value for the current stat
* returns the new value of the stat
*/
int Character::setCurrentStat(int statNumber, int amount) {
	currentStats[statNumber] = amount;
	return currentStats[statNumber];
};

/*
* Set current attribute array
*/
void Character::setCurrentAttributeArray(int attrArray[]) {
	for (int i = 0; i < 6; i++) {
		currentAttributes[i] = attrArray[i];
	}
};

/*
* Set current attribute array
*/
void Character::setCurrentStatsArray(int statsArray[]) {
	for (int i = 0; i < 6; i++) {
		currentStats[i] = statsArray[i];
	}
};

/*
* Used during character creation
*/
void Character::distributeAttributePoints(int attrArray[]) {
	for (int i = 0; i < 6; i++) {
		attributes[i] = attrArray[i];
		currentAttributes[i] = attrArray[i];	
	}
};

/*
* Used during character creation
*/
void Character::distributeStatPoints(int statsArray[]) {
	for (int i = 0; i < 6; i++) {
		stats[i] = statsArray[i];
		currentStats[i] = statsArray[i];	
	}
};

/*
* Gets the item currently equiped in slotNumber
* returns the object pointer or null
*
Object* Character::getEquipedItem(int slotNumber) {
	return equipedItems[slotNumber];
};

/*
* Equips the item specified by itemToEquip
* returns true if the item was equiped
*/
bool Character::equipItem(Equipment itemToEquip) {
	int tempSlot = itemToEquip.getSlot();
	if (equipedItems[tempSlot] == 0) {
		*equipedItems[tempSlot] = itemToEquip;
		return true;
	}
	return false;
};
