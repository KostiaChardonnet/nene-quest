#include <entity.hpp>
#include <math.h>
using namespace sf;

std::vector<sf::RectangleShape*> Entity::getHitboxes() {
	return hitboxes;
}

std::vector<sf::RectangleShape*> Entity::getZHitboxes() {
	return zHitboxes;
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for (auto h : hitboxes)
		target.draw(*h, states);
	
	target.draw(sprite, states);
}

void Entity::setPosition(int x, int y)
{
	sprite.setPosition(x,y);
	for (auto h : hitboxes)
		h->setPosition(x,y);
}

Vector2f Entity::getPosition() {
    //return hitbox.getPosition();
	return hitboxes.at(0)->getPosition();			//Mixed feelings about this
}

void Entity::updateAutoHitboxPosition(){
	hitboxes.at(0)->setPosition(sprite.getGlobalBounds().left, sprite.getGlobalBounds().top);
}

void Entity::updateAutoHitboxSize(){
	hitboxes.at(0)->setSize(Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height));
}

Vector2f Entity::getSpriteSize(){
    return Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
}

void Entity::updateAutoSpritePosition(){
	sprite.setPosition(hitboxes.at(0)->getGlobalBounds().left, hitboxes.at(0)->getGlobalBounds().top);
}

float Entity::getDepth(){
    return hitboxes.at(0)->getGlobalBounds().top + hitboxes.at(0)->getGlobalBounds().height;	//Same about this line
}

float Entity::getDrawDepth(){
    return this->getDepth();
}

void Entity::move(sf::Vector2f v) {
	//maybe we can do it directly here instead of each of the entities
	sprite.move(v);
	for (auto h : hitboxes)
		h->move(v);
	for (auto zh : zHitboxes)
		zh->move(v);
}

EntityType Entity::getEntityType() {
	return NONE;
}

void Entity::update(float elapsedTime) {
	//do nothing
}

bool Entity::isDead() {
	return false;
}

float Entity::distanceToPosition(sf::Vector2f position) {
	return sqrtf(powf(this->getPosition().x - position.x, 2) + powf(this->getPosition().y - position.y, 2));
}