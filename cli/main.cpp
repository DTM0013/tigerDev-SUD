/*
* Class: Main class
* Descirpition: Used to run the game
*
* Author: David Moore
* Date created: 2-28-16
* Date modified: 2-28-16
*
* Compile using -std=c++11 flag
*/

//Include statments
//#include "../libs/Entity/Entity.cpp"
//#include "../libs/Entity/Character.cpp"
//#include "../libs/Entity/Room.cpp"
#include "../libs/Entity/Player.cpp"
#include "../libs/Database/MapBuilder.cpp"

#include <iostream>
#include <string>
#include <stdlib.h>

//Functions
/*
* hashes strings into ints for use in a switch statement
*/
constexpr unsigned int string2int(const char* str, int h = 0)
{
    // DJB Hash function
    // not my code but can't remember where I got it from
    return !str[h] ? 5381 : (string2int(str, h+1)*33) ^ str[h];
}

int main() {	

	//Build the map
	MapBuilder level = MapBuilder("../data/DebugMap.txt");
	level.buildMap();
	//Read in data from map
	//std::vector< std::vector<Room*> > map = level.getMap();
	
	//Create player object
	Player player = Player();
	player.setPosX(level.getStartRoomXpos());
	player.setPosY(level.getStartRoomYpos());	

	//Get input from user
	std::string firstWord;
	std::string secondWord;

	//Constant variables
	std::string MOVE_FAILURE = "I can't go that way.";

	//Game Loop
	while (true) {
		//Print description of current room 
		std::cout << level.getRoom(player.getPosX(), player.getPosY()) -> getDescription() << std::endl;
		
		//debug
		std::cout << player.getPosX() << " | " << player.getPosY() << std::endl;

		//Parser for getting user input
		std::string input;
		while (true) {
			std::cout << "Input: ";
			std::getline(std::cin, input);
		
			if (input.find(" ") != -1) {
				firstWord = input.substr(0, input.find(" "));
				secondWord = input.substr(input.find(" ")+1);
				
				//Convert to lower case
				for (int i=0; firstWord[i]; i++) firstWord[i] = tolower(firstWord[i]);
				for (int i=0; secondWord[i]; i++) secondWord[i] = tolower(secondWord[i]);			
			
				break;
			}
			else {
				firstWord = input;
				//Convert to lower case
				for (int i=0; firstWord[i]; i++) firstWord[i] = tolower(firstWord[i]);

				secondWord = "none";		
				break;
			}
		}
		if (firstWord.compare("quit") == 0 && secondWord.compare("game") == 0) {
			break;
		}
		
		std::cout << std::endl;

		//for debug
		//std::cout << "First Word: " << firstWord << " | " << "Second Word: " << secondWord << std::endl;
	
		//Switch statment for determining what happens
		switch ( string2int(firstWord.c_str()) ) {
			//Cases for movement
			//North
			case string2int("north") : 
				//Checks to see if it's  valid move
				//Check for walking off map
				if (player.getPosY() == 0) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Check if room to the north
				if (level.getRoom(player.getPosX(), player.getPosY() - 1) == NULL) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Checks passed, so make move
				std::cout << "You walk North" << std::endl;
				player.setPosY(player.getPosY() - 1);
				break;
			//South
			case string2int("south") :
				//Checks to see if it's  valid move
				//Check for walking off map
				if (player.getPosY() == 100) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Check if room to the north
				if (level.getRoom(player.getPosX(), player.getPosY() + 1) == NULL) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Checks passed, so make move
				std::cout << "You walk North" << std::endl;
				player.setPosY(player.getPosY() + 1);
				break;
			//East
			case string2int("east") :
				//Checks to see if it's  valid move
				//Check for walking off map
				if (player.getPosX() == 100) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Check if room to the north
				if (level.getRoom(player.getPosX() + 1, player.getPosY()) == NULL) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Checks passed, so make move
				std::cout << "You walk North" << std::endl;
				player.setPosX(player.getPosX() + 1);
				break;
			//West
			case string2int("west") :
				//Checks to see if it's  valid move
				//Check for walking off map
				if (player.getPosX() == 0) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Check if room to the north
				if (level.getRoom(player.getPosX() - 1, player.getPosY()) == NULL) {
					std::cout << MOVE_FAILURE << std::endl;
					break;
				}
				//Checks passed, so make move
				std::cout << "You walk North" << std::endl;
				player.setPosX(player.getPosX() - 1);
				break;
		}
	}
};
