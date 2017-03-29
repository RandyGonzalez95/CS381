/*
 * EntityMgr.h
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ENTITYMGR_H_
#define INCLUDE_ENTITYMGR_H_

#include <list>
#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>

#include <Entity381.h>
#include <mgr.h>

class Engine;

class EntityMgr: public Mgr
{

private:
	std::list<Entity381 *> entities;
	//
public:

//	Ogre::SceneManager *ogreSceneMgr;
	Entity381* selectedEntity;

	EntityMgr(Engine *eng);
	//EntityMgr(Ogre::SceneManager *ogreSceneMgr);
	~EntityMgr();

	virtual void init();
	virtual void tick(float dt);
	virtual void loadLevel();
	virtual void stop();

	Entity381 *CreateEntity(EntityType entityType, Ogre::Vector3 pos, float yaw = 0);
	void CreateOgreEntityAndNode(Entity381 *ent);
	//void Tick(float dt);
	void SelectNextEntity();


};



#endif /* INCLUDE_ENTITYMGR_H_ */
