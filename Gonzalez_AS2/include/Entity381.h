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


class Entity381
{
public:
	Entity381();
	virtual ~Entity381();

	void Tick(float dt);
	bool isSelected = false;

private:
	int entityId;
	char* entityName, *meshFile;
	float minSpeed, maxSpeed, speed, heading, desiredSpeed, desiredHeading;
	float acceleration, turningRate;
	Ogre::Vector3 position, velocity;
	Ogre::SceneNode *ogreSceneNode;
	Ogre::Entity *ogreEntity;
};



#endif /* INCLUDE_ENTITY381_H_ */
