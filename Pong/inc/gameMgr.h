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
	void moveBall();
	void moveAI(float dt);

	Ogre::Vector3 ball, leftPaddle, rightPaddle; //position of all objects
	Ogre::Vector3 dirVec;
	Ogre::Vector3 AIVector;

	float y = 0.0f;
	bool singlePlayer = true; // game by default is single player

	Ogre::Vector3 currentDir, currentVel;


public:
	GameMgr(Engine *engine);
	~GameMgr();
	void init();
	void tick(float dt);
	void loadLevel();
	void stop();


};



#endif /* GAMEMGR_H_ */
