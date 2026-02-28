#pragma once
#include "Tuple.hpp"
#include "Matrix.hpp"

namespace  rt
{
	class Object {
	public:
		Matrix	inv_transform;

		Object()
			: inv_transform(Matrix::Identity(4)) {};
	};

	class Sphere : public Object {

	};
}
