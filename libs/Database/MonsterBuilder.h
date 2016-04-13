/*
 * Class: Monster Builder Header
 * Description: Prototypes the class that will
 * 	import and store character objects
 *
 * Author: David Moore
 * Date created: 4-12-2016
 * Last Modified: 4-12-2016
 *
 */

//Header Guard Start
#ifndef MonsterBuilder_H
#define MonsterBuilder_H

//Include Statements
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "../Combat/Skill.h"
#include "../Entity/Character.h"
#include "SkillBuilder.h"

class MonsterBuilder {

//Variables
private:
	std::string fileName;
	SkillBuilder* skillBuilder;

	std::string name;
	std::string description;
	int attributes[6];
	int stats[6];
	std::vector <std::string> skills;

	std::vector <Character*> monsters;
//Functions
public:
	/*
	 * Returns the character object pointer with the name - name
	 * If the character is not found
	 *	Returns NULL
	 */
	Character* getCharacter(std::string name);

	/*
	 * Reads in data from file name
	 * Reads line by line
	 * 	setting temp variables
	 * Builds character object and stores it in monsters
	 * Returns true if data was read in
	 * 	otherwise returns false
	 */
	bool buildMonsters();

//Constructor
public:
	/*
	 * General use constructor
	 * Sets fileName and skillBuilder
	 */
	MonsterBuilder(std::string fileName, SkillBuilder* skillBuilder);
};

//Header Guard End
#endif
