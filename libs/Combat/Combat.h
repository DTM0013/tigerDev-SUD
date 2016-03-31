/*
* Class: Combat Header
* Description: Prototypes the combat class
* 		Handles combat between characters
*
* Author: David Moore
* Date created: 2-17-2016
* Last modified: 2-17-2016
*
* Note: I am confused on how this should work
*/

//Header guard start
#ifndef COMBAT_H
#define COMBAT_H

//Include statements
#include "../Entity/Character.cpp"
#include "../Entity/Player.cpp"

class Combat {

//Variables
private:
	Player player;
	Character target;
	int previousPosX;
	int previousPosY;
	bool turn; //true if player's turn (may not need this)
//Functions
public:
	/*
	* Checks if the player wants to enter combat
	* returns true if the player wants to enter combat
	*/
	bool combatCheck();

	/*
	* Function call that does combat
	* Note: essentially a while loop until one
	*	character is dead or player retreats
	*/
	void handleCombat();

//Constructor
public:
	/*
	* Default Constructor
	*/
	Combat();

	/*
	* General use constructor
	*/
	Combat(Player player, Character target, int previousPosX, int previousPosY);

};

//Header guard end
#endif
