/*
* Class: Room
* Description: Handles the creation of room objects.
* 
* Author: David Moore
* Date created: 2-19-2016
* Last Modified: 2-20-2016
*
*/

//Include statements
#include "Room.h"

//Constants
const int DEFAULT_HEALTH = 1000;

/*
* Default constructor
* Should not be used unless debugging
*/
Room::Room() {
	this->Entity::setMaxHealth(DEFAULT_HEALTH);
	this->Entity::setCurrentHealth(DEFAULT_HEALTH);
};

/*
* General use Constructor
* Sets name, description, contents, and health
*/
Room::Room(std::string name, std::string description, std::vector<Entity*> contents) {
	this->Entity::setName(name);
	this->setDescription(description);

	this->setMaxHealth(DEFAULT_HEALTH);
	this->setCurrentHealth(DEFAULT_HEALTH);
	
	this->contents = contents;	
};


/*
* Scans the contents vector to see if there is a monster
* returns true if a monster is in the room
*/
bool Room::containsMonster() {
	return hasMonster;
};

void Room::setContainsMonster(bool hasMonster) {
	this->hasMonster = hasMonster;
};

/*
* Scans the contents vector to see if there is an entity
* 	in the room
* returns true if the room contains an entity
*/
bool Room::containsEntity() {
	return contents.empty();
};

/*
* Scans the contents vector to see if there is an entity
* 	with itemName in the room
* returns true if the room contains an entity
*/
bool Room::containsEntityName(std::string entityName) {
	for(int i = 0; i < contents.size(); i++) {
		if (contents[i]->getName().compare(entityName) == 0) {
			return true;
		}
	}
	return false;	
};

/*
* Removes itemName from the contents vector
* returns true if the entity was removed
*
* Note: make sure the entity & pointer is removed
*/
bool Room::removeEntity(std::string entityName) {
	//check if entityName is in the room at all
	if (!containsEntityName(entityName)) {
		return false;
	}
	//remove entityName from room
	for(int i = 0; i < contents.size(); i++) {
		if (contents[i]->getName().compare(entityName) == 0) {
			//free(contents[i]);
			contents.erase(contents.begin() + i);
			return true;
		}
	}
	return false;	
};


/*
* Removes itemName from the contents vector
* returns true if the entity was removed
*
* Note: make sure the entity & pointer is removed
*/
void Room::addEntity(Entity* entityPointer) {
	contents.push_back(entityPointer);
};
