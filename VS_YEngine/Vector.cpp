#include "Vector.h"
#include <math.h>

vec3_t Vector::vec3_rotate_x(vec3_t v, float angle)
{
	vec3_t _v{
		.x = v.x,
		.y = v.y * cos(angle) - v.z * sin(angle),
		.z = v.y * sin(angle) + v.z * cos(angle)
	};

	return _v;
}

vec3_t Vector::vec3_rotate_y(vec3_t v, float angle)
{
	vec3_t _v{
		.x = v.x * cos(angle) - v.z * sin(angle),
		.y = v.y,
		.z = v.x * cos(angle) + v.z * cos(angle)
	};

	return _v;
}

vec3_t Vector::vec3_rotate_z(vec3_t v, float angle)
{
	vec3_t _v{
		.x = v.x * cos(angle) - v.y * sin(angle),
		.y = v.x * sin(angle) + v.y * cos(angle),
		.z = v.z
	};

	return _v;
}

