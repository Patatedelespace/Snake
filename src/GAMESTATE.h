#pragma once

#include <vector>


namespace GAMESTATE {
    inline bool PLAYING;
    inline bool PAUSED;

    inline float SCREEN_WIDTH  = 1200.f;
    inline float SCREEN_HEIGHT = 450.f;

    inline std::vector<Rectangle> CollisionObjects = {
      {0, SCREEN_HEIGHT - 50, SCREEN_WIDTH, 10}
    };
}

