#include "Object.hpp"

namespace phun
{
	Object::Object()
	{

	}

	Object::Object(const std::initializer_list<Vector>& vertices, const std::initializer_list<unsigned short>& indices):
		vertices_(vertices), indices_(indices)
	{

	}

	void Object::AddVertex(const Vector& vec)
	{
		vertices_.push_back(vec);
	}

	void Object::AddTriangle(const int& firstVertex, const int& secondVertex, const int& thirdVertex)
	{
		indices_.push_back(firstVertex);
		indices_.push_back(secondVertex);
		indices_.push_back(thirdVertex);
	}

	size_t Object::GetVertexCount() const
	{
		return vertices_.size();
	}

	size_t Object::GetTriangleCount() const
	{
		return indices_.size();
	}

	const float* Object::GetVertices() const
	{
		float* ret = new float[vertices_.size() * 3 * sizeof(float)];
		for (int i = 0; i < vertices_.size(); i++)
		{
			Vector vec = vertices_[i];
			ret[3 * i] = vec.x();
			ret[3 * i+1] = vec.y();
			ret[3 * i+2] = vec.z();
		}
		return ret;
	}

	const unsigned short* Object::GetIndices() const
	{
		return indices_.data();
	}
}