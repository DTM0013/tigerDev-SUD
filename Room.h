/*
* Class: Room Class Header
* Description: Prototypes the Room class
*
* Author: David Moore
* Date created: 2-17-2016
* Last modified: 2-17-2016
*
*/

//Header guard start
#ifndef ADD_H
#define ADD_H

//Include statements
#include "Entity.h"
#include <vector>
// #include <typeinfo> (may need to include this)

class Room {

//Variables
private:
	vector<Entity*> contents;
//Functions
protected:
	/*
	* Scans the contents vector to see if there is a monster
	* returns true if a monster is in the room
	*/
	bool containsMonster();
	
	/*
	* Scans the contents vector to see if there is an entity
	*	with itemName as its name
	* returns true if it is in the room
	*/
	bool containsEntity(string entityName);

	/*
	* Removes itemName from the contents vector
	* returns true if the object was removed
	*/
	bool removeEntity(string entityName);

	/*
	* Adds entityObject to the contents vector
	* returns true if the object was added
	*/
	bool addEntity(Entity entityObject);

//Constructor
public:
	/*
	* Default constructor
	* Should not be used unless debugging
	*/
	Room();

	/*
	* General use Constructor
	* Sets name, description, and contents
	* maxHealth & currentHealth should be initilized to a large default value
	*	that way nobody takes the time attack the room and  see what happens 
	*	when a room's health goes to zero. (right now nothing)
	*/
	Room(string name, string description, vector<Entity*> contents);

};

//Header guard end
#endif
