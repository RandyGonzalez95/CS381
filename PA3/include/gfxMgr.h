/*
 * gfxMgr.h
 *
 *  Created on: Mar 28, 2017
 *      Author: randy
 */

#ifndef INCLUDE_GFXMGR_H_
#define INCLUDE_GFXMGR_H_

#include <mgr.h>

class Engine;

class GfxMgr : public Mgr
{
public:
	GfxMgr(Engine *eng);
	virtual ~GfxMgr();

	virtual void tick(float dt);
	virtual void init();
	virtual void loadLevel();
	virtual void stop();

	// Set up Graphics Engine
	bool setup();
	void setupResources(void);
	bool configure();
	void loadResources(void);
	void chooseSceneManager(void);
	void createCamera();
	void createViewports(void);
	void render();





	// All Ogre Variables for Graphics Engine
	Ogre::Root* 			mRoot;
	Ogre::String 			mResourcesCfg;
	Ogre::String			mPluginsCfg;

	Ogre::RenderWindow *	mWindow;
	Ogre::SceneManager*		mSceneMgr;
	Ogre::Camera*			mCamera;


    Ogre::String            m_ResourcePath;
private:
};



#endif /* INCLUDE_GFXMGR_H_ */
