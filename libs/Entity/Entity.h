/*
* Class: Entity Class Header
* Description: Prototypes the Entity class
* 
* Author: David Moore
* Date created: 2-17-2016
* Last modified: 2-20-2016
*
*/

//Header guard start
#ifndef Entity_H
#define Entity_H

//Include statements
#include <string>

class Entity {

//Variables 
private:
	std::string name;
	std::string description;
	int maxHealth;
	int currentHealth;

//Functions
public:
	std::string getName(); //Returns the entity's name
	std::string getDescription(); //Returns the entity's description
	int getMaxHealth(); //Returns the entity's max health
	int getCurrentHealth(); //Returns the entity's current health
	
	/*
	* Sets a new value for the entity's currentHealth
	* The max health will change to the value specified by amount
	* Returns the new maxHealth of the entity
	*/
	int setMaxHealth(int amount);
	

	/*
	* Sets a new value for the entity's currentHealth
	* The current health will change to the value specified by amount
	* Returns the new currentHealth of the entity
	*/
	int setCurrentHealth(int amount);
	
	/*
	* Sets the name of the Entity
	* No return value
	*/
	void setName(std::string name);
	
	/*
	* Sets the description of the Entity
	* No return value
	*/
	void setDescription(std::string description);
};

//Header guard end
#endif
