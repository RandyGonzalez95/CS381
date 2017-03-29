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
	MakeSky();
	createEntities();

}

void GameMgr::createEntities()
{
	Entity381 *ent = 0;
	int x = 0;

	ent = engine->entityMgr->CreateEntity(destroyer, Ogre::Vector3(-100,0,0), 0);
	x += 200;
	ent = engine->entityMgr->CreateEntity(carrier, Ogre::Vector3(x,0,0), 0);
	x += 200;
	ent = engine->entityMgr->CreateEntity(speedboat, Ogre::Vector3(x,0,0), 0);
	x += 200;
	ent = engine->entityMgr->CreateEntity(frigate, Ogre::Vector3(x,0,0), 0);
	x += 200;
	ent = engine->entityMgr->CreateEntity(alien, Ogre::Vector3(x,0,0), 0);
	x += 200;

	ent->isSelected = true;


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
	engine->gfxMgr->mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");
}

void GameMgr::MakeFog()
{
	Ogre::ColourValue fadeColour(0.9, 0.9, 0.9);
	engine->gfxMgr->mWindow->getViewport(0)->setBackgroundColour(fadeColour);
	engine->gfxMgr->mSceneMgr->setFog(Ogre::FOG_LINEAR, fadeColour, 0, 600, 900);
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


