#pragma once
#include "Tuple.hpp"
#include "Matrix.hpp"

namespace  rt
{
	class Object {
	public:
		Matrix	inv_transform;
		Tuple	origin;


		Object()
			: inv_transform(Matrix::Identity(4)), origin(Tuple()) {};
	};

	class Sphere : public Object {

	};
}
