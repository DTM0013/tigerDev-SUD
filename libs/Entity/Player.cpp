/*
* Class: Player Class Header
* Description: Prototypes the Player Class
*
* Author: David Moore
* Date created: 3-05-2016
* Last modified: 3-05-2016
*
*/

//Include statment
#include "Player.h"

//Getters for current player position
int Player::getPosX() {
	return playerPosX;
};

int Player::getPosY() {
	return playerPosY;
};

//Setters for current player position
void Player::setPosX(int posX) {
	playerPosX = posX;
};

void Player::setPosY(int posY) {
	playerPosY = posY;
};
