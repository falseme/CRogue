#include "Entity.h"
Entity::Entity(Vector2f pos, Animation anim, float h, float d) : GameObject(pos, anim) {
	SetHealth(h);
	SetDamage(d);

}
float Entity::GetHealth() {
	return health;
}
void Entity::SetHealth(float h) {
	health = h;
}
void Entity::Attacked(float d) {
	health -= d;
}
float Entity::GetDamage() {
	return damage;
}
void Entity::SetDamage(float d) {
	damage = d;
}
void Entity::update() {}