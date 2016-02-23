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
#include <string>
#include <vector>
#include <iostream>

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
int MapBuildeR::getStartRoomXpos() {
	return startRoomXpos;
};

/*
* Returns the y pos of the start room
*/
int MapBuildeR::getStartRoomYpos() {
	return startRoomYpos;
};

/*
* Returns the x pos of the end room
*/
int MapBuildeR::getEndRoomXpos() {
	return startRoomXpos;
};

/*
* Returns the y pos of the end room
*/
int MapBuildeR::getStartRoomXpos() {
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
	return false;
};

