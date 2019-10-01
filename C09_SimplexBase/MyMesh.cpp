#include "MyMesh.h"
using namespace Simplex;
//  MyMesh
void MyMesh::Init(void)
{
	m_nData = 0;
}
void MyMesh::Swap(MyMesh& other)
{
	std::swap(m_nData, other.m_nData);
	std::swap(m_lData, other.m_lData);
}
void MyMesh::Release(void)
{
	m_lData.clear();
}
void MyMesh::AssignShape(uint a_uShader)
{
	m_uShaderID = a_uShader;
}
void MyMesh::GenerateShape(void)
{
	//vertex 1
	m_lVertex.push_back(vector3(-0.25f, -0.25f, 0.0f)); //position
	m_lVertex.push_back(vector3(1.0f, 0.0f, 0.0f)); //color
	//vertex 2
	m_lVertex.push_back(vector3(0.25f, -0.25f, 0.0f)); //position
	m_lVertex.push_back(vector3(0.0f, 1.0f, 0.0f)); //color
	//vertex 3
	m_lVertex.push_back(vector3(0.0f, 0.25f, 0.0f)); //position
	m_lVertex.push_back(vector3(0.0f, 0.0f, 1.0f)); //color
}
void MyMesh::ComplieOpenGL_3X(void)
{
	glGenVertexArrays(1, &m_uVAO);//Generate vertex array object
	glGenBuffers(1, &m_uVBO);//Generate Vertex Buffered Object

	glBindVertexArray(m_uVAO);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);//Bind the VBO

	//Generate space for the VBO (vertex count times size of vec3)
	glBufferData(GL_ARRAY_BUFFER, m_lVertex.size() * sizeof(vector3), &m_lVertex[0], GL_STATIC_DRAW);

	//count the attributes
	int attributeCount = 2;

	// Position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, attributeCount * sizeof(vector3), (GLvoid*)0);

	// Color attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, attributeCount * sizeof(vector3), (GLvoid*)(1 * sizeof(vector3)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);//Bind the VBO
	glBindVertexArray(0);//Bind the VAO
}
void MyMesh::Render(void)
{
	//View and projection matrix
	matrix4 m4View;//view matrix
	matrix4 m4Projection;//projection matrix

	//read uniforms and send values
	GLuint MVP = glGetUniformLocation(m_uShaderProgramID, "MVP");//Model View Projection
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(m4Projection * m4View * m_m4Model));

	//draw content
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
//The big 3
MyMesh::MyMesh() { Init(); }
MyMesh::MyMesh(MyMesh const& other)
{
	m_nData = other.m_nData;
	m_lData = other.m_lData;
}
MyMesh& MyMesh::operator=(MyMesh const& other)
{
	if (this != &other)
	{
		Release();
		Init();
		MyMesh temp(other);
		Swap(temp);
	}
	return *this;
}
MyMesh::~MyMesh() { Release(); };
//Accessors

//--- Non Standard Singleton Methods

