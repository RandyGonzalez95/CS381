/*
 * gameMgr.h
 *
 *  Created on: Mar 11, 2017
 *      Author: sushil
 */

#ifndef GAMEMGR_H_
#define GAMEMGR_H_

#include <mgr.h>
#include <OgreVector3.h>


class GameMgr : public Mgr
{

private:
	void createEnts();
	void createSky();
	void createGround();
	void createWall();
	void hitPaddle();
	float bounceBall(Ogre::Vector3 ballPos, Ogre::Vector3 paddlePos, float paddleHeight);
	void createPowerup(float dt);
	void instantiate();
	void checkPowerUp(float dt);
	void activatePP(float dt);
	void moveBall();
	void resetPowerUps();
	void randomizePP();
	void createMaterials();
	void moveAI(float dt);
	void wait(float dt);

	Ogre::Vector3 ball, leftPaddle, rightPaddle; //position of all objects
	Ogre::Vector3 dirVec;
	Ogre::Vector3 AIVector;
	Ogre::Vector3 powerupPos;

	// Power Ups
	bool purple = false, pink = false;

	float y = 0.0f;
	bool singlePlayer = true; // game by default is single player

	// Cooldown for powerups
	float timer, timer2;
	const float currentTime = 11.0f, currentTime2 = 5.0f; // in seconds

	bool powerUp = false;
	bool activated = false;

	int size = 0;

	Ogre::Vector3 currentDir, currentVel;


public:
	GameMgr(Engine *engine);
	~GameMgr();
	void init();
	void tick(float dt);
	void loadLevel();
	void stop();

	bool green = false;

};



#endif /* GAMEMGR_H_ */
