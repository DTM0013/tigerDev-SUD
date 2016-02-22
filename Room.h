/*
* Class: Room Class Header
* Description: Prototypes the Room class
*
* Author: David Moore
* Date created: 2-17-2016
* Last modified: 2-19-2016
*
*/

//Header guard start
#ifndef Room_H
#define Room_H

//Include statements
#include "Entity.h"
#include <vector>
#include <typeinfo>
#include <string>

class Room : public Entity {

//Variables
private:
	std::vector<Entity*> contents;
	bool hasMonster;
//Functions
protected:
	/*
	* Scans the contents vector to see if there is a monster
	* returns true if a monster is in the room
	*/
	bool containsMonster();
	
	/*
	*
	*
	*/
	void setContainsMonster(bool hasMonster);
	
	/*
	* Scans the contents vector to see if there is an entity
	* 	in the room
	* returns true if it is in the room
	*/
	bool containsEntity();

	/*
	* Scans the contents vector to see if there is an entity
	*	called itemName in the room
	* returns true if it is in the room
	*/
	bool containsEntityName(std::string entityName);

	/*
	* Removes itemName from the contents vector
	* returns true if the object was removed
	*/
	bool removeEntity(std::string entityName);

	/*
	* Adds entityObject to the contents vector
	* returns true if the object was added
	*/
	void addEntity(Entity* entityPointer);

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
	Room(std::string name, std::string description, std::vector<Entity*> contents);

};

//Header guard end
#endif
