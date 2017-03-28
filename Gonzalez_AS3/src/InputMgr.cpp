/*
 * InputMgr.cpp
 *
 *  Created on: Mar 27, 2017
 *      Author: randygonzalez
 */

#include <InputMgr.h>

InputMgr::InputMgr(Engine *eng) : Mgr(eng)
{



}

InputMgr::~InputMgr()
{

}

void InputMgr::init()
{
	createFrameListener();

	cameraNode = engine->gfxMgr->mSceneMgr->getRootSceneNode()->createChild();
	cameraNode->setPosition(0, 200, 500);
	cameraNode->attachObject(mCamera);
}

void InputMgr::tick(float dt)
{

}

void InputMgr::loadLevel()
{

}

void InputMgr::stop()
{
	return;
}

void InputMgr::updateCamera(const Ogre::FrameEvent& fe)
{
	float move = 400.0f;
	float rotate = 0.1f;

	 Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

	  if (mKeyboard->isKeyDown(OIS::KC_W))
	    dirVec.z -= move;

	  if (mKeyboard->isKeyDown(OIS::KC_S))
	    dirVec.z += move;

	  if (mKeyboard->isKeyDown(OIS::KC_E))
	    dirVec.y += move;

	  if (mKeyboard->isKeyDown(OIS::KC_F))
	    dirVec.y -= move;

	  if (mKeyboard->isKeyDown(OIS::KC_A))
	  {
	    if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
		      cameraNode->yaw(Ogre::Degree(5 * rotate));
	    else
	      dirVec.x -= move;
	  }

	  if (mKeyboard->isKeyDown(OIS::KC_D))
	  {
	    if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
	      cameraNode->yaw(Ogre::Degree(-5 * rotate));
	    else
	      dirVec.x += move;
	  }

	  cameraNode->translate(dirVec * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
}

void InputMgr::updateVelocity(const Ogre::FrameEvent& fe)
{

}


void InputMgr::createFrameListener(void)
{
    Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
    OIS::ParamList pl;
    size_t windowHnd = 0;
    std::ostringstream windowHndStr;

    mWindow->getCustomAttribute("WINDOW", &windowHnd);
    windowHndStr << windowHnd;
    pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

    // insert the following lines right before calling mInputSystem = OIS::InputManager::createInputSystem( paramList );
    #if defined OIS_WIN32_PLATFORM
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_FOREGROUND" )));
    pl.insert(std::make_pair(std::string("w32_mouse"), std::string("DISCL_NONEXCLUSIVE")));
    pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_FOREGROUND")));
    pl.insert(std::make_pair(std::string("w32_keyboard"), std::string("DISCL_NONEXCLUSIVE")));
    #elif defined OIS_LINUX_PLATFORM
    pl.insert(std::make_pair(std::string("x11_mouse_grab"), std::string("false")));
    pl.insert(std::make_pair(std::string("x11_mouse_hide"), std::string("false")));
    pl.insert(std::make_pair(std::string("x11_keyboard_grab"), std::string("false")));
    pl.insert(std::make_pair(std::string("XAutoRepeatOn"), std::string("true")));
    #endif


    mInputManager = OIS::InputManager::createInputSystem(pl);

    mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject(OIS::OISKeyboard, true));
    mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject(OIS::OISMouse, true));

    mMouse->setEventCallback(this);
    mKeyboard->setEventCallback(this);

    // Set initial mouse clipping size
    windowResized(engine->gfxMgr->mWindow);

    // Register as a Window listener
    Ogre::WindowEventUtilities::addWindowEventListener(engine->gfxMgr->mWindow, this);

    mInputContext.mKeyboard = mKeyboard;
    mInputContext.mMouse = mMouse;
    mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", engine->gfxMgr->mWindow, mInputContext, this);
    mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    mTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
    mTrayMgr->hideCursor();

    // Create a params panel for displaying sample details
    Ogre::StringVector items;
    items.push_back("cam.pX");
    items.push_back("cam.pY");
    items.push_back("cam.pZ");
    items.push_back("");
    items.push_back("cam.oW");
    items.push_back("cam.oX");
    items.push_back("cam.oY");
    items.push_back("cam.oZ");
    items.push_back("");
    items.push_back("Filtering");
    items.push_back("Poly Mode");

    engine->gfxMgr->mDetailsPanel = mTrayMgr->createParamsPanel(OgreBites::TL_NONE, "DetailsPanel", 200, items);
    engine->gfxMgr->mDetailsPanel->setParamValue(9, "Bilinear");
    engine->gfxMgr->mDetailsPanel->setParamValue(10, "Solid");
    engine->gfxMgr->mDetailsPanel->hide();

    engine->gfxMgr->mRoot->addFrameListener(this);
}

void InputMgr::createViewPorts(void)
{
    // Create one viewport, entire window
    Ogre::Viewport* vp = engine->gfxMgr->mWindow->addViewport(engine->gfxMgr->mCamera);
    vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

    // Alter the camera aspect ratio to match the viewport
    engine->gfxMgr->mCamera->setAspectRatio(Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}

bool InputMgr::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
	mKeyboard->capture();
	if(mKeyboard->isKeyDown(OIS::KC_ESCAPE))
		return false;

	//mTrayMgr->frameRenderingQueued(fe);

	updateCamera(fe);
	updateVelocity(fe);
	//entityManager->Tick(fe.timeSinceLastFrame);

	return true;
}

bool InputMgr::keyPressed(const OIS::KeyEvent &arg)
{

}

bool InputMgr::keyReleased(const OIS::KeyEvent &arg)
{

}

bool InputMgr::mouseMoved(const OIS::MouseEvent &arg)
{

}

bool InputMgr::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{

}

bool InputMgr::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{

}


void InputMgr::windowResized(Ogre::RenderWindow* rw)
{

}


void InputMgr::windowClosed(Ogre::RenderWindow* rw)
{

}
