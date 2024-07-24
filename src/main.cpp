#include "raylib.h"
#include "Player.h"
#include "GAMESTATE.h"
#include <iostream>

void player_process(Player& player);

int main()
{
    InitWindow(GAMESTATE::SCREEN_WIDTH, GAMESTATE::SCREEN_HEIGHT, "Snake (en faite c'était plus fun de faire un platformer) (tkt frère pour les copyrights)");
    SetWindowIcon(LoadImage(ASSETS_PATH"Icon.png"));
    SetTargetFPS(60);

    Player player = Player(LoadTexture(ASSETS_PATH"Player.png"));

    float player_scale_divisor = 16;

    player.resize(player.getRectangle().width / player_scale_divisor, player.getRectangle().height / player_scale_divisor);

    GAMESTATE::PLAYING = true;

    while (!WindowShouldClose())
    {

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
        DrawTextureRec(player.getSprite(), player.getRectangle(), player.getRealPosition(), WHITE);

        // DrawRectangle(0, GetScreenHeight() - 10, GetScreenWidth(), 10, GREEN);

        std::cout << "{" << std::endl;

        for (Rectangle i : GAMESTATE::CollisionObjects) {
            DrawRectangle(i.x, i.y, i.width, i.height, GREEN);
            std::cout << "  {" << i.x << ", " << i.y << ", " << i.width << ", " << i.height << "}" << std::endl;
        }

        std::cout << "}" << std::endl;

        EndDrawing();
    }

    GAMESTATE::PLAYING = false;

    UnloadTexture(player);

    CloseWindow();
    return 0;
}

void player_process(Player& player) {
    // player.setVelocityX(0);

    player.setVelocityX(((int)IsKeyDown(KEY_RIGHT) - (int)IsKeyDown(KEY_LEFT)) * player.getSpeed() /** delta*/);

    if (player.getVelocity().x != 0) {
        // if (player.velocity.x < 0) player.direction = -1;
        // if (player.velocity.x > 0) player.direction = 1;
        player.setDirection((player.getVelocity().x < 0) ? -1 : 1);
    }

    if (IsKeyPressed(KEY_SPACE)) player.setVelocityY(-player.getJumpStrengh());

    if (player.getVelocity().y < player.getJumpStrengh()) {
        // std::cout << "Must fall down" << std::endl;
        player.setVelocityY(player.getVelocity().y + player.getGravity());
        // std::cout << player.getVelocity().y + player.getGravity() << std::endl;
    }

    player.move(player.getVelocity());

    // player.position = (Vector2) {player.position.x, (float)crop(0, GAMESTATE::SCREEN_HEIGHT, player.position.y)};

    player.setRealPosition((Vector2) {player.getPosition().x - player.getRectangle().width / 2, player.getPosition().y - player.getRectangle().width /2});

    // std::cout << "Position : {" << player.getPosition().x << "; " << player.getPosition().y << "}" << std::endl;
    // std::cout << "Velocity : {" << player.getVelocity().x << "; " << player.getVelocity().y << "}" << std::endl;
}

