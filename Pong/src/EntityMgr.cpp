/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: sushil
 */


#include <EntityMgr.h>
#include <engine.h>


EntityMgr::EntityMgr(Engine *eng): Mgr(eng)
{

}

EntityMgr::~EntityMgr()
{

}

void EntityMgr::tick(float dt)
{
	// Loop through list of entities

}

void EntityMgr::init()
{
	return;
}

void EntityMgr::loadLevel()
{

}

void EntityMgr::stop()
{
	return;
}

void EntityMgr::CreateOgreEntityAndNode(Entity381 *ent)
{

	/*if(ent) {
		ent->ogreEntity = engine->gfxMgr->ogreSceneManager->createEntity(ent->meshfile);
		ent->ogreSceneNode = engine->gfxMgr->ogreSceneManager->getRootSceneNode()->createChildSceneNode(ent->pos);
		ent->ogreSceneNode->attachObject(ent->ogreEntity);
		ent->ogreSceneNode->yaw(Ogre::Radian(ent->heading));
	}*/

}

Entity381* EntityMgr::CreateEntity()
{

	Entity381 *ent = 0;// = new Entity381(entityType, position, heading);


	CreateOgreEntityAndNode(ent);
	// push back entity to list
	return ent;
}


