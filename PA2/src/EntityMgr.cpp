/*
 * EntityMgr.cpp
 *
 *  Created on: Mar 6, 2017
 *      Author: randygonzalez
 */
#include "EntityMgr.h"

EntityMgr::EntityMgr()
{

}

EntityMgr::EntityMgr(Ogre::SceneManager* mSceneMgr)
{
	sceneMgr = mSceneMgr;
}

EntityMgr::~EntityMgr()
{

}

bool EntityMgr::Init()
{

	return true;
}

void EntityMgr::CreateEntity(EntityType type, Ogre::Vector3 pos, float heading)
{
	// Declare Temp
	Entity381 *temp = new Entity381();

	// Determine our type of boat
	switch(type)
	{
	case destroyer:
		temp = new Destroyer;
		break;

	case carrier:
		temp = new Carrier;
		break;

	case speedboat:
		temp = new Speedboat;
		break;

	case frigate:
		temp = new Frigate;
		break;

	case alien:
		temp = new Alien;
		break;

	default:
		break;
	}

	// give our object the corresponding mesh file
	temp->ogreEntity = sceneMgr->createEntity(temp->meshFile);
	temp->ogreSceneNode = sceneMgr->getRootSceneNode()->createChildSceneNode(pos); // place object
	temp->ogreSceneNode->attachObject(temp->ogreEntity);


	// Texture our object
	temp->ogreEntity->setMaterialName(temp->matFile);

	// Add Entity to our list
	entities.push_back(temp);

}

void EntityMgr::Tick(float dt)
{
	for(int i = 0; i< entities.size();i++)
	{
		entities[i]->Tick(dt);
	}
}


