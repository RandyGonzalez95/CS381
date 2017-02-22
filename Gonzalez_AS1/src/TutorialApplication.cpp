/*
 * Copyright 2017
 * Randy Gonzalez
 * CS 381
 * UNR
 * randygonzalez@nevada.unr.edu
 */

#include "TutorialApplication.h"

TutorialApplication::TutorialApplication()	: mRotate(.13),
											  mMove(250),
											  mCamNode(0),
											  mDirection(Ogre::Vector3::ZERO),
											  surfaceHeight(10000),
											  cubeVel(Ogre::Vector3::ZERO)
{
}

TutorialApplication::~TutorialApplication()
{
}

void TutorialApplication::createScene()
{
  mSceneMgr->setAmbientLight(Ogre::ColourValue(.25, .25, .25));

  // Set Light
  Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
  pointLight->setType(Ogre::Light::LT_POINT);
  pointLight->setPosition(250, 150, 250);
  pointLight->setDiffuseColour(Ogre::ColourValue::White);
  pointLight->setSpecularColour(Ogre::ColourValue::White);

  // Create Cube
  Ogre::Entity* cubeEntity = mSceneMgr->createEntity("cube.mesh");
  Ogre::SceneNode* cubeNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    "NinjaNode");
  cubeNode->attachObject(cubeEntity);
  cubeEntity->setMaterialName("Borg/borg");

  // Create Plane
  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

  Ogre::MeshManager::getSingleton().createPlane(
    "ground",
    Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    plane, 10000, surfaceHeight, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

  groundEntity->setMaterialName("Examples/Rockwall");
  groundEntity->setCastShadows(false);

  // Attach Camera Node
  mCamNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
          "CamNode", Ogre::Vector3(0, 400, 1000));

  mCamNode->attachObject(mCamera);

}

bool TutorialApplication::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);

  mCamNode->translate(mDirection * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);

  // computes the velocity of the cube each frame
  mSceneMgr->getSceneNode("NinjaNode")->translate(cubeVel * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);


  return ret;
}

bool TutorialApplication::keyPressed(const OIS::KeyEvent& ke)
{


	switch (ke.key)
	{
	  // Move Camera Node
	  case OIS::KC_ESCAPE:
		mShutDown = true;
		break;

	  case OIS::KC_W:
		mDirection.z = -mMove;
		break;

	  case OIS::KC_S:
		mDirection.z = mMove;
		break;

	  case OIS::KC_A:
		mDirection.x = -mMove;
		break;

	  case OIS::KC_D:
		mDirection.x = mMove;
		break;

	  case OIS::KC_E:
		mDirection.y = mMove;
		break;

	  case OIS::KC_F:
		mDirection.y = -mMove;
	    break;


	// Move Cube Node
	  case OIS::KC_NUMPAD8:
	    cubeVel.z -= mMove;
	    break;

	  case OIS::KC_NUMPAD2:
	    cubeVel.z += mMove;
	    break;

	  case OIS::KC_NUMPAD4:
		cubeVel.x -= mMove;
	    break;

	  case OIS::KC_NUMPAD6:
		cubeVel.x += mMove;
		break;

	  case OIS::KC_PGDOWN:
		cubeVel.y -= mMove;
		break;

	  case OIS::KC_PGUP:
		cubeVel.y += mMove;
		break;

	  case OIS::KC_SPACE:
		cubeVel.x = 0;
		cubeVel.y = 0;
		cubeVel.z = 0;
		break;

	  default:
		break;
	 }

  return true;
}

bool TutorialApplication::keyReleased(const OIS::KeyEvent& ke)
{
	switch (ke.key)
	{
	// Stop Moving Camera on Release
	case OIS::KC_W:
		mDirection.z = 0;
		break;

	case OIS::KC_S:
		mDirection.z = 0;
		break;

	case OIS::KC_A:
		mDirection.x = 0;
		break;

	case OIS::KC_D:
		mDirection.x = 0;
		break;

	case OIS::KC_E:
		mDirection.y = 0;
		break;

	case OIS::KC_F:
		mDirection.y = 0;
		break;


	default:
		break;
	}


	return true;
}


#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
  int main(int argc, char *argv[])
#endif
  {
    // Create application object
    TutorialApplication app;

    try {
      app.go();
    } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox(
        NULL,
        e.getFullDescription().c_str(),
        "An exception has occurred!",
        MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
      std::cerr << "An exception has occurred: " <<
	e.getFullDescription().c_str() << std::endl;
#endif
    }

    return 0;
  }

#ifdef __cplusplus
}
#endif
