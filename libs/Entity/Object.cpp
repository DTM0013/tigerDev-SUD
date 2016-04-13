/*
* Class: Object Class 
* Description: General outline of the available objects
* 
* Author: Garrett Raab
* Date created: 2-21-2016
* Last modified: 2-21-2016
* 
*/

//include statements
#include "Object.h"

/*
*Returns true if an object is able to be picked up
*
*/

bool Object::getPickUpable() {
	return pickUpable;
}

/*
*Returns true if an item can be used
*
*/

bool Object::getUsable() {
	return usable;
}

/*
*Allows us to set which items are able to be picked up 
*returns true if the item was picked up
*/

void Object::setPickUpable(bool pickUpable) {
	
}

/*
*Allows us to determine whether or not an object is usable
*Returns true if the object is usable
*
*/

void Object::setUsable (bool setUsable) {
	
}

