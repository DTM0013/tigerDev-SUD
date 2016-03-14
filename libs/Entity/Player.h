/*
* Class: Player Class Header
* Description: Prototypes the Player Class
*
* Author: David Moore
* Date created: 3-05-2016
* Last modified: 3-05-2016
*
*/

//Header guard start
#ifndef Player_H
#define Player_H

//Include statment
#include "Character.h"

class Player {

//Variables
private:
	int playerPosX;
	int playerPosY;
//Functions
public:
	//Getters and setters for current player pos
	int getPosX();
	int getPosY();
	void setPosX(int posX);
	void setPosY(int posY);

};
//Header guards end
#endif
