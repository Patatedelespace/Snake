#pragma once

#include "raylib.h"
#include "GAMESTATE.h"

class Player {
private:
    double speed = 0.1;
    double jump_strengh = 7;
    double gravity = 1;
    Vector2 position = {GAMESTATE::SCREEN_WIDTH / 2, GAMESTATE::SCREEN_HEIGHT / 2};
    Vector2 velocity = {0, 0};
    int direction = 1;
    Vector2 real_position;
    Texture2D sprite;
    Rectangle rectangle;
    bool on_ground;

public:
    // Core functions
    Player(Texture2D sprite) {
        this->position = (Vector2) {GAMESTATE::SCREEN_WIDTH / 2, GAMESTATE::SCREEN_HEIGHT / 2};
        this->sprite = sprite;
        this->rectangle.x = 0; this->rectangle.y = 0;
        this->rectangle.width = this->sprite.width;
        this->rectangle.height = this->sprite.height;
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
    double getSpeed();
    double getJumpStrengh();
    double getGravity();

    // Setters functions
    void setPosition(Vector2 position);
    void setPositionX(int x);
    void setPositionY(int y);
    void setVelocity(Vector2 velocity);
    void setVelocityX(int x);
    void setVelocityY(int y);
    void setDirection(int direction);
    void setRealPosition(Vector2 real_position);
    void setSprite(Texture2D sprite);
    void setRectangle(Rectangle rectangle);
    void setSpeed(double speed);
    void setJumpStrengh(double jump_strengh);
    void setGravity(double gravity);

    // Other functions
    void move(Vector2 velocity);
    void resize(int width, int height);

};
