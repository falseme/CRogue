#include "Enemy.h"

Enemy::Enemy(Vector2f pos, Animation anim, BoxCollider collider, float h, float d) : Entity(pos, anim, collider, h, d) {

}
void Enemy::update() {}

void Enemy::onCollision(BoxCollider other) {

}