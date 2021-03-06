/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 22, 2017
 *      Author: sushil
 */


#include "../Inc/EntityMgr.h"

#include "../Inc/engine.h"


EntityMgr::EntityMgr(Engine *eng): Mgr(eng){
	entities.clear();
	selectedEntity = 0;
}

EntityMgr::~EntityMgr(){
	entities.clear();
}

void EntityMgr::tick(float dt){
	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it){
		(*it)->Tick(dt);
		if ((*it)->isSelected)
			this->selectedEntity = (*it);
	}
}

void EntityMgr::init(){
	return;
}

void EntityMgr::loadLevel(){

}

void EntityMgr::stop(){
	return;
}

void EntityMgr::CreateOgreEntityAndNode(Entity381 *ent){

	if(ent) {
		ent->ogreEntity = engine->gfxMgr->ogreSceneManager->createEntity(ent->meshfile);
		ent->ogreSceneNode = engine->gfxMgr->ogreSceneManager->getRootSceneNode()->createChildSceneNode(ent->pos);
		ent->ogreSceneNode->attachObject(ent->ogreEntity);
		ent->ogreSceneNode->yaw(Ogre::Radian(ent->heading));
	}

}

Entity381* EntityMgr::CreateEntity(EntityType entityType, Ogre::Vector3 position, float heading){

	Entity381 *ent = 0;// = new Entity381(entityType, position, heading);
	switch(entityType){
	case EntityType::ALIEN:
		ent = new Alien(position, heading);
		break;
	case EntityType::CIGARETTE:
		ent = new Cigarette(position, heading);
		break;
	case EntityType::DDG:
		ent = new Ddg(position, heading);
		break;
	case EntityType::CVN:
		ent = new Cvn(position, heading);
		break;
	case EntityType::FRIGATE:
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

void EntityMgr::SelectNextEntity(){
	int n = 0;

	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it){
		n++;
		if((*it)->isSelected){
			(*it)->isSelected = false;
			it++;
			if(it == entities.end()){
				std::cout << "End of ents" << std::endl;
				selectedEntity = *(entities.begin());
			} else {
				selectedEntity = *it;
				std::cout << "End of ents" << std::endl;
			}
			selectedEntity->isSelected = true;
			break;
		}
	}

}

Entity381* EntityMgr::closestBoat(Ogre::Vector3 point){
	Ogre::Real closestDistance = 50000;
	Ogre::Real currentDistance;
	Entity381* closestBoat = NULL;


	for (std::list<Entity381 *>::const_iterator it = entities.begin(); it != entities.end(); ++it){
		currentDistance = point.distance((*it)->pos);

		if(currentDistance < closestDistance){
			closestDistance = currentDistance;
			closestBoat = *it;
		}
	}

	return closestBoat;
}

