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
* Parses user input
* Sets firstWord and secondWord to
* 	the first and second words the user typed
* Returns true if the user wants to quit the game
*/
bool parser(std::string& firstWord, std::string& secondWord) {
	std::string input;
	while (true) {
		std::cout << "Input: ";
		std::getline(std::cin, input);
		
		if (input.find(" ") != -1) {
			firstWord = input.substr(0, input.find(" "));
			secondWord = input.substr(input.find(" ")+1);
			break;
		}
		else {
			std::cout << "I don't understand." << std::endl;		
		}
	}
	if (firstWord.compare("quit") == 0 && secondWord.compare("game") == 0) {
		return true;
	}

	return false;
};

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

	//Game Loop
	while (true) {
		//Print description of current room 
		std::cout << level.getRoom(player.getPosX(), player.getPosY()) -> getDescription() << std::endl;

		//Parser for getting user input
	/*
		//Note breaks line getDesciription for some fucking reason
		if (parser(firstWord, secondWord)) {
			break;
		}
	*/
		//Hard code to try and fix
		std::string input;
		while (true) {
			std::cout << "Input: ";
			std::getline(std::cin, input);
		
			if (input.find(" ") != -1) {
				firstWord = input.substr(0, input.find(" "));
				secondWord = input.substr(input.find(" ")+1);
				break;
			}
			else {
				std::cout << "I don't understand." << std::endl;		
			}
		}
		if (firstWord.compare("quit") == 0 && secondWord.compare("game") == 0) {
			break;
		}
		

		//for debug
		std::cout << "First Word: " << firstWord << " | " << "Second Word: " << secondWord << std::endl;
		

	
		//Switch statment for determining what happens
		switch ( string2int(firstWord.c_str()) ) {
			//Cases for movement
			case string2int("go") : 
				std::cout << "Found go!" << std::endl;
				break;
		}
		std::cout << level.getRoom(player.getPosX(), player.getPosY()) -> getDescription() << std::endl;
		std::cout << "Reached end" << std::endl;
	}
	std::cout << "First Word: " << firstWord << " | " << "Second Word: " << secondWord << std::endl;
};
