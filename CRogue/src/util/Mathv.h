#pragma once

#include <SFML/System/Vector2.hpp>
using namespace sf;

class Mathv {
public:
	static void normalizeAndScale(Vector2f& v, float scale);
	static float distance(Vector2f v1, Vector2f v2);
};

