/*
 * gfxMgr.cpp
 *
 *  Created on: Mar 28, 2017
 *      Author: randy
 */
#include <gfxMgr.h>
#include <engine.h>

GfxMgr::GfxMgr(Engine *eng) : Mgr(eng)
{
	mRoot = 0;
    mResourcesCfg = Ogre::StringUtil::BLANK;
    mPluginsCfg = Ogre::StringUtil::BLANK;

    mWindow = 0;
    mSceneMgr = 0;
    mCamera = 0;

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
    m_ResourcePath = Ogre::macBundlePath() + "/Contents/Resources/";
#else
    m_ResourcePath = "";
#endif

}

GfxMgr::~GfxMgr()
{
	delete mRoot;
}

void GfxMgr::tick(float dt)
{
	Ogre::WindowEventUtilities::messagePump();

	if(mWindow->isClosed())
		engine->keepRunning = false;

	if(!mRoot->renderOneFrame(dt))
		engine->keepRunning = false;
}

void GfxMgr::init()
{
#ifdef _DEBUG
#ifndef OGRE_STATIC_LIB
    mResourcesCfg = m_ResourcePath + "resources_d.cfg";
    mPluginsCfg = m_ResourcePath + "plugins_d.cfg";
#else
    mResourcesCfg = "resources_d.cfg";
    mPluginsCfg = "plugins_d.cfg";
#endif
#else
#ifndef OGRE_STATIC_LIB
    mResourcesCfg = m_ResourcePath + "resources.cfg";
    mPluginsCfg = m_ResourcePath + "plugins.cfg";
#else
    mResourcesCfg = "resources.cfg";
    mPluginsCfg = "plugins.cfg";
#endif
#endif

    if(!setup())
    	return;

}

void GfxMgr::loadLevel()
{

}

void GfxMgr::stop()
{

}

bool GfxMgr::setup()
{
	mRoot = new Ogre::Root(mPluginsCfg);

	setupResources();

	if(!configure())
		return false;

    // Set default mipmap level (NB some APIs ignore this)
    Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

    // initialize all resources found by ogre
    loadResources();

    // create manager from root
    chooseSceneManager();
    createCamera();
    createViewports();

    //render();

	return true;
}

void GfxMgr::setupResources(void)
{
    // Load resource paths from config file
    Ogre::ConfigFile cf;
    cf.load(mResourcesCfg);

    // Go through all sections & settings in the file
    Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

    Ogre::String secName, typeName, archName;
    while (seci.hasMoreElements())
    {
        secName = seci.peekNextKey();
        Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
        Ogre::ConfigFile::SettingsMultiMap::iterator i;
        for (i = settings->begin(); i != settings->end(); ++i)
        {
            typeName = i->first;
            archName = i->second;

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
            // OS X does not set the working directory relative to the app.
            // In order to make things portable on OS X we need to provide
            // the loading with it's own bundle path location.
            if (!Ogre::StringUtil::startsWith(archName, "/", false)) // only adjust relative directories
                archName = Ogre::String(Ogre::macBundlePath() + "/" + archName);
#endif

            Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
                archName, typeName, secName);
        }
    }
}

bool GfxMgr::configure(void)
{
    // Show the configuration dialog and initialise the system.
    // You can skip this and use root.restoreConfig() to load configuration
    // settings if you were sure there are valid ones saved in ogre.cfg.
    if(mRoot->showConfigDialog())
    {
        // If returned true, user clicked OK so initialise.
        // Here we choose to let the system create a default rendering window by passing 'true'.
        mWindow = mRoot->initialise(true, "CS381 - Assignment Three");

        return true;
    }
    else
    {
        return false;
    }
}

void GfxMgr::loadResources(void)
{
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void GfxMgr::chooseSceneManager(void)
{
    // Get the SceneManager, in this case a generic one
    mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

}

void GfxMgr::createCamera(void)
{
    // Create the camera
    mCamera = mSceneMgr->createCamera("PlayerCam");

    // Position it at 500 in Z direction
    mCamera->setPosition(Ogre::Vector3(0,0,80));
    // Look back along -Z
    mCamera->lookAt(Ogre::Vector3(0,0,-300));
    mCamera->setNearClipDistance(5);

    //mCameraMan = new OgreBites::SdkCameraMan(mCamera);   // Create a default camera controller
}

void GfxMgr::createViewports(void)
{
    // Create one viewport, entire window
    Ogre::Viewport* vp = mWindow->addViewport(mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}

void GfxMgr::render()
{
	  // Create Scene
	  Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");

	  Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	  ogreNode->attachObject(ogreEntity);

	  mSceneMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));

	  Ogre::Light* light = mSceneMgr->createLight("MainLight");
	  light->setPosition(20, 80, 50);

}
