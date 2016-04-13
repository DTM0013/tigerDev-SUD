/*
* Class: Combat
* Desciription: This class handles combat between characters
*		(will be expanded for all entities in the future)
*
* Author: David Moore
* Date created: 3-26-2016
* Last modified: 3-26-2016
*
*/

// Include Statements
#include "Combat.h"

#include <iostream>
#include <string>
#include <stdlib.h>

// Default Constructor
Combat::Combat(Player* player, Character* target, int previousPosX, int previousPosY, SkillBuilder* skills) {
	this -> player = player;
	this -> target = target;
	this -> previousPosX = previousPosX;
	this -> previousPosY = previousPosY;
	this -> skills = skills;
};

/*
* Method for processing combat 
*/
bool Combat::handleCombat() {
	
	std::string input;
	
	//Initial check to see if player wants to enter combat
	std::cout << "You notice that you have a chance to run away" << std::endl;
	std::cout << "\tbefore the enemy notices you. Do you attack" << std::endl;
	std::cout << "\tor do you retreat." << std::endl <<std::endl;
	
	while (true) {
		//get user input for check
		std::cout << "Input: ";
		getline(std::cin, input);
		//convert to lower case
		for (int i=0; input[i]; i++) input[i] = tolower(input[i]);
		
		if (input.compare("retreat") == 0) {
			std::cout << "You decide to run back the way you came" << std::endl;
			player -> setPosX(previousPosX);
			player -> setPosY(previousPosY);
			return false;
		}
		else if (input.compare("attack") == 0) {
			std::cout << "You decide to attack." << std::endl;
			break;
		}
		else {
			std::cout << "I don't understand." << std::endl;
		}
	}	

	/*
	* ----------Combat Loop--------
	* PreLoop
	* Check who goes first
	* Basic loop -------------------------------
	* Player uses skill, item, or runs
	* Monster uses skill
	* repeat until dead
	*
	* (for now only player attacks)
	*/
	while (true) {
		//Loop for user action
		while (true) {
			//get user input for check
			std::cout << "Input: ";
			getline(std::cin, input);
			//convert to lower case
			for (int i=0; input[i]; i++) input[i] = tolower(input[i]);

			//Running away mid-combat
			if (input.compare("retreat") == 0) {
				std::cout << "You decide to run back the way you came" << std::endl;
				player -> setPosX(previousPosX);
				player -> setPosY(previousPosY);
				return false;
			}
			//Display Status
			else if (input.compare("status")==0) {
				std::cout << "Name: " << player -> getName() << std::endl;
                     		std::cout << "Description: " << player->getDescription() << std::endl  << std::endl;
                     		std::cout << "Health: " << player->getCurrentHealth() << "/" << player->getMaxHealth() << std::endl;
                     		std::cout << "Stamina: " << player->getCurrentStat(5) << "/" << player->getStat(5) << std::endl;
                	     	std::cout << "Weight: " << player->getCurrentStat(4) << "/" << player->getStat(4) << std::endl << std::endl;
        	             	std::cout << "Melee: " << player->getStat(0) << " Ranged: " << player->getStat(1) << std::endl;
 	                    	std::cout << "Throw: " << player->getStat(3) << " Medicine: " << player->getStat(4) << std::endl << std::endl;	
			}
			//Heal
			else if (input.compare("heal")==0) {
				player -> setCurrentHealth(player->getCurrentHealth() + player->getCurrentStat(3));
				player -> setCurrentStat(5, player->getCurrentStat(5) - 75);
				if (player->getCurrentStat(5) < 0) {
					player->setCurrentStat(5, 0);
				}
				if (player -> getCurrentHealth() > player-> getMaxHealth()) {
					player -> setCurrentHealth(player->getMaxHealth());
				}
			}	
			//Rest
			else if (input.compare("rest")==0) {
				player -> setCurrentStat(5, player->getCurrentStat(5) + player->getCurrentAttribute(2) * 10);
				if (player -> getCurrentStat(5) > player -> getStat(5)) {
					player -> setCurrentStat(5, player->getStat(5));
				}
			}	
			//User attempts to use movement words
			else if (input.compare("north")==0) {
				std::cout << "I can't move freely while in combat, unless I retreat." << std::endl;
			}
			else if (input.compare("south")==0) {
				std::cout << "I can't move freely while in combat, unless I retreat." << std::endl;
			}
			else if (input.compare("east")==0) {
				std::cout << "I can't move freely while in combat, unless I retreat." << std::endl;
			}
			else if (input.compare("west")==0) {
				std::cout << "I can't move freely while in combat, unless I retreat." << std::endl;
			}
			//Handles using skills and unknown words 
			else {
				if (player -> checkHasSkill(input)) {
					Skill* tempSkill = skills -> getSkill(input);
					if (!tempSkill -> canBeUsed(player)) {
						std::cout << "The skill can not be used" << std::endl;
						break;
					}
					tempSkill -> useSkill(player, target);
				}
				break;
				//Loop through skill list and check if input matches a skill name
					//if true use skill and break out of loop
					//if false simply say "I don't understand" NO BREAK
			}
		}
		if (target -> getCurrentHealth() <= 0) {
			std::cout << "You have defeated the enemy." << std::endl;
			return true;
		}
	}
};

