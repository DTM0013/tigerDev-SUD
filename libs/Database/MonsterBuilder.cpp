/*
 * Class: Monster Builder
 * Description: imports and stores character objects
 *
 * Author: David Moore
 * Date Created: 4-12-2016
 * Last Modified: 4-15-2016
 *
 */

//Include statment
#include "MonsterBuilder.h"

/*
 * Constructor
 * Sets fileName and skillBuilder
 */
MonsterBuilder::MonsterBuilder(std::string fileName, SkillBuilder* skillBuilder) {
	this -> fileName = fileName;
	this -> skillBuilder = skillBuilder;	
};

/*
 * Returns the character object pointer with the name - name
 * Returns NULL if the character object can't be found
 */
Character* MonsterBuilder::getCharacter(std::string name) {
	for (int i = 0; i < monsters.size(); i++) {
		if (monsters[i] -> getName().compare(name) == 0) {
			return monsters[i];
		}
	}
	return NULL;
};

/*
 * Reads in data from file name
 * Reads in line by line setting temp variables
 * Builds a character object and stores it
 * Returns true if data was read in
 * Otherwise returns false
 */
bool MonsterBuilder::buildMonsters() {
	//Make file object
	std::ifstream file(fileName.c_str());
	//check if the file is open
	if (!file.is_open()) {
		return false;
	}

	//Temp string for input
	std::string tempLine;

	//Loop through file
	int i=0;
	while(getline(file, tempLine)) {
		if (tempLine.find("Name: ") != -1) {
			i++;
			name = tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1);
		}
		else if (tempLine.find("Description: ") != -1) {
			i++;
			description = tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1);
		}
		else if (tempLine.find("") != -1) {
			i++;
		}
		else if (tempLine.find("") != -1) {
			i++;
		}
		if (i == 4) {
			i = 0;
			//check constructor
			monsters.push_back(new Character());
		}
	};
	return true;
};
