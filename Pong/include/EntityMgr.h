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

class Engine;

class EntityMgr: public Mgr {

private:

	//
public:

	EntityMgr(Engine *eng);

	~EntityMgr();

	void init();
	void tick(float dt);
	void loadLevel();
	void stop();

	Entity381 *CreateEntity();
	void CreateOgreEntityAndNode(Entity381 *ent);

};


#endif /* ENTITYMGR_H_ */
