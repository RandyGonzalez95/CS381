/*
 * gameMgr.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: sushil
 */

#include <gameMgr.h>
#include <engine.h>
#include <OgreMeshManager.h>

GameMgr::GameMgr(Engine *engine): Mgr(engine)
{

}

GameMgr::~GameMgr()
{

}

void GameMgr::init()
{

}

void GameMgr::loadLevel()
{
//We know graphicsMgr is ready and initialized
	engine->gfxMgr->ogreSceneManager->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	Ogre::Light* light = engine->gfxMgr->ogreSceneManager->createLight("MainLight");
	light->setPosition(20.0, 80.0, 50.0);

	createEnts();
	createWall();
	//createSky();
	//createGround();
}

void GameMgr::stop()
{

}

void GameMgr::tick(float dt)
{
	hitPaddle();
}

void GameMgr::createEnts()
{
	int x = 0;

	// Entity[0] left paddle
	engine->entityMgr->CreateEntity(EntityType::Paddle, Ogre::Vector3(x, 0, 0));
	x += 800;

	// Entity[1] right paddle
	engine->entityMgr->CreateEntity(EntityType::Paddle, Ogre::Vector3(x, 0, 0));

	// Entity[2] left ball
	engine->entityMgr->CreateEntity(EntityType::Ball, Ogre::Vector3(400, 0, 0));


	engine->entityMgr->entities[0]->ogreSceneNode->setScale(0.5, 2.5, 1);
	engine->entityMgr->entities[1]->ogreSceneNode->setScale(0.5, 2.5, 1);


	engine->entityMgr->entities[2]->ogreSceneNode->setScale(0.2, 0.2, 0.2);





}

void GameMgr::hitPaddle()
{
	// Grab Positions of all entities
	leftPaddle = engine->entityMgr->entities[0]->ogreSceneNode->getPosition();
	rightPaddle = engine->entityMgr->entities[1]->ogreSceneNode->getPosition();
	ball = engine->entityMgr->entities[2]->ogreSceneNode->getPosition();


	// Left
	if((ball.x - 20) < (leftPaddle.x + 30))
	{
		if( ((ball.y -10) < (leftPaddle.y +95)) && ((ball.y +10) > (leftPaddle.y -95)) )
		{

			engine->entityMgr->entities[2]->direction *= Ogre::Vector3(-1, 1, 1 );
			engine->entityMgr->entities[2]->ogreSceneNode->setPosition((leftPaddle.x + 50), ball.y, ball.z);
		}

	}

	// Right
	else if((ball.x + 20) > (rightPaddle.x - 30))
	{

		if( ((ball.y-10) < (rightPaddle.y + 95)) && ((ball.y+10) > (rightPaddle.y - 95)) )
		{
			engine->entityMgr->entities[2]->direction *= Ogre::Vector3(-1, 1, 1 );
			engine->entityMgr->entities[2]->ogreSceneNode->setPosition((rightPaddle.x - 50), ball.y, ball.z);
		}

	}

}

void GameMgr::createGround(){

	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	  Ogre::MeshManager::getSingleton().createPlane(
	    "ground",
	    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	    plane,
	    15000, 15000, 20, 20,
	    true,
	    1, 5, 5,
	    Ogre::Vector3::UNIT_Z);

	  Ogre::Entity* groundEntity = engine->gfxMgr->ogreSceneManager->createEntity("ground");
	  engine->gfxMgr->ogreSceneManager->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
	  groundEntity->setCastShadows(false);
	  //	  groundEntity->setMaterialName("Ocean2_HLSL_GLSL");
	  //groundEntity->setMaterialName("OceanHLSL_GLSL");
	  groundEntity->setMaterialName("Ocean2_Cg");
	 // groundEntity->setMaterialName("Island");
	  //groundEntity->setMaterialName("NavyCg");

}

void GameMgr::createSky()
{
	engine->gfxMgr->ogreSceneManager->setSkyBox(true, "Examples/MorningSkyBox");

}

void GameMgr::createWall()
{
	Entity381 * ent;

	// Entity[3] Top Wall
	ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(400, 400, 50));
	ent->ogreEntity->setMaterialName("Examples/Rockwall");
	engine->entityMgr->entities[3]->ogreSceneNode->setScale(12, 0.5, 1);

	// Entity[4] Bottom Wall
	ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(400, -400, 50));
	ent->ogreEntity->setMaterialName("Examples/Rockwall");
	engine->entityMgr->entities[4]->ogreSceneNode->setScale(12, 0.5, 1);

	// Entity[5] Left Wall
	ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(-250, 0, 0));
	ent->ogreEntity->setMaterialName("Examples/Rockwall");
	engine->entityMgr->entities[5]->ogreSceneNode->setScale(0.5, 9, 1);

	// Entity[6] Right Wall
	ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(1050, 0, 0));
	ent->ogreEntity->setMaterialName("Examples/Rockwall");
	engine->entityMgr->entities[6]->ogreSceneNode->setScale(0.5, 9, 1);
}





