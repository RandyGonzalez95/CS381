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

	entity->position = entity->position + (entity->velocity *dt);
	//entity->ogreSceneNode->setPosition(entity->position);

}

RenderableAspect::RenderableAspect()
{

}

RenderableAspect::RenderableAspect(Entity381* ent)
{
	entity = ent;
}

RenderableAspect::~RenderableAspect()
{

}

void RenderableAspect::RenderBoat()
{
	entity->ogreSceneNode->setPosition(entity->position);
}


void RenderableAspect::Tick(float dt)
{
	RenderBoat();
}
