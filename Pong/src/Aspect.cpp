/*
 * Aspect.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: Randy Gonzalez, Nirmit Patel
 */

#include <Aspect.h>
#include <math.h>

Aspect::Aspect (Entity381 * ent)
{
	this->entity = ent;


}

Aspect::~Aspect()
{

}


Renderable::Renderable(Entity381 * ent): Aspect(ent)
{

	return;
}

Renderable::~Renderable()
{

}

void Renderable::Tick(float dt)
{

}

Physics::Physics(Entity381 * ent): Aspect(ent)
{

}

Physics::~Physics()
{

}


void Physics::Tick(float dt)
{


}

