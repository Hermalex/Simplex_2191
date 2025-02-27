#include "AppClass.h"
using namespace Simplex;
void Application::InitVariables(void)
{
	//Set the position and target of the camera
	m_pCameraMngr->SetPositionTargetAndUpward(	vector3(0.0f, 3.0f, 13.0f), //Position
											vector3(0.0f, 3.0f, 12.0f),	//Target
											AXIS_Y );					//Up

	//Set the position of the light
	m_pLightMngr->SetPosition(vector3(10.0f));

	m_pMyMeshMngr = MyMeshManager::GetInstance();

	//Initialize models
	m_pEntity1 = new MyEntity();
	m_pEntity1->GenerateTorus();
	

	//creeper
	m_pCreeper = new Model();
	m_pCreeper->Load("Minecraft\\Creeper.obj");
	m_pCreeperRB = new RigidBody(m_pCreeper->GetVertexList());

	//steve
	m_pSteve = new Model();
	m_pSteve->Load("Minecraft\\Steve.obj");
	m_pSteveRB= new RigidBody(m_pSteve->GetVertexList());

	//cow
	m_pCow = new Model();
	m_pCow->Load("Minecraft\\Cow.obj");
	m_pCowRB = new RigidBody(m_pCow->GetVertexList());

	//pig
	m_pPig = new Model();
	m_pPig->Load("Minecraft\\Pig.obj");
	m_pPigRB = new RigidBody(m_pPig->GetVertexList());

	//zombie
	m_pZombie = new Model();
	m_pZombie->Load("Minecraft\\Zombie.obj");
	m_pZombieRB = new RigidBody(m_pZombie->GetVertexList());
}
void Application::Update(void)
{
	//Update the system so it knows how much time has passed since the last call
	m_pSystem->Update();

	//Is the arcball active?
	ArcBall();

	//Is the first person camera active?
	CameraRotation();

	m_pEntity1->SetModelMatrix(ToMatrix4(m_qArcBall));
	m_pEntity1->AddToRenderList();
}
void Application::Display(void)
{
	//Clear the screen
	ClearScreen();

	m_pMyMeshMngr->Render();
	m_pMyMeshMngr->ClearRenderList();

	//Add grid to the scene
	m_pMeshMngr->AddGridToRenderList();

	//Add skybox
	m_pMeshMngr->AddSkyboxToRenderList();
	
	//render list call
	m_uRenderCallCount = m_pMeshMngr->Render();

	//clear the render list
	m_pMeshMngr->ClearRenderList();
		
	//draw gui
	DrawGUI();
	
	//end the current frame (internally swaps the front and back buffers)
	m_pWindow->display();
}
void Application::Release(void)
{
	//release the model
	SafeDelete(m_pCreeper);

	//release the rigid body for the model
	SafeDelete(m_pCreeperRB);

	//release the model
	SafeDelete(m_pSteve);

	//release the rigid body for the model
	SafeDelete(m_pSteveRB);

	//release the model
	SafeDelete(m_pZombie);

	//release the rigid body for the model
	SafeDelete(m_pZombieRB);

	//release the model
	SafeDelete(m_pPig);

	//release the rigid body for the model
	SafeDelete(m_pPigRB);

	//release the model
	SafeDelete(m_pCow);

	//release the rigid body for the model
	SafeDelete(m_pCowRB);
	
	//release GUI
	ShutdownGUI();
}
