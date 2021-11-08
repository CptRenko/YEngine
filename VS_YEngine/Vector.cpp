#include "Vector.h"
#include <math.h>

vec3_t Vector::vec3_rotate_x(vec3_t v, float angle)
{
	vec3_t _v{
		.x = v.x,
		.y = v.y * static_cast<float>(cos(angle)) - v.z * static_cast<float>(sin(angle)),
		.z = v.y * static_cast<float>(sin(angle)) + v.z * static_cast<float>(cos(angle))
	};

	return _v;
}

vec3_t Vector::vec3_rotate_y(vec3_t v, float angle)
{
	vec3_t _v{
		.x = v.x * static_cast<float>(cos(angle)) - v.z * static_cast<float>(sin(angle)),
		.y = v.y,
		.z = v.x * static_cast<float>(cos(angle)) + v.z * static_cast<float>(cos(angle))
	};

	return _v;
}

vec3_t Vector::vec3_rotate_z(vec3_t v, float angle)
{
	vec3_t _v{
		.x = v.x * static_cast<float>(cos(angle)) - v.y * static_cast<float>(sin(angle)),
		.y = v.x * static_cast<float>(sin(angle)) + v.y * static_cast<float>(cos(angle)),
		.z = v.z
	};

	return _v;
}

