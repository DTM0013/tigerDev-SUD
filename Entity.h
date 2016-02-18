/*
* Class: Entiy Class Header
* Description: Prototypes the Entity class
* 
* Author: David Moore
* Date created: 2-17-2016
* Last modified: 2-17-2016
*
*/

//Header guard start
#ifndef ADD_H
#define ADD_H

class Entity {

//Variables 
private:
	string name;
	string description;
	int maxHealth;
	int currentHealth;

//Functions
protected:
	string getName(); //Returns the entity's name
	string getDescription(); //Returns the entity's description
	int getMaxHealth(); //Returns the entity's max health
	int getCurrentHealth(); //Returns the entity's current health
	
	/*
	* Sets a new value for the entity's currentHealth
	* The current health will change to the value specified by amount
	* Returns the new currentHealth of the entity
	*/
	int setHealth(int amount);
	
	/*
	* Sets the name of the Entity
	* No return value
	*/
	void setName(string name);
	
	/*
	* Sets the description of the Entity
	* No return value
	*/
	void setDescription(string description);

//Constructor
public:
	/*
	* Default Constructor
	* Should have no Entity objects
	*/
	Entity();

};

//Header guard end
#endif
