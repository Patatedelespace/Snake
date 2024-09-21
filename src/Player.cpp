#include "Player.h"
#include <thread>
#include "GAMESTATE.h"
#include <functional>
#include "utility.h"
#include <iostream>
#include <chrono>


// Core functions


// Operators functions
Player::operator Texture2D() {
    return this->sprite;
}


// Getters functions
Vector2 Player::getPosition() {
    return this->position;
}

Vector2 Player::getVelocity() {
    return this->velocity;
}

int Player::getDirection() {
    return this->direction;
}

Vector2 Player::getRealPosition() {
    return this->real_position;
}

Texture2D Player::getSprite() {
    return this->sprite;
}

Rectangle Player::getRectangle() {
    return this->rectangle;
}

Rectangle Player::getCollisionRectangle() {
    return this->collision_rectangle;
}

double Player::getSpeed() {
    return this->speed;
}

double Player::getJumpStrengh() {
    return this->jump_strengh;
}

double Player::getGravity() {
    return this->gravity;
}


// Setters functions
void Player::setPosition(Vector2 position) {
    this->position = position;
}

void Player::setPositionX(float x) {
    this->position.x = x;
}

void Player::setPositionY(float y) {
    this->position.y = y;
}

void Player::setVelocity(Vector2 velocity) {
    this->velocity = velocity;
}

void Player::setVelocityX(float x) {
    this->velocity.x = x;
}

void Player::setVelocityY(float y) {
    this->velocity.y = y;
}

void Player::setDirection(int direction) {
    this->direction = direction;
}

void Player::setRealPosition(Vector2 real_position) {
    this->real_position = real_position;
}

void Player::setSprite(Texture2D sprite) {
    this->sprite = sprite;
}

void Player::setRectangle(Rectangle rectangle) {
    this->rectangle = rectangle;
}

void Player::setCollisionRectangle(Rectangle rectangle) {
    this->collision_rectangle = rectangle;
}

void Player::setSpeed(double speed) {
    this->speed = speed;
}

void Player::setJumpStrengh(double jump_strengh) {
    this->jump_strengh = jump_strengh;
}

void Player::setGravity(double gravity) {
    this->gravity = gravity;
}


// Other functions
void Player::move(Vector2 velocity) {
    this->collision_rectangle.x = this->position.x; this->collision_rectangle.y = this->position.y;

    // Vector2 previous_position = this->position;

    // this->position.x += velocity.x; this->position.y += velocity.y;

    CollisionType collision_type = NONE;

    this->collision_rectangle.x += velocity.x;

    for (Rectangle i : GAMESTATE::CollisionObjects) {
        // if ( ( ( (this->position.x > i.x) && (this->position.x < i.width) ) || ( (this->position.x + this->rectangle.width > i.x) && (this->position.x + this->rectangle.width < i.width) ) ) && ( ( (this->position.y > i.y)/*under top line*/ && (this->position.y < i.height)/*over bottom line*/ )/*with y*/ || ( (this->position.y + this->rectangle.height > i.y)/*under top line*/ && (this->position.y + this->rectangle.height < i.height)/*over bottom line*/ )/*with height*/  ) ) {
        //     this->position.x = previous_position.x;
        // }
        if (CheckCollisionRecs(this->collision_rectangle, i)) {
            // if ( ( (this->position.y + this->collision_rectangle.height / 2 < i.y) && (this->position.y + this->collision_rectangle.height / 2 < i.y) ) || ( (this->position.y + this->collision_rectangle.height / 2 > i.y) && (this->position.y + this->collision_rectangle.height / 2 > i.y) ) ) {
                   // this->position.y = previous_position.y;
            // }
            collision_type = X;
            break;

        }
    }

    this->collision_rectangle.y += velocity.y;

    for (Rectangle i : GAMESTATE::CollisionObjects) {
        // if ( ( ( (this->position.x > i.x) && (this->position.x < i.width) ) || ( (this->position.x + this->rectangle.width > i.x) && (this->position.x + this->rectangle.width < i.width) ) ) && ( ( (this->position.y > i.y)/*under top line*/ && (this->position.y < i.height)/*over bottom line*/ )/*with y*/ || ( (this->position.y + this->rectangle.height > i.y)/*under top line*/ && (this->position.y + this->rectangle.height < i.height)/*over bottom line*/ )/*with height*/  ) ) {
        //     this->position.x = previous_position.x;
        // }
        if (CheckCollisionRecs(this->collision_rectangle, i)) {
            // if ( ( (this->position.y + this->collision_rectangle.height / 2 < i.y) && (this->position.y + this->collision_rectangle.height / 2 < i.y) ) || ( (this->position.y + this->collision_rectangle.height / 2 > i.y) && (this->position.y + this->collision_rectangle.height / 2 > i.y) ) ) {
                   // this->position.y = previous_position.y;
            // }
            collision_type = (collision_type == NONE) ? Y : X_AND_Y;
            break;

        }
    }

    switch (collision_type) {
        case NONE:
            position.x += velocity.x;
            position.y += velocity.y;
            break;

        case X:
            position.y += velocity.y;
            break;

        case Y:
            position.x += velocity.x;
            break;

        case X_AND_Y:
            break;
    }

    // Rectangle floor = GAMESTATE::CollisionObjects[0];

    std::cout << "Position y : " << this->position.y << " (" << this->position.y + this->collision_rectangle.height / 2 << "; " << this->position.y - this->collision_rectangle.height / 2 << ") Velocity : {x : " << this->velocity.x << "; y : " << this->velocity.y << "}" << std::endl;
}



void Player::resize(int width, int height) {
    this->sprite.width = width; this->sprite.height = height;
    this->rectangle.width = width; this->rectangle.height = height;
}










