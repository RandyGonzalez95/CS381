/*
 * GxfMgr.h
 *
 *  Created on: Mar 9, 2017
 *      Author: sushil
 */

#ifndef GFXMGR_H_
#define GFXMGR_H_

#include <mgr.h>

#include <OgreRoot.h>
#include <OgreConfigFile.h>
#include <OgreRenderWindow.h>
#include <OgreSceneManager.h>
#include <OgreCamera.h>
#include <OgreSceneNode.h>
#include <OgreViewport.h>
#include <OgreEntity.h>
#include <OgreWindowEventUtilities.h>


class GfxMgr : public Mgr {

private:
	//Ogre variables
	Ogre::Root *ogreRoot;

	Ogre::String resources;
	Ogre::String plugins;
	Ogre::ConfigFile cf;
	void loadConfig(Ogre::ConfigFile cf);
	void configureRenderSystem();
	void initResources();

	void createSceneManager();
	void createCamera();
	Ogre::Viewport *ogreViewport;
	void createViewport();

public:

	GfxMgr(Engine *eng);
	~GfxMgr();

	void tick(float dt);
	void init();
	void loadLevel();
	void stop();

	Ogre::RenderWindow* ogreRenderWindow;
	Ogre::SceneManager* ogreSceneManager;
	Ogre::SceneNode *cameraNode, *pitchNode;
	Ogre::Camera* ogreCamera;


	void testScene();

};



#endif /* GFXMGR_H_ */
