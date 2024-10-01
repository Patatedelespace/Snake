#pragma once

#include "../libs/raylib/src/raylib.h"
#include <vector>
#include <string>


namespace GAMESTATE {
    inline bool PLAYING;
    inline bool PAUSED;

    inline float SCREEN_WIDTH  = 1200.f;
    inline float SCREEN_HEIGHT = 450.f;

    inline float gravity = 0.5;

    inline std::vector<Rectangle> dirt_floors = {
      {0, SCREEN_HEIGHT - 100, SCREEN_WIDTH, 10},
      {751, SCREEN_HEIGHT - 250, 10, 50}
    };

    inline std::string current_music_track = "main music";
}
