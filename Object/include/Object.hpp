#pragma once
#include <Vector.hpp>
#include <vector>
#include <initializer_list>

namespace phun
{
	class Object
	{
	public:
		Object();
		Object(const std::initializer_list<Vector>& vertices, const std::initializer_list<unsigned short>& indices);

		void AddVertex(const Vector& vec);

		void AddTriangle(const int& first, const int& second, const int& third);

		size_t GetVertexCount() const;
		size_t GetTriangleCount() const;

		const float* GetVertices() const;

		const unsigned short* GetIndices() const;

	private:
		std::vector<Vector> vertices_;
		std::vector<unsigned short> indices_;
	};
}