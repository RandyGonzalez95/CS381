/*
 * Aspect.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: randygonzalez
 */


#include "Aspect.h"

Aspect::Aspect()
{

}

Aspect::Aspect(Entity381* ent)
{
	entity = ent;
}

Aspect::~Aspect()
{

}

void Aspect::Tick(float dt)
{

}

PhysicsAspect::PhysicsAspect(void)
{

}

PhysicsAspect::PhysicsAspect(Entity381* ent)
{
	entity = ent;
}


PhysicsAspect::~PhysicsAspect()
{

}

void PhysicsAspect::UpdatePostion()
{

}

void PhysicsAspect::Tick(float dt)
{
	if(entity->ogreSceneNode == NULL)
	{
		std::cerr<<"Hello\n";
	}
	std::cerr<<"Not Null\n";
	//position = position + (velocity * fe.timeSinceLastFrame);
	entity->position = entity->position + (entity->velocity *dt);
	entity->ogreSceneNode->setPosition(entity->position);

}

RenderableAspect::RenderableAspect()
{

}

RenderableAspect::~RenderableAspect()
{

}

void RenderableAspect::RenderBoat()
{

}


void RenderableAspect::Tick(float dt)
{

}
