#include <math.h>

struct Vector2 {
	float x, y;
	float magnitude() {
		return sqrtf(x * x + y * y);
	}
};