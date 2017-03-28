/*
 * GameMgr.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: randy
 */
#include <GameMgr.h>
#include <engine.h>

GameMgr::GameMgr(Engine *eng) : Mgr(eng)
{

}

GameMgr::~GameMgr()
{

}

void GameMgr::createScene()
{
	MakeGround();
}

void GameMgr::createEntities()
{

}

void GameMgr::MakeGround()
{
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	  Ogre::MeshManager::getSingleton().createPlane(
	    "ground",
	    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	    plane,
	    15000, 15000, 20, 20,
	    true,
	    1, 5, 5,
	    Ogre::Vector3::UNIT_Z);

	  Ogre::Entity* groundEntity = engine->gfxMgr->mSceneMgr->createEntity("ground");
	  engine->gfxMgr->mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	  groundEntity->setCastShadows(false);
	  //	  groundEntity->setMaterialName("Ocean2_HLSL_GLSL");
	  //groundEntity->setMaterialName("OceanHLSL_GLSL");
	  groundEntity->setMaterialName("Ocean2_Cg");
}

void GameMgr::MakeSky()
{

}

void GameMgr::MakeFog()
{

}

// Inherited Implementations
void GameMgr::tick(float dt)
{

}

void GameMgr::init()
{
	createScene();
}

void GameMgr::loadLevel()
{

}

void GameMgr::stop()
{

}


