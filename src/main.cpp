#include "../libs/raylib/src/raylib.h"
#include "Player.h"
#include "GAMESTATE.h"
#include <iostream>
#include <map>

void player_process(Player& player);

std::map<std::string, Sound> musics_list = {
    {"main music", LoadSound(ASSETS_PATH"main_bg_music.mp3")}
};

int main()
{
    InitAudioDevice();

    InitWindow(GAMESTATE::SCREEN_WIDTH, GAMESTATE::SCREEN_HEIGHT, "Snake (en faite c'était plus fun de faire un platformer) (tkt frère pour les copyrights)");
    SetWindowIcon(LoadImage(ASSETS_PATH"Icon.png"));
    SetTargetFPS(60);

    Player player = Player(LoadTexture(ASSETS_PATH"Player.png"));

    float player_scale_divisor = 16;

    player.resize(player.getRectangle().width / player_scale_divisor, player.getRectangle().height / player_scale_divisor);

    GAMESTATE::PLAYING = true;

    PlaySound(musics_list[std::string("main music")]);

    SetMasterVolume(0.1);

    while (!WindowShouldClose()) {

        player_process(player);

        // if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_RIGHT)) player_velocity.x = 0;
        // else if (IsKeyDown(KEY_LEFT)) player_velocity.x = -1;
        // else if (IsKeyDown(KEY_RIGHT)) player_velocity.x = 1;
        // else player_velocity.x = 0;

        // player_velocity.x = ((int)IsKeyDown(KEY_RIGHT) - (int)IsKeyDown(KEY_LEFT)) * player_speed;
        //
        // if (player_velocity.x != 0) {
        //     if (player_velocity.x < 0) player_direction = -1;
        //     if (player_velocity.x > 0) player_direction = 1;
        // }
        //
        // if (IsKeyPressed(KEY_SPACE)) player_velocity.y = -player_jump_strengh;
        //
        // if (player_velocity.y < player_jump_strengh) player_velocity.y += gravity;
        //
        // player_position.x += player_velocity.x; player_position.y += player_velocity.y;

        BeginDrawing();

        ClearBackground(BLUE);

        // Rectangle draw_player_rectangle = {0, 0, (float)player.getRectangle().width * player.getDirection(), (float)player.getRectangle().height};

        // Rectangle floor = {0, (float)GetScreenHeight() - 10, (float)GetScreenWidth(), 10};

        // DrawTextureRec(player.getSprite(), player.getRectangle(), player.getRealPosition(), WHITE);
        DrawTextureRec(player.getSprite(), player.getRectangle(), player.getPosition(), WHITE);

        // DrawRectangle(0, GetScreenHeight() - 10, GetScreenWidth(), 10, GREEN);

        // std::cout << "{" << std::endl;

        for (Rectangle i : GAMESTATE::dirt_floors) {
            DrawRectangle(i.x, i.y, i.width, i.height, GREEN);
            // std::cout << "  {" << i.x << ", " << i.y << ", " << i.width << ", " << i.height << "}" << std::endl;
        }

        // DrawCircle(player.getPosition().x, player.getPosition().y, 1.f, RED);
        DrawLineEx({player.getCollisionRectangle().x + player.getCollisionRectangle().width, player.getCollisionRectangle().y}, {player.getCollisionRectangle().x + player.getCollisionRectangle().width, player.getCollisionRectangle().y + player.getCollisionRectangle().height}, 1, RED);

        // std::cout << "}" << std::endl;

        EndDrawing();
    }

    GAMESTATE::PLAYING = false;

    UnloadTexture(player);

    CloseWindow();
    return 0;
}

void player_process(Player& player) {
    // player.setVelocityX(0);

    // player.setVelocityX((IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT)) * player.getSpeed());

    float player_x_movement;

    if ((IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT)) || (!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT))) {

        if (player.getVelocity().x < 0.2 && player.getVelocity().x > -0.2) {
            player_x_movement = 0;
        }
        else {
            std::cout << "no key detected." << std::endl;

            int velocity_x_sign = (player.getVelocity().x > 0) - (player.getVelocity().x < 0);

            switch (velocity_x_sign) {

                case -1:
                    std::cout << "stopping left movement" << std::endl;
                    player_x_movement = (-player.getMoveSmoothness() > player.getVelocity().x) ? player.getVelocity().x + player.getMoveSmoothness() : 0;
                    break;

                case 1:
                    std::cout << "stopping right movement" << std::endl;
                    player_x_movement = (player.getMoveSmoothness() < player.getVelocity().x) ? player.getVelocity().x - player.getMoveSmoothness() : 0;
                    break;

            }

        }
    }
    else if (IsKeyDown(KEY_RIGHT)) {
        player_x_movement = (player.getVelocity().x < player.getSpeed()) ? player.getVelocity().x + player.getMoveSmoothness() : player.getSpeed();
    }
    else if (IsKeyDown(KEY_LEFT)) {
        player_x_movement = (player.getVelocity().x > -player.getSpeed()) ? player.getVelocity().x - player.getMoveSmoothness() : -player.getSpeed();
    }


    player.setVelocityX(player_x_movement);

    std::cout << player.getVelocity().x << ";" << player.getVelocity().y << "(" << ((int)IsKeyDown(KEY_RIGHT) - (int)IsKeyDown(KEY_LEFT)) * player.getSpeed() << ")" << std::endl;

    if (player.getVelocity().x != 0) {
        // if (player.velocity.x < 0) player.direction = -1;
        // if (player.velocity.x > 0) player.direction = 1;
        player.setDirection((player.getVelocity().x < 0) ? -1 : 1);
    }

    if (IsKeyDown(KEY_SPACE) && player.isOnGround()) player.setVelocityY(-player.getJumpStrengh());

    if (player.getVelocity().y < player.getJumpStrengh()) {
        // std::cout << "Must fall down" << std::endl;
        player.setVelocityY(player.getVelocity().y + GAMESTATE::gravity);
        // std::cout << player.getVelocity().y + GAMESTATE::gravity << std::endl;
    }

    player.move();

    // player.position = (Vector2) {player.position.x, (float)crop(0, GAMESTATE::SCREEN_HEIGHT, player.position.y)};

    player.setRealPosition((Vector2) {player.getPosition().x - player.getRectangle().width / 2, player.getPosition().y - player.getRectangle().width /2});

    // std::cout << "Position : {" << player.getPosition().x << "; " << player.getPosition().y << "}" << std::endl;
    // std::cout << "Velocity : {" << player.getVelocity().x << "; " << player.getVelocity().y << "}" << std::endl;

    player.setCollisionRectangle((Rectangle){player.getPosition().x, player.getPosition().y, player.getRectangle().width, player.getRectangle().height});
}
