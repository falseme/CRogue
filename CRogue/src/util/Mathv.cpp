#include "Mathv.h"
#include <cmath>

void Mathv::normalizeAndScale(Vector2f& v, float scale) {

	if (v.x == 0 && v.y == 0)
		return;
	if (v.x == 0) {
		v.y *= (scale / abs(v.y));
		return;
	}
	if (v.y == 0) {
		v.x *= (scale / abs(v.x));
		return;
	}

	float mod = sqrt(v.x * v.x + v.y * v.y);
	v.x *= (scale / mod);
	v.y *= (scale / mod);

}

float Mathv::distance(Vector2f v1, Vector2f v2) {

	Vector2f d = v2 - v1;

	if (d.x == 0 && d.y == 0)
		return 0;
	if (d.x == 0)
		return abs(d.y);
	if (d.y == 0)
		return abs(d.x);

	return sqrt(d.x * d.x + d.y * d.y);

}

