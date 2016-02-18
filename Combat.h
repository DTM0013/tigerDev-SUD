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
#ifndef ADD_H
#define ADD_H

//Include statements
#include "Character.h"

class Combat {

//Variables
private:
	bool turn; //true if player's turn (may not need this)
//Functions
private:
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
]
//Constructor
public:
	/*
	* Default Constructor
	*/
	Combat();

	/*
	* General use constructor
	* character1 is usually player
	*
	*  Note: probably need better names than
	*	 character1 & character2
	*/
	Combat(Character character1, Character character2);

};

//Header guard end
#endif
