/*
 * as2.h
 *
 *  Created on: Mar 6, 2017
 *      Author: randygonzalez
 */

#ifndef INCLUDE_AS2_H_
#define INCLUDE_AS2_H_

#include "BaseApplication.h"
#include "EntityMgr.h"

class AS2 : public BaseApplication
{

public:
	AS2();
	virtual ~AS2();
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

	void RenderGround();
	void RenderSky();
	void UpdateCamera(const Ogre::FrameEvent& fe);
	void UpdateVelocity(const Ogre::FrameEvent& fe);
	void UpdatePosition(const Ogre::FrameEvent& fe);


protected:
	virtual void CreateScene();

private:
	EntityMgr *entityManager;
	float yaw;
	float deltaVeloctiy;
	Ogre::Vector3 velocity, position;
	float keyboardTimer;
	const static float keyTime = 0.01f;
};




#endif /* INCLUDE_AS2_H_ */
