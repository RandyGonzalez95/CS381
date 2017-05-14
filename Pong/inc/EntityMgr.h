/*
 * EntityMgr.h
 *
 *  Created on: Feb 22, 2017
 *      Author: sushil
 */

#ifndef ENTITYMGR_H_
#define ENTITYMGR_H_


#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <Entity381.h>
#include <mgr.h>
#include <vector>

class Engine;

class EntityMgr: public Mgr
{

private:

public:
	EntityMgr(Engine *eng);
	~EntityMgr();

	void init();
	void tick(float dt);
	void loadLevel();
	void stop();

	Entity381 *CreateEntity(EntityType entityType, Ogre::Vector3 position);
	void CreateOgreEntityAndNode(Entity381 *ent);
	void DeleteEntity();

	std::vector<Entity381*> entities;

};



#endif /* ENTITYMGR_H_ */
