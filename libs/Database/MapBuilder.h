/*
* Class: MapBuilder Class Header
* Description: Prototypes the MapBuilder class
*
* Author: David Moore
* Date created: 2-21-2016
* Last modified: 2-21-2016
*
*/

//Header guard start
#ifndef MapBuilder_H
#define MapBuilder_H

//Include statements
#include "../Entity/Room.cpp"

#include <string>
#include <vector>
#include <iostream>

class MapBuilder {

//Variables
private:
	std::string mapName; //txt file name
	int startRoomXpos;
	int startRoomYpos;
	int endRoomXpos;
	int endRoomYpos;
	int numberOfRooms;	
	
	std::vector< std::vector<Room*> > map;

//Functions
public:
	std::string getMapName(); //Returns the name of the txt file
	int getStartRoomXpos(); //Returns the x pos of start room
	int getStartRoomYpos(); //Returns the y pos of start room
	int getEndRoomXpos(); //Returns the x pos of end room
	int getEndRoomYpos(); //Returns the y pos of end room

	/*
	* Returns the Room object in the Rooms
	* 	vector at [x][y]
	*/
	Room* getRoom(int x, int y);
	
	/*
	* Returns the 2D vector that stores all rooms
	* The position of the room in the vector
	*	corisponds to the position of the room
	*	on the map. (top right corner [0][0)]
	*/
	std::vector< std::vector<Room*> > getMap();

	/*
	* Reads in data from mapName
	* Sets start room and end room x & y values
	* Sets numberOfRooms
	* Constructs the 2D vector of Rooms
	* Returns true if the data was read in
	* 	& the map was build
	* Returns false if the data could not
	*	be read in or the map could not be built
	*/
	bool buildMap();

//Constructor
public:
	/*
	* Default constructor
	*/
	MapBuilder();
	
	/*
	* General use Constructor
	* Sets mapName
	*/
	MapBuilder(std::string mapName);

};

//Header guard end
#endif
