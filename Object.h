/*
* Class: Object Class Header
* Description: Prototypes the Entity class
* 
* Author: David Moore
* Date created: 2-17-2016
* Last modified: 2-17-2016
* 
*/

//Header guard start:
#ifndef ADD_H
#define ADD_H

//Include statement
#include "Entity.h"

class Object {

//Variables
private:
	bool pickUpable; //If the item can be picked up off the ground
	bool usable; //If the item can be used

//Functions
protected:
	bool getPickUpable(); //returns true if the item can be picked up
	bool getUsable(); //returns true if the item can be used
	void setPickUpable(bool status);
	void setUsable(bool status);

};

//Header guard end
#endif
