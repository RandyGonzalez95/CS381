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
	void CreateEntity(EntityType type, Ogre::Vector3 pos, float heading);
	void Tick(float dt);
	std::vector<Entity381*> entities;

private:

	Ogre::SceneManager *sceneMgr;

};



#endif /* INCLUDE_ENTITYMGR_H_ */
