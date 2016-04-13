/*
 * Class: Skill Builder
 * Description: Class is used to import
 * 	and store skill objects for use
 * 
 * Author: David Moore
 * Date created: 5-8-2016
 * Last Modified: 5-8-2016
 *
 */

//Include Statements
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include "SkillBuilder.h"

/*
 * Constructor
 * sets fileName
 */
SkillBuilder::SkillBuilder(std::string fileName) {
	this -> fileName = fileName;
};

/*
 * Returns the Skill object pointer
 * 	with the name - name
 * If the skill is not found
 * 	returns NULL
 */
Skill* SkillBuilder::getSkill(std::string name) {
	for (int i = 0; i < skills.size(); i++) {
		if (skills[i] -> getName().compare(name) == 0) {
			return skills[i];
		}
	}
	return NULL;
};
/*
 * Reads in data from fileName
 * Reads in data from each line
 * 	and sets the appropriate temp values
 * Builds a Skill object using
 * 	temp variabls
 * Returns true if the data was read in
 * 	& the skills vector was built
 * Otherwise returns false
 */
bool SkillBuilder::buildSkills() {
	//Make file object
	std::ifstream file(fileName.c_str());
	//check if file is open
	if (!file.is_open()) {
		return false;
	}
	
	//Temp string for reading line data
	std::string tempLine;

	//Loop to iterate through the file
	int i = 0;
	while (getline(file, tempLine)) {
		if (tempLine.find("Name: ") != -1) {
			name = tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<") - 1);
			i++;
		}
		else if (tempLine.find("Description: ") != -1) {
			description = tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1);
			i++;
		}
		else if (tempLine.find("Stamina: ") != -1) {
			staminaUse = atoi(tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1).c_str());
			i++;
		}
		else if (tempLine.find("Damage: ") != -1) {
			damage = atoi(tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1).c_str());
			i++;
		}

		if (i == 4) { 
			skills.push_back(new Skill(name, description, staminaUse, damage));
			i = 0;
		}
	};
	return true;
};
