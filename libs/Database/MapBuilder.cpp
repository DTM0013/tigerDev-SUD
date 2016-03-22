/*
* Class: MapBuilder
* Description: Reads information about the map in
*	from a txt file, and appropriatly build it.
*
* Author: David Moore
* Date created: 2-22-2016
* Last modified: 2-22-2016
*
*/

//Include statements
#include "MapBuilder.h"
//#include "../Entity/Room.cpp"
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

/*
* Default constructor
*/
MapBuilder::MapBuilder() {
};

/*
* General use constructor
* Sets mapName
*/
MapBuilder::MapBuilder(std::string mapName) {
	this->mapName = mapName;

	map.resize(100);
	for (int i = 0; i < 100; i++) {
		map[i].resize(100);
	}
	
};

/*
* Returns the name of the txt file that is read in
*/
std::string MapBuilder::getMapName() {
	return mapName;
};

/*
* Returns the x pos of the start room
*/
int MapBuilder::getStartRoomXpos() {
	return startRoomXpos;
};

/*
* Returns the y pos of the start room
*/
int MapBuilder::getStartRoomYpos() {
	return startRoomYpos;
};

/*
* Returns the x pos of the end room
*/
int MapBuilder::getEndRoomXpos() {
	return startRoomXpos;
};

/*
* Returns the y pos of the end room
*/
int MapBuilder::getEndRoomYpos() {
	return endRoomYpos;
};

/*
* Return the room object with
*	position [x][y]
*/
Room* MapBuilder::getRoom(int x, int y) {
	return map[x][y];
};

/*
* Reads in data from mapName
* Sets start and end room x & y values
* Sets numberOfRooms
* Constructs the 2D vector of rooms
* Returns true if the data was read in
*	& the map was built
* Returns false if the data could not be
*	read in or the map could not be built
*
* Note: need to decide on format of txt file before making
*/
bool MapBuilder::buildMap() {

	//Make file object for reading data
	std::ifstream file(mapName.c_str());
	
	//Check if the file was opened
	if (!file.is_open()) {
		return false;
	}

	//Temp string for reading line data
	std::string tempLine;
	std::string tempWord;	

	//First 5 lines for basic map info
	//start room x
	std::getline(file, tempLine);
	tempWord = tempLine.substr(tempLine.find(" ") + 1);
	startRoomXpos = atoi(tempWord.c_str());

	//start room y
	getline(file, tempLine);
	tempWord = tempLine.substr(tempLine.find(" ") + 1);
	startRoomYpos = atoi(tempWord.c_str());
	
	//end room x
	getline(file, tempLine);
	tempWord = tempLine.substr(tempLine.find(" ") + 1);
	endRoomXpos = atoi(tempWord.c_str());
	
	//end room y
	getline(file, tempLine);
	tempWord = tempLine.substr(tempLine.find(" ") + 1);
	endRoomYpos = atoi(tempWord.c_str());
	
	//number of rooms
	getline(file, tempLine);
	tempWord = tempLine.substr(tempLine.find(" ") + 1);
	numberOfRooms = atoi(tempWord.c_str());

	//Create each room object and add it to 
	int xPos = 0;
	int yPos = 0;
	
	while (getline(file, tempLine)) {
		
		//Room position
		if (tempLine.find("RoomPos: ") != -1) {
			tempWord = tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1);
			xPos = atoi(tempWord.c_str());
			tempWord = tempLine.substr(tempLine.find("{")+1, tempLine.find("}")-tempLine.find("{")-1);
			yPos = atoi(tempWord.c_str());	
			
			//Room room = new Room();
			map[xPos][yPos] = new Room();	
		}
		
		//Room Name
		else if ( tempLine.find("RoomName: ") != -1) {
			map[xPos][yPos] -> setName(tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1));
		}
		
		//Room Description
		else if ( tempLine.find("RoomDescription: ") != -1) {
			map[xPos][yPos] -> setDescription(tempLine.substr(tempLine.find("<")+1, tempLine.find(">")-tempLine.find("<")-1));
		}
		
	}
	return true;
};

