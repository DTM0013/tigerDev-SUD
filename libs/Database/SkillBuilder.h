/*
 * Class: Skill Builder Header
 * Description: Prototypes the class the will 
 * 	import and store skill objects
 *
 * Author: David Moore
 * Date created: 4-7-2016
 * Last Modified: 4-7-2016
 *
 */

//Header Guard Start
#ifndef SkillBuilder_H
#define SkillBuilder_H

//Include Statements
#include <string>
#include <iostream>
#include <vector>
#include "../Combat/Skill.h"

class SkillBuilder {

//Variables
private:
	std::string fileName;

	std::string name;
	std::string description;
	int staminaUse;
	int damage;

	std::vector <Skill*> skills;

//Functions
public:
	/*
	 * Returns the Skill object pointer 
	 *	with the name - name
	 * If the skill is not found 
	 *	returns NULL
	 */
	Skill* getSkill(std::string name);

	/*
	 * Reads in data from fileName
	 * Reads in data from each line
	 * 	and sets appropriate temp variables
	 * Builds a Skill object using
	 * 	temp variables
	 * Returns true if the data was read in
	 * 	& the Skills vector was built
	 * Otherwise returns false
	 */
	bool buildSkills();

//Constructor
public:
	/*
	 * General use Constructor
	 * sets fileNma
	 */
	SkillBuilder(std::string fileName);
};

//Header Guard End
#endif
