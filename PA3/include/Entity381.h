/*
 * Entity381.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ENTITY381_H_
#define INCLUDE_ENTITY381_H_

#include <OgreVector3.h>
#include <OgreSceneNode.h>

#include <Types.h>

#include <vector>

class Aspect;

class Entity381
{

private:
	//
	static unsigned int nextId;

protected:
	//

public:

	Entity381();
	Entity381(EntityType entityType, Ogre::Vector3 pos, float heading);
	~Entity381();
	void Tick(float dt);
	void DefaultInit();

	//static stuff
	float maxSpeed, minSpeed;
	float acceleration, turnRate;
	EntityType entityType;
	std::string meshfile;
	std::string matfile;

	//Ogre stuff
	Ogre::Vector3 pos;
	Ogre::Vector3 vel;
	Ogre::SceneNode *ogreSceneNode;
	Ogre::Entity* ogreEntity;

	//Engine stuff dynamic
	float speed, heading;
	float desiredSpeed, desiredHeading;

	//selection
	bool isSelected;

	unsigned int entityId;

	std::vector<Aspect*> listOfAspects;
};

class Ddg: public Entity381
{

public:
	Ddg();
	Ddg(Ogre::Vector3 pos, float heading);
	~Ddg();

};

class Cigarette: public Entity381
{

public:
	Cigarette();
	Cigarette(Ogre::Vector3 pos, float heading);
	~Cigarette();
};

class Alien: public Entity381
{

public:
	Alien();
	Alien(Ogre::Vector3 pos, float heading);
	~Alien();
};

class Cvn: public Entity381
{

public:
	Cvn();
	Cvn(Ogre::Vector3 pos, float heading);
	~Cvn();
};

class Frigate: public Entity381
{

public:
	Frigate();
	Frigate(Ogre::Vector3 pos, float heading);
	~Frigate();
};



#endif /* INCLUDE_ENTITY381_H_ */
