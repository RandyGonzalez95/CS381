/*
 * EntityMgr.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */
#include <EntityMgr.h>
#include <engine.h>


EntityMgr::EntityMgr(Engine *eng): Mgr(eng)
{
	entities.clear();
	selectedEntity = 0;
}


EntityMgr::~EntityMgr(){
	entities.clear();
}

void EntityMgr::tick(float dt)
{
	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it)
	{
		(*it)->Tick(dt);
		if ((*it)->isSelected)
			this->selectedEntity = (*it);
	}
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

	if(ent)
	{
		ent->ogreEntity = engine->gfxMgr->mSceneMgr->createEntity(ent->meshfile);
		ent->ogreSceneNode->attachObject(ent->ogreEntity);
		ent->ogreSceneNode->yaw(Ogre::Radian(ent->heading));
	}

}

Entity381* EntityMgr::CreateEntity(EntityType entityType, Ogre::Vector3 position, float heading)
{

	Entity381 *ent = 0;// = new Entity381(entityType, position, heading);

	switch(entityType)
	{
	case alien:
		ent = new Alien(position, heading);
		break;
	case speedboat:
		ent = new Cigarette(position, heading);
		break;
	case destroyer:
		ent = new Ddg(position, heading);
		break;
	case carrier:
		ent = new Cvn(position, heading);
		break;
	case frigate:
		ent = new Frigate(position, heading);
		break;
	default:
		ent = new Ddg(position, heading);
		break;
	}

	CreateOgreEntityAndNode(ent);
	entities.push_front(ent);
	return ent;
}

void EntityMgr::SelectNextEntity()
{
	int n = 0;

	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it){
		n++;
		if((*it)->isSelected)
		{
			(*it)->isSelected = false;
			it++;
			if(it == entities.end())
			{
				std::cout << "End of ents" << std::endl;
				selectedEntity = *(entities.begin());
			}
			else
			{
				selectedEntity = *it;
				std::cout << "End of ents" << std::endl;
			}
			selectedEntity->isSelected = true;
			break;
		}
	}

}



