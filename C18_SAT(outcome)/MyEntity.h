/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2017/06
----------------------------------------------*/
#ifndef __MYENTITY_H_
#define __MYENTITY_H_

#include "Simplex\Simplex.h"
#include "MyRigidBody.h"
#include "MyMeshManager.h"

namespace Simplex
{

//System Class
class MyEntity
{
	MyMeshManager* m_pMeshMngr = nullptr;
	MyRigidBody* m_pRigidBody = nullptr;

	//-1 so we know that nothing has been initalized
	int m_nMeshIndex = -1;
	matrix4 m_m4ModeltoWorld;

public:
	/*
	Usage: Constructor
	Arguments: ---
	Output: class object instance
	*/
	MyEntity(void);
	/*
	Usage: Copy Constructor
	Arguments: class object to copy
	Output: class object instance
	*/
	MyEntity(MyEntity const& other);
	/*
	Usage: Copy Assignment Operator
	Arguments: class object to copy
	Output: ---
	*/
	MyEntity& operator=(MyEntity const& other);
	/*
	Usage: Destructor
	Arguments: ---
	Output: ---
	*/
	~MyEntity(void);

	/*
	Usage: Changes object contents for other object's
	Arguments: other -> object to swap content from
	Output: ---
	*/
	void Swap(MyEntity& other);

	/*
	Usage: Gets data member
	Arguments: ---
	Output: data
	*/
	int GetData(void);
	/*
	Usage: Sets data member
	Arguments: int a_nData = 1 -> data to set
	Output: ---
	*/
	void SetData(int a_nData = 1);
	/* Property */
	//__declspec(property(get = GetData, put = SetData)) int Data;

	/*
	Usage: adds data on vector
	Arguments: int a_nData -> data to add
	Output: ---
	*/
	void SetDataOnVector(int a_nData);
	/*
	Usage: gets data on vector at the specified entry
	Arguments: int a_nIndex -> entry index 
	Output: entry's content
	*/
	int& GetDataOnVector(int a_nIndex);

private:
	/*
	Usage: Deallocates member fields
	Arguments: ---
	Output: ---
	*/
	void Release(void);
	/*
	Usage: Allocates member fields
	Arguments: ---
	Output: ---
	*/
	void Init(void);

public:
	void GenerateTorus(void);
	void AddToRenderList(void);
	void SetModelMatrix(matrix4 a_m4ToWorld);
	void GenerateRigidBody(void);
};//class

} //namespace Simplex

#endif //__MYENTITY_H__

/*
USAGE:
ARGUMENTS: ---
OUTPUT: ---
*/