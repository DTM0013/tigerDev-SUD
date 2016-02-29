/*
* Class: Main class
* Descirpition: Used to run the game
*
* Author: David Moore
* Date created: 2-28-16
* Date modified: 2-28-16
*
*/

//Include statments
//#include "../libs/Entity/Entity.cpp"
//#include "../libs/Entity/Character.cpp"
//#include "../libs/Entity/Room.cpp"
#include "../libs/Database/MapBuilder.cpp"

#include <iostream>
#include <string>

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

int main() {

	//Build the map
	MapBuilder level = MapBuilder("../data/DebugMap.txt");
	level.buildMap();
	
	//Get input from user
	std::string firstWord;
	std::string secondWord;

	//Game Loop
	while (true) {
		if (parser(firstWord, secondWord)) {
			break;
		}
		std::cout << "First Word: " << firstWord << " | " << "Second Word: " << secondWord << std::endl;
	}
	std::cout << "First Word: " << firstWord << " | " << "Second Word: " << secondWord << std::endl;
};
