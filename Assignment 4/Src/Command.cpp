/*
 * Command.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: jwoo
 */
#include <Command.h>

using namespace std;

Command::Command()
{

}

Command::Command(Entity381* ent, COMMAND_TYPE ct){
	entity = ent;
}


Command::~Command(){

}


void Command::init(){

}



void Command::tick(float dt){

}


bool Command::done(){

}



MoveTo::MoveTo(Entity381* ent, Ogre::Vector3 location) : Command(ent, commandType){
	std::cerr<<"Move to instantiated"<<std::endl;
	targetLocation = location;
	isFinished = false;
}


MoveTo::~MoveTo(){

}


void MoveTo::init(){
}



void MoveTo::tick(float dt){

	// Calculate distance
	Ogre::Real distance = targetLocation.distance(entity->pos);

	// if the ships within threshold
	if(distance < MOVE_DISTANCE_THRESHOLD)
	{
		std::cerr<<"the ship is at its destination"<<std::endl;
		// slow down
		entity->desiredSpeed = 0;
		entity->vel = Ogre::Vector3::ZERO;

		// and now command is finished
		isFinished = true;
		return;
	}

	// Grab the distance between the two vectors and determine the theta angle
	Ogre::Vector3 difference = targetLocation - entity->pos;
	Ogre::Radian angle = Ogre::Math::ATan2(difference.z, difference.x);
	float heading = angle.valueRadians();

	if(heading < 0)
	{
		heading += Ogre::Math::TWO_PI;
	}
	else if (heading >= Ogre::Math::TWO_PI)
	{
		heading -= Ogre::Math::TWO_PI;
	}

	entity->desiredHeading = heading;

	// accelerate to max speed possible toward the destination
	entity->desiredSpeed = entity->maxSpeed;
}


bool MoveTo::done(){
	return isFinished;
}


Follow::Follow(Entity381* ent, Entity381* boat) : Command(ent, commandType){
	isFinished = false;
	followedBoat = boat;
}


Follow::~Follow(){

}


void Follow::init(){

}



void Follow::tick(float dt){
	targetLocation = followedBoat->pos;

	Ogre::Real distance = targetLocation.distance(entity->pos);

	// if the ships within threshold
	if(distance < MOVE_DISTANCE_THRESHOLD)
	{
		std::cerr<<"the ship is at its destination"<<std::endl;
		// slow down
		entity->desiredSpeed = 0;
		entity->vel = Ogre::Vector3::ZERO;

		// and now command is finished
		isFinished = true;
		return;
	}

	// get proper heading to face destination
	Ogre::Vector3 difference = targetLocation - entity->pos;
	Ogre::Radian angle = Ogre::Math::ATan2(difference.z, difference.x);

	// set the proper heading
	entity->desiredHeading = angle.valueRadians();
	//std::cerr<<"Desired Heading: "<<entity->desiredHeading<<std::endl;

	// accelerate to max speed possible toward the destination
	entity->desiredSpeed = entity->maxSpeed;
}


bool Follow::done(){

	return isFinished;
}








