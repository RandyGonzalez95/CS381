/*
 * Entity381.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#include <Entity381.h>
#include <aspect.h>

unsigned int Entity381::nextId = 0;

Entity381::Entity381()
{

	this->pos = pos;
	this->heading = heading;
	this->vel = Ogre::Vector3::ZERO;
	this->speed = 0;

	this->isSelected = false;


	this->entityId = Entity381::nextId++;



	Aspect *physics;
	Aspect *graphics;

	graphics = new Renderable(this);
	physics = new Physics(this);

	listOfAspects.push_back(graphics);
	listOfAspects.push_back(physics);


	DefaultInit();
}

Entity381::Entity381(EntityType entType, Ogre::Vector3 pos, float heading)
{


	entityType = entType;
	this->pos = pos;
	this->heading = heading;
	this->vel = Ogre::Vector3::ZERO;
	this->speed = 0;

	this->isSelected = false;


	this->entityId = Entity381::nextId++;

	DefaultInit();
}

Entity381::~Entity381()
{

}

void Entity381::DefaultInit()
{
	this->acceleration = 0.5f;
	this->turnRate = 0.2f;

	this->maxSpeed = 100;
	this->minSpeed = 0;

	this->desiredHeading = 0;
	this->desiredSpeed = 0;

	this->meshfile = "cube.mesh";

}

void Entity381::Tick(float dt)
{
	for(unsigned int i = 0; i<listOfAspects.size();i++)
	{

		listOfAspects[i]->Tick(dt);
	}
}

Ddg::Ddg(){}

Ddg::Ddg(Ogre::Vector3 pos, float heading) //: Entity381(EntityType::DDG, pos, heading)
{
	this->meshfile = "ddg51.mesh";
	this->pos = pos;
	this->acceleration = 1.0f;
	this->turnRate = 0.1f;
}

Ddg::~Ddg()
{

}

Cigarette::Cigarette(){}

Cigarette::Cigarette(Ogre::Vector3 pos, float heading) //: Entity381(EntityType::CIGARETTE, pos, heading)
{
	this->meshfile = "cigarette.mesh";
	this->pos = pos;
	this->acceleration = 1.5f;
	this->turnRate = 0.3f;
}

Cigarette::~Cigarette()
{

}

Alien::Alien(){}

Alien::Alien(Ogre::Vector3 pos, float heading) //: Entity381(EntityType::ALIEN, pos, heading)
{
	this->meshfile = "alienship.mesh";
	this->pos = pos;
	this->turnRate = 0.5f;
	this->acceleration = 1.8f;
}

Alien::~Alien()
{

}

Cvn::Cvn(){}

Cvn::Cvn(Ogre::Vector3 pos, float heading) //: Entity381(EntityType::CVN, pos, heading)
{
	this->meshfile = "cvn68.mesh";
	this->pos = pos;
	this->turnRate = 0.05f;
	this->acceleration = 0.75f;
}

Cvn::~Cvn(){

}

Frigate::Frigate(){}

Frigate::Frigate(Ogre::Vector3 pos, float heading) //: Entity381(EntityType::FRIGATE, pos, heading)
{
	this->meshfile = "sleek.mesh";
	this->pos = pos;
	this->turnRate = 0.15f;
	this->acceleration = 1.1f;
}

Frigate::~Frigate()
{

}


