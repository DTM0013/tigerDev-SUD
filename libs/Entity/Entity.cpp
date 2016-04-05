/*
* Class: Entity Class
* Description: General outline of game Entities
*
* Author: David Moore
* Date created: 2-20-1016
* Last modified:2-20-2016
*
*/

//Include statements
#include "Entity.h"

/*
* Returns the entity's name
*/
std::string Entity::getName() {
	return name;
};

/*
* Returns the entity's description
*/
std::string Entity::getDescription() {
	return description;
};

/*
* Returns the entity's max health
*/
int Entity::getMaxHealth() {
	return maxHealth;
};

/*
* Returns the entity's current health
*/
int Entity::getCurrentHealth() {
	return currentHealth;
};

/*
* Sets a new value for the entity's max health
* The max health will change to the value specified by amount
* Returns the new maxHealth of the entity
*/
int Entity::setMaxHealth(int amount) {
	maxHealth = amount;
	return maxHealth;
};

/*
* Sets a new value for the entity's current health
* The current health will change to the value specified by amount
* returns the new current health of the entity
*/
int Entity::setCurrentHealth(int amount) {
	currentHealth = amount;
	return currentHealth;
};

/*
* Sets the name of the entity
* no return value
*/
void Entity::setName(std::string name) {
	this->name = name;
};

/*
* Sets the description of the entity
* No return value
*/
void Entity::setDescription(std::string description) {
	this->description = description;
};

