#pragma once

#include "raylib.h"
#include <vector>


namespace GAMESTATE {
    inline bool PLAYING;
    inline bool PAUSED;

    inline float SCREEN_WIDTH  = 1200.f;
    inline float SCREEN_HEIGHT = 450.f;

    inline float gravity = 0.5;

    inline std::vector<Rectangle> CollisionObjects = {
      {0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, 10},
      {751, SCREEN_HEIGHT - 200, 10, 50}
    };
}
