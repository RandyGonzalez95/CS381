/*
 * EntityMgr.h
 *
 *  Created on: Mar 6, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_ENTITYMGR_H_
#define INCLUDE_ENTITYMGR_H_

#include "Entity381.h"
#include <vector>

class EntityMgr
{
public:
	EntityMgr();
	EntityMgr(Ogre::SceneManager *mSceneMgr);
	virtual ~EntityMgr();

	bool Init();
	Entity381* CreateEntity(EntityType *type, Ogre::Vector3 pos, float heading);
	void Tick(float dt);

private:
	std::vector<Entity381*> entities;

};



#endif /* INCLUDE_ENTITYMGR_H_ */
