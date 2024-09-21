#pragma once

#include "raylib.h"
#include "GAMESTATE.h"

class Player {
private:
    float speed = 0.5;
    float jump_strengh = 12;
    float gravity = 0.5;
    Vector2 position = {GAMESTATE::SCREEN_WIDTH / 2, GAMESTATE::SCREEN_HEIGHT / 2};
    Vector2 velocity = {0.f, 0.f};
    int direction = 1;
    Vector2 real_position;
    Texture2D sprite;
    Rectangle rectangle;
    Rectangle collision_rectangle;
    bool on_ground;
    enum CollisionType {
        NONE = 0,
        X = 1,
        Y = 2,
        X_AND_Y = 3
    };

public:
    // Core functions
    Player(Texture2D sprite) {
        this->position = (Vector2) {GAMESTATE::SCREEN_WIDTH / 2, GAMESTATE::SCREEN_HEIGHT / 2};
        this->sprite = sprite;
        this->rectangle.x = 0; this->rectangle.y = 0;
        this->rectangle.width = this->sprite.width;
        this->rectangle.height = this->sprite.height;
        this->collision_rectangle.x = position.x; this->rectangle.y = position.y;
        this->collision_rectangle.width = this->sprite.width;
        this->collision_rectangle.height = this->sprite.height;
    }

    ~Player() {}

    // Operators functions
    operator Texture2D();

    // Getters functions
    Vector2 getPosition();
    Vector2 getVelocity();
    int getDirection();
    Vector2 getRealPosition();
    Texture2D getSprite();
    Rectangle getRectangle();
    Rectangle getCollisionRectangle();
    double getSpeed();
    double getJumpStrengh();
    double getGravity();

    // Setters functions
    void setPosition(Vector2 position);
    void setPositionX(float x);
    void setPositionY(float y);
    void setVelocity(Vector2 velocity);
    void setVelocityX(float x);
    void setVelocityY(float y);
    void setDirection(int direction);
    void setRealPosition(Vector2 real_position);
    void setSprite(Texture2D sprite);
    void setRectangle(Rectangle rectangle);
    void setCollisionRectangle(Rectangle rectangle);
    void setSpeed(double speed);
    void setJumpStrengh(double jump_strengh);
    void setGravity(double gravity);

    // Other functions
    void move(Vector2 velocity);
    void resize(int width, int height);

};