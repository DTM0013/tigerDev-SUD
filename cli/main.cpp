/*
* Class: Main class
* Descirpition: Used to run the game
*
* Author: David Moore
* Date created: 2-28-16
* Date modified: 2-28-16
*
* Compile using -std=c++11 -g flags
*/

//Include statments
//#include "../libs/Entity/Entity.cpp"
#include "../libs/Entity/Character.h"
#include "../libs/Entity/Room.h"
#include "../libs/Entity/Player.h"
#include "../libs/Database/MapBuilder.h"
#include "../libs/Database/SkillBuilder.h"
#include "../libs/Combat/Combat.h"
#include "../libs/Combat/Skill.h"



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
	MapBuilder level = MapBuilder("data/DebugMap.txt");
	level.buildMap();
	
	//Build the Skills list
	SkillBuilder skills = SkillBuilder("data/SkillList.txt");
	skills.buildSkills();
	SkillBuilder* skillsPointer = &skills;
	//Create player object
	Player player = Player();
	player.setPosX(level.getStartRoomXpos());
	player.setPosY(level.getStartRoomYpos());	
	Player* playerPointer = &player;	

	//Temp monster in east room
	level.getRoom(2,1) -> setContainsMonster(true);	

	//Temp player set values
	player.setMaxHealth(500);
	player.setCurrentHealth(500);
	player.addSkill("Swipe");

	//Get input from user
	std::string firstWord;
	std::string secondWord;

	//Constant variables
	std::string MOVE_FAILURE = "I can't go that way.";
	
	//LOGO Screed
	//If true in case this needs to be turned off
	if (true) {
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "--------------PITCH BLACK-------------------" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "--------------------------------------------" << std::endl << std::endl;
	}
	
	//Intro / plot setup
	//If ture in case this needs to be turned off
	if(true) {
		std::cout << "You walk into the governmental office of your small, home town." << std::endl;
		std::cout << "You are short on money and have decided to take up mercenary work." << std::endl;
		std::cout << "So, you walk up to the front desk and grab a mercenaty identification card." << std::endl;
		std::cout << "This magical item stores all information about its owner, as well as" << std::endl;
		std::cout << "\tallowing its owner to take up mercenary work." << std::endl;
		std::cout << "However before accepting any jobs, you need to update the information on your card" << std::endl;
	}

	//Character Creation
	//If true for debug in case this needs to be turned off
	if (true) {
		std::cout << "Please fill out the information on your mercenary card." << std::endl;

		std::string input;
		std::cout << "Name: ";
		std::getline(std::cin, input);
		player.setName(input);
		std::cout << std::endl;

		std::cout << "Describe yourself: ";
		std::getline(std::cin, input);
		player.setDescription(input);
		std::cout << std::endl;

		std::cout << "Rank your various attributes: " << std::endl;
		int points = 26;
		int attributes[6] = {1,1,1,1,1,1};
		int stats[6] = {1,1,1,1,1,1};
		while (points > 0) {
			std::cout << "Strength: " << attributes[0] << "- determines how hard your melee attacks hit, and how you handle heavy weapons." << std::endl;
			std::cout << "Dexterity: " << attributes[1] << " - determines how hard your melee attacks hit, and how you handle unique weapons." << std::endl;
			std::cout << "Constitution: " << attributes [2]<< " - determines how resistant you are to damage, and how quickly you recover stamina." << std::endl;
			std::cout << "Agility: " << attributes[3] << " - determines how much stamina you have, and how much you can attack per turn." << std::endl;
			std::cout << "Perception: "<< attributes[4] << " - determines how much damage ranged and thrown weapons do." << std::endl;
			std::cout << "Intelligence: " << attributes[5] << " - determines how much well you can pack and thus carry, as well as medical profeciany." << std::endl << std::endl;

			std::cout << "Type in the name of the stat you would like to increase." << std::endl;
			std::cout << "Remaining Attribute points to distribute: " << points << std::endl;
			std::cout << "Stat to increase by one: ";
			std::getline(std::cin, input);
			//Convert to lower case
			for (int i=0; input[i]; i++) input[i] = tolower(input[i]);

			switch (string2int(input.c_str())) {
				case string2int("str") :
				case string2int("strength") :
					attributes[0]++;
					points--;
					break;
				case string2int("dex"):
				case string2int("dexterity") :
					attributes[1]++;
					points--;
					break;
				case string2int("con") :
				case string2int("constitution") :
					points--;
					attributes[2]++;
					break;
				case string2int("agi") :
				case string2int("agility") :
					points--;
					attributes[3]++;
					break;
				case string2int("per") :
				case string2int("perception") :
					points--;
					attributes[4]++;
					break;
				case string2int("int") :
				case string2int("intelligence") :
					points--;
					attributes[5]++;
					break;
				default :
					std::cout << "I don't understand." << std::endl;
			}
			std::cout << std::endl;
		}
		player.distributeAttributePoints(attributes);

		//Calculate stats based off of attributes and then tag 1 or 2 stats
		//Max Health
		player.setMaxHealth(attributes[2] * 100);
		player.setCurrentHealth(attributes[2] * 100);
		//Melee stat
		stats[0] = (attributes[0] * 30 + attributes[1] * 20);
		//Ranged stat
		stats[1] = (attributes[4] * 30);
		//Throwing stat
		stats[2] = (attributes[4] * 30);
		//Medical
		stats[3] = (attributes[5] * 50);
		//max weight
		stats[4] = (attributes[5] * 15);
		//max stamina
		stats[5] = (attributes[3] * 10);
		player.distributeStatPoints(stats);

		//Pick 2 skills (rest and heal as default)
		std::cout << "You flip the ID card over to fill out what skills you have." << std::endl;
		std::cout << "You already know Rest and Heal by default." << std::endl;
		std::cout << "You know that you must learn skills by seeing them." << std::endl;
		std::cout << "Thankfully, you saw a mercenary practicing Swipe and Crush earlier." << std::endl;
		std::cout << "Choose two skills that you can use in combat." << std::endl << std::endl;
		int skillsToAdd = 2;
		while (skillsToAdd > 0) {
			std::cout << "Input: ";
			std::getline(std::cin, input);
			//Convert to lower case
			for (int i=0; input[i]; i++) input[i] = tolower(input[i]);
			if (skills.getSkill(input) != NULL) {
				player.addSkill(input);
				skillsToAdd--;
			}
			else {
				std::cout << "That is not a skill." << std::endl;
			}
			std::cout << std::endl;
		}
		
		//Rest of the intro
		std::cout << "Now that you have finished filling out your ID Card, you go to the job board." << std::endl;
		std::cout << "You notice a job for clearing out a nearby dungeon." << std::endl;
		std::cout << "The job sounds easy enough, so you accept the job." << std::endl;
		std::cout << "You arrive at the dungeon's entrance that afternoon." << std::endl;
		std::cout << "You slowly make your way into the pitch black." << std::endl << std::endl;
	}

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
			//Case for displaying status
			case string2int("status") :
				std::cout << "Name: " << player.getName() << std::endl;
				std::cout << "Description: " << player.getDescription() << std::endl  << std::endl;
				std::cout << "Health: " << player.getCurrentHealth() << "/" << player.getMaxHealth() << std::endl;
				std::cout << "Stamina: " << player.getCurrentStat(5) << "/" << player.getStat(5) << std::endl;
				std::cout << "Weight: " << player.getCurrentStat(4) << "/" << player.getStat(4) << std::endl << std::endl;
				std::cout << "Melee: " << player.getStat(0) << " Ranged: " << player.getStat(1) << std::endl;
				std::cout << "Throw: " << player.getStat(2) << " Medicine: " << player.getStat(3) << std::endl << std::endl;
				break;
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
				std::cout << "You walk South" << std::endl;
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
				std::cout << "You walk East" << std::endl;
				player.setPosX(player.getPosX() + 1);

				//Check if there is a monster in the room, and see what to do
				if (level.getRoom(player.getPosX(), player.getPosY()) -> containsMonster()) {
					//Change target to thing in the room instead of making player kill themselves
					Combat fight = Combat(playerPointer, playerPointer, player.getPosX() - 1, player.getPosY(), skillsPointer);
					//If the player wins the fight then set the room to not contain a monster
					if (fight.handleCombat()) {
						level.getRoom(player.getPosX(), player.getPosY()) -> setContainsMonster(false);	
					}
				}

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
				std::cout << "You walk West" << std::endl;
				player.setPosX(player.getPosX() - 1);
				break;

			//In case the input is not understood
			default: 
				std::cout << "I don't understand what I should be doing?" << std::endl;
				break;
		}
	}
};
