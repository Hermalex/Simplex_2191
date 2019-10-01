/*----------------------------------------------
Programmer: Alberto Bobadilla (labigm@gmail.com)
Date: 2017/06
----------------------------------------------*/
#ifndef __MyMesh_H_
#define __MyMesh_H_

#include "Simplex\Simplex.h"

namespace Simplex
{

	//System Class
	class MyMesh
	{
		uint m_uVAO = 0; //States of the state machine
		uint m_uVBO = 0; //Buffered list of vertex
		uint m_uShaderProgramID = 0; //Shader to use
		uint m_uVertexCount = 0; //How many verteices the model has
		std::vector<glm::vec3> m_lVertex; //List of vertecies
		matrix4 m_m4Model = IDENTITY_M4; //where the model is in space

	public:
		/*
		Usage: Indicate which shader to use
		Arguments: uint a_uShader -> The shader to use
		Output: ---
		*/
		void AssignShape(uint a_uShader);
		/*
		Usage: Make a simple shape
		Arguments: ---
		Output: ---
		*/
		void GenerateShape(void);
		/*
		Usage: Initalize the VAO and VBO
		Arguments: ---
		Output: ---
		*/
		void ComplieOpenGL_3X(void);
		/*
		Usage: Initalize the VAO and VBO
		Arguments: ---
		Output: ---
		*/
		void Render(void);
		/*
		Usage: Constructor
		Arguments: ---
		Output: class object instance
		*/
		MyMesh(void);
		/*
		Usage: Copy Constructor
		Arguments: class object to copy
		Output: class object instance
		*/
		MyMesh(MyMesh const& other);
		/*
		Usage: Copy Assignment Operator
		Arguments: class object to copy
		Output: ---
		*/
		MyMesh& operator=(MyMesh const& other);
		/*
		Usage: Destructor
		Arguments: ---
		Output: ---
		*/
		~MyMesh(void);

		/*
		Usage: Changes object contents for other object's
		Arguments: other -> object to swap content from
		Output: ---
		*/
		void Swap(MyMesh& other);

		/*
		Usage: Gets data member
		Arguments: ---
		Output: data
		*/

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
	};//class

} //namespace Simplex

#endif //__MyMesh_H__

/*
USAGE:
ARGUMENTS: ---
OUTPUT: ---
*/
