/*
 * Entity381.h
 *
 *  Created on: Mar 6, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ENTITY381_H_
#define INCLUDE_ENTITY381_H_

#include "BaseApplication.h"
#include "EntityType.h"
#include <vector>
#include "Aspect.h"

class Aspect;

class Entity381
{
public:
	Entity381();
	virtual ~Entity381();
	bool Init();

	void Tick(float dt);

	// variables
	bool isSelected, isMoving;
	Ogre::Real entityId;
	Ogre::String entityName, meshFile, matFile;
	float minSpeed, maxSpeed, speed, heading, desiredSpeed, desiredHeading;
	float acceleration, turningRate;
	Ogre::Vector3 position, velocity;
	Ogre::SceneNode *ogreSceneNode;
	Ogre::Entity *ogreEntity;
	std::vector<Aspect*> listOfAspects;
};

class Destroyer : public Entity381
{
public:
	Destroyer();
	~Destroyer();
	bool Init();
private:
	// mesh file

};

class Carrier : public Entity381
{
public:
	Carrier();
	~Carrier();
	bool Init();
private:
};

class Speedboat : public Entity381
{
public:
	Speedboat();
	~Speedboat();
	bool Init();
private:
};

class Frigate : public Entity381
{
public:
	Frigate();
	~Frigate();
	bool Init();
private:
};

class Alien : public Entity381
{
public:
	Alien();
	~Alien();
	bool Init();
private:
};



#endif /* INCLUDE_ENTITY381_H_ */
