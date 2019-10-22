#include "MyEntity.h"
using namespace Simplex;
//  MyEntity
void MyEntity::Init(void)
{
	
}
void MyEntity::Swap(MyEntity& other)
{
	
}
void MyEntity::Release(void)
{
	
}
//The big 3
MyEntity::MyEntity()
{
	Init();
	m_pMeshMngr = MyMeshManager::GetInstance();
}
MyEntity::MyEntity(MyEntity const& other)
{
	
}
MyEntity& MyEntity::operator=(MyEntity const& other)
{
	if(this != &other)
	{
		Release();
		Init();
		MyEntity temp(other);
		Swap(temp);
	}
	return *this;
}
MyEntity::~MyEntity()
{
	Release();
};

void MyEntity::GenerateTorus(void)
{
	m_nMeshIndex = m_pMeshMngr->GenerateTorus(1.0f, 0.7f, 12, 12, C_RED);
}

void MyEntity::AddToRenderList(void)
{
	m_pMeshMngr->AddMeshToRenderList(m_nMeshIndex, m_m4ModeltoWorld);
}

void MyEntity::SetModelMatrix(matrix4 a_m4ToWorld) 
{
	m_m4ModeltoWorld = a_m4ToWorld;
}
void Simplex::MyEntity::GenerateRigidBody(void)
{
	MyMesh* pMesh = m_pMeshMngr->GetMesh(m_nMeshIndex);
	m_pRigidBody = new MyRigidBody(pMesh->GetVertexList());
}
//Accessors

//--- Non Standard Singleton Methods

