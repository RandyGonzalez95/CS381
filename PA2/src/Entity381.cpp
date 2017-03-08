/*
 * Entity381.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: randygonzalez
 */

#include "Entity381.h"

Entity381::Entity381()
{
	isSelected = false;
	entityId = 0;
	entityName = "";
	meshFile = "";
	minSpeed = 0;
	maxSpeed = 0;
	speed = 0;
	heading = 0;
	desiredSpeed = 0;
	desiredHeading = 0;
	acceleration = 0;
	turningRate = 0;
	Ogre::Vector3 position = Ogre::Vector3::ZERO;
	velocity = Ogre::Vector3::ZERO;


}

Entity381::~Entity381(void)
{

}

void Entity381::Tick(float dt)
{
	/*for(int i = 0; i<listOfAspects.size();i++)
	{
		listOfAspects[i]->Tick(dt);
	}*/
}

// Start Destroyer class definition
Destroyer::Destroyer(void)
{
	meshFile = "ddg51.mesh";
	matFile = "Deck";
	minSpeed = 0;
	maxSpeed = 0;
	speed = 0;
	heading = 0;
	desiredSpeed = 10;
	desiredHeading = 0;
	acceleration = 1;
	turningRate = 0;
	position = Ogre::Vector3::ZERO;
	velocity = Ogre::Vector3::ZERO;
}


Destroyer::~Destroyer(void)
{
}


bool Destroyer::Init(void)
{

	return true;
}

// Start Carrier class definition
Carrier::Carrier(void)
{

}


Carrier::~Carrier(void)
{

}


bool Carrier::Init(void)
{

	return true;
}

// Start Speedboat class definition
Speedboat::Speedboat(void)
{

}


Speedboat::~Speedboat(void)
{

}


bool Speedboat::Init(void)
{

	return true;
}

// Start Frigate class definition
Frigate::Frigate(void)
{

}


Frigate::~Frigate(void)
{

}


bool Frigate::Init(void)
{

	return true;
}

// Start Frigate class definition
Alien::Alien(void)
{

}


Alien::~Alien(void)
{

}


bool Alien::Init(void)
{

	return true;
}


