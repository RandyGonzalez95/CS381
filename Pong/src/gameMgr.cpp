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

	// Start the ball paused
	engine->entityMgr->entities[2]->speed = 0.0f;
	//pause = true;
}

void GameMgr::stop()
{

}

void GameMgr::tick(float dt)
{
	hitPaddle();

	// if we have one player, Move AI
	if(engine->uiMgr->singlePlayer)
		moveAI(dt);

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

	dirVec = Ogre::Vector3(1,-1,0);
	AIVector = Ogre::Vector3(1,-1,0);

}

void GameMgr::hitPaddle()
{
	// Grab Positions of all entities
	leftPaddle = engine->entityMgr->entities[0]->ogreSceneNode->getPosition();
	rightPaddle = engine->entityMgr->entities[1]->ogreSceneNode->getPosition();
	ball = engine->entityMgr->entities[2]->ogreSceneNode->getPosition();

	// Check where the ball is at
	moveBall();

	// Left
	if((ball.x -20) < (leftPaddle.x+40))
	{
		if( ((ball.y -20) < (leftPaddle.y +95)) && ((ball.y +20) > (leftPaddle.y -95)) )
		{
			// ball has gone past the paddle
			if(ball.x < leftPaddle.x-30)
				return;

			// Find the direction the ball should go
			y = bounceBall(ball, leftPaddle, 102);
			dirVec = Ogre::Vector3(-1, y, ball.z);

			// Set the direction of the ball and have it go back to the other side
			engine->entityMgr->entities[2]->direction = dirVec;
			engine->entityMgr->entities[2]->direction *= Ogre::Vector3(-1, 1, 1 );

			// Set the position at the left side of the paddle
			engine->entityMgr->entities[2]->ogreSceneNode->setPosition((leftPaddle.x + 60), ball.y, ball.z);

		}

	}

	// Right
	else if((ball.x + 20) > (rightPaddle.x - 40))
	{


		if( ((ball.y-20) < (rightPaddle.y + 95)) && ((ball.y+20) > (rightPaddle.y - 95)) )
		{
			// ball has gone past the paddle
			if(ball.x+10 > rightPaddle.x+30)
				return;

			// else
			engine->entityMgr->entities[2]->direction *= Ogre::Vector3(-1, 1, 1 );
			engine->entityMgr->entities[2]->ogreSceneNode->setPosition((rightPaddle.x - 60), ball.y, ball.z);
		}

	}

}

void GameMgr::moveBall()
{
	ball = engine->entityMgr->entities[2]->ogreSceneNode->getPosition();

	// Grab current direction and velocity of the ball
	currentDir = engine->entityMgr->entities[2]->direction;
	currentVel = engine->entityMgr->entities[2]->velocity;


	// Check Left Side
	if((ball.x - 40) <= -250)
	{
		// Reset the Ball
		engine->entityMgr->entities[2]->ogreSceneNode->setPosition(400, 0, 0);
		engine->entityMgr->entities[2]->direction *= Ogre::Vector3(-1, 1, 1 );

		// Update Score
		engine->entityMgr->entities[2]->score2++;

		engine->entityMgr->entities[2]->speed = 0.0f;
		engine->inputMgr->pause = true;

	}
	// Check Right Wall
	else if((ball.x + 40) >= 1050)
	{
		engine->entityMgr->entities[2]->ogreSceneNode->setPosition(400, 0, 0);
		engine->entityMgr->entities[2]->direction *= Ogre::Vector3(-1, 1, 1 );

		// Update Score
		engine->entityMgr->entities[2]->score1++;

		engine->entityMgr->entities[2]->speed = 0.0f;
		engine->inputMgr->pause = true;

	}
	//Check Top
	else if((ball.y +40) >= 400 && engine->entityMgr->entities[2]->direction.y > 0)
	{
		engine->entityMgr->entities[2]->ogreSceneNode->setPosition(ball.x, 360, ball.z);
		engine->entityMgr->entities[2]->direction *= Ogre::Vector3(1, -1, 1 );

	}
	// Check Bottom
	else if((ball.y -40 ) <= -400 && engine->entityMgr->entities[2]->direction.y < 0)
	{
		engine->entityMgr->entities[2]->ogreSceneNode->setPosition(ball.x, -360, ball.z);
		engine->entityMgr->entities[2]->direction *= Ogre::Vector3(1, -1, 1 );
	}
}

float GameMgr::bounceBall(Ogre::Vector3 ballPos, Ogre::Vector3 paddlePos, float paddleHeight)
{
	return(ballPos.y - paddlePos.y)/paddleHeight;
}

void GameMgr::moveAI(float dt)
{

	// Get Position of Ball and the AI
	ball = engine->entityMgr->entities[2]->ogreSceneNode->getPosition();
	rightPaddle = engine->entityMgr->entities[1]->ogreSceneNode->getPosition();


	// Find Distance between the ball and the paddle
	float relativePos = ball.y - rightPaddle.y;


	// Have the AI move to the ball
	if(relativePos > 0)
	{
		AIVector.y = std::min(relativePos, 1.0f);
		AIVector.x = 0;
	}
	if(relativePos < 0)
	{
		AIVector.y = -1 * std::min(-relativePos, 1.0f);
		AIVector.x = 0;
	}

	// Set the direction and speed of the AI
	engine->entityMgr->entities[1]->direction = AIVector;
	engine->entityMgr->entities[1]->speed = 400;

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
	int x = -100;
	int y = -450;

	// Entity[3] Top Wall
	for(int i = 0; i < 12; i++)
	{
		ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(x, 450, 0));
		ent->ogreEntity->setMaterialName("Examples/Rockwall");
		x += 100;
		//engine->entityMgr->entities[3]->ogreSceneNode->setScale(12, 0.5, 1);
	}

	// reset x value
	x = -100;

	// Entity[4] Bottom Wall
	for(int i = 0; i< 12; i++)
	{
		ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(x, -450, 0));
		ent->ogreEntity->setMaterialName("Examples/Rockwall");
		x += 100;
	}

	//engine->entityMgr->entities[4]->ogreSceneNode->setScale(12, 0.5, 1);

	// Entity[5] Left Wall
	for(int i = 0; i < 10; i++)
	{
		ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(-200, y, 0));
		ent->ogreEntity->setMaterialName("Examples/Rockwall");
		y+= 100;
	}

	y = -450;

	//engine->entityMgr->entities[5]->ogreSceneNode->setScale(0.5, 9, 1);

	// Entity[6] Right Wall
	for(int i = 0; i < 10; i++)
	{
		ent = engine->entityMgr->CreateEntity(EntityType::Wall, Ogre::Vector3(1050, y, 0));
		ent->ogreEntity->setMaterialName("Examples/Rockwall");
		y += 100;
	}

	//engine->entityMgr->entities[6]->ogreSceneNode->setScale(0.5, 9, 1);
}





