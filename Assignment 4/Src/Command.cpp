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
	//std::cout << "Constuctor command created" << std::endl << std::endl;
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
	//std::cout << "Constuctor moveto created" << std::endl << std::endl;
	targetLocation = location;
	isFinished = false;
}


MoveTo::~MoveTo(){

}


void MoveTo::init(){/*
	std::cout << " this is 1" << std::endl << std::endl;
	std::cout << "target: " << targetLocation << "pos: " << entity->pos << std::endl << std::endl;
	if (targetLocation != entity->pos){
		std::cout << "2" << std::endl << std::endl;
		entity->desiredSpeed = entity->maxSpeed;
		std::cout << "3" << std::endl << std::endl;
	}
	std::cout << "4" << std::endl << std::endl;*/
}



void MoveTo::tick(float dt){
	// Vector difference
	/*cout << endl << "1" << endl << endl;
	cout << targetLocation << endl;
	cout << "boat: " << entity->pos << endl;*/
	//Ogre::Vector3 deltaVec = targetLocation - entity->pos;
	//cout << endl << "2" << endl << endl;

	std::cerr<<"Move To tick being called"<<std::endl;

	// Calculate distance
	//Ogre::Real distance = Ogre::Math::Sqrt(deltaVec.x * deltaVec.x + deltaVec.y * deltaVec.y);
	Ogre::Real distance = targetLocation.distance(entity->pos);

	// if the ships within threshold
	if(distance < MOVE_DISTANCE_THRESHOLD){
		// slow down
		entity->desiredSpeed = 0;

		// and now command is finished
		isFinished = true;
	}

	// get proper heading to face destination
	//Ogre::Radian angle = Ogre::Math::ATan2(entity->pos.y, entity->pos.x);
	Ogre::Radian angle = Ogre::Math::ATan2(targetLocation.y, targetLocation.x);

	// set the proper heading
	entity->desiredHeading = angle.valueDegrees();

	//cout << endl << entity->desiredHeading << endl << distance << endl << endl << endl;

	// accelerate to max speed possible toward the destination
	entity->desiredSpeed = entity->maxSpeed;
}


bool MoveTo::done(){

}


Follow::Follow(Entity381* ent, Ogre::Vector3 location) : Command(ent, commandType){
	targetLocation = location;
}


Follow::~Follow(){

}


void Follow::init(){
	// if right clicked


		// check for the click location and see if the current entity position is greater than that
			// if x is greater, head to the positive direction

			// if x is less, turn around

			// if z is greater, turn clockwise

			// if z is less, turn clockwise

		//
}



void Follow::tick(float dt){

}


bool Follow::done(){

}





