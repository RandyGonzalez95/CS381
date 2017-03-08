/*
 * Aspect.h
 *
 *  Created on: Mar 7, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ASPECT_H_
#define INCLUDE_ASPECT_H_

#include "Entity381.h"

class Entity381;

class Aspect
{
public:
	Aspect();
	Aspect(Entity381* ent);
	virtual ~Aspect();

	virtual void Tick(float dt) = 0;
	Entity381 *entity;
};

class PhysicsAspect : public Aspect
{
public:
	PhysicsAspect();
	PhysicsAspect(Entity381* ent);
	~PhysicsAspect();
	void UpdatePostion();


protected:
	virtual void Tick(float dt);

private:
	Ogre::Vector3 position, velocity;
	Ogre::Entity *ogreEntity;
	Ogre::SceneNode *ogreSceneNode;
	float minSpeed, maxSpeed, speed, heading, desiredSpeed, desiredHeading;

};

class RenderableAspect : public Aspect
{
public:
	RenderableAspect();
	RenderableAspect(Entity381* ent);
	~RenderableAspect();
	void RenderBoat();

protected:
	virtual void Tick(float dt);

private:
	Ogre::Entity *ogreEntity;
	Ogre::SceneNode *ogreSceneNode;
	Ogre::Vector3 position, heading;

};

#endif /* INCLUDE_ASPECT_H_ */
