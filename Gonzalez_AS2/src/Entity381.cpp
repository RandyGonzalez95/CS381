/*
 * Entity381.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: randygonzalez
 */

#include "Entity381.h"

Entity381::Entity381()
{
	entityId = 0;
	entityName = new char[20];
	meshFile = new char[20];
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

void Entity381::CreateScene()
{

}

void Entity381::Tick(float dt)
{

}

