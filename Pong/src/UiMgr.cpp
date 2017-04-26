/*
 * UiMgr.cpp
 *
 *  Created on: Apr 12, 2017
 *      Author: chad
 */

#include <UiMgr.h>
#include <engine.h>
#include <vector>

UiMgr::UiMgr(Engine* eng): Mgr(eng), mTrayMgr(0)
{
	// Initialize the OverlaySystem (changed for Ogre 1.9)
	    mOverlaySystem = new Ogre::OverlaySystem();
	    engine->gfxMgr->ogreSceneManager->addRenderQueueListener(mOverlaySystem);

	    //Ogre::WindowEventUtilities::addWindowEventListener(engine->gfxMgr->ogreRenderWindow, this);
}

UiMgr::~UiMgr(){ // before gfxMgr destructor

}

void UiMgr::init()
{
	//init sdktrays

    mInputContext.mKeyboard = engine->inputMgr->keyboard;
    mInputContext.mMouse = engine->inputMgr->mouse;
    mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", engine->gfxMgr->ogreRenderWindow, mInputContext, this);
    //mTrayMgr->showFrameStats(OgreBites::TL_BOTTOMLEFT);
    //mTrayMgr->showLogo(OgreBites::TL_BOTTOMRIGHT);
    //mTrayMgr->showCursor();
    //mTrayMgr->showBackdrop();
    //mTrayMgr->hideCursor();
}

void UiMgr::stop()
{

}

void UiMgr::loadLevel()
{

	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().create("Background", "General");
	material->getTechnique(0)->getPass(0)->createTextureUnitState("pong.png");
	material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
	material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(false);

	mTrayMgr->showBackdrop("Background");

	//OgreBites::SelectMenu* menu = mTrayMgr->createThickSelectMenu(OgreBites::TL_CENTER, "MyMenu", "Menu", 200, 3);
	//OgreBites::Button *b = mTrayMgr->createButton(OgreBites::TL_TOPLEFT, "MyButton", "Click Me!");
	//OgreBites::SelectMenu* menu = mTrayMgr->createLongSelectMenu(OgreBites::TL_CENTER, "MyMenu", "Menu", 200, 100, 400);
	//Ogre::Bites SelectMenu *menu = mTrayMgr->createThickSelectMenu(OgreBites::TL_CENTER, "MyMenu", "Menu", 300, 3);

	//OgreBites::Label *label = mTrayMgr->createLabel(OgreBites::TL_NONE, "Label", "Caption", 200);
}

void UiMgr::tick(float dt)
{
	mTrayMgr->refreshCursor();
}

void UiMgr::windowResized(Ogre::RenderWindow* rw)
{
	unsigned int width, height, depth;
	int left, top;
	rw->getMetrics(width, height, depth, left, top);

	const OIS::MouseState &ms = engine->inputMgr->mouse->getMouseState();
	ms.width = width;
	ms.height = height;
}

void UiMgr::windowClosed(Ogre::RenderWindow* rw)
{

}

bool UiMgr::keyPressed(const OIS::KeyEvent &arg)
{
	std::cout << "Key Pressed: " << arg.key << std::endl;
	return true;
}
bool UiMgr::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}
bool UiMgr::mouseMoved(const OIS::MouseEvent &arg)
{
    if (mTrayMgr->injectMouseMove(arg)) return true;
    /* normal mouse processing here... */
	return true;
}
bool UiMgr::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	std::cout << "mouse clicked" << std::endl;
	if (mTrayMgr->injectMouseDown(arg, id)) return true;
	    /* normal mouse processing here... */
	return true;
}
bool UiMgr::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
    if (mTrayMgr->injectMouseUp(arg, id)) return true;
    /* normal mouse processing here... */
	return true;
}

void UiMgr::buttonHit(OgreBites::Button *b)
{
    if(b->getName()=="MyButton")
    {
        std::cout <<"Click Me!" << std::endl;
        //mTrayMgr->hideBackdrop();
    }

}

void UiMgr::itemSelected(OgreBites::SelectMenu *m)
{
    if(m->getName()=="MyMenu")
    {
        std::cout <<"Menu!" << std::endl;
    }

}
