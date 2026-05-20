#include <iostream>
#include "raylib.h"
#include "Player.h"
#include "Tree.h"
#include "Witch.h"

const int cellSize = 50;
const int cellCount = 16;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Player player;
    Witch witch;

    Vector2 v = { 350,200 };

    int treeNum = 35;
    Tree* trees = new Tree[treeNum];

    Texture2D spriteSheet = LoadTexture("bar 3.png");
    const int frameCount = 6;
    const int frameWidth = spriteSheet.width / frameCount;
    const int frameHeight = spriteSheet.height;
    Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)frameHeight };
    int currentFrame = 0;
    int frameCounter = 0;
    int framesSpeed = 10;


    InitWindow(cellSize*cellCount, cellSize * cellCount, "Witch Game");

    SetTargetFPS(60);

    for (int i = 0; i < treeNum; i++)
    {
        trees[i].setPos(player,witch);
    }

    while (!WindowShouldClose())
    {
        frameCounter++;
        if (frameCounter >= (60 / framesSpeed))
        {
            frameCounter = 0;
            currentFrame++;
            if (currentFrame >= frameCount) currentFrame = 0;

            frameRec.x = (float)currentFrame * frameWidth;
        }
        player.move(trees,treeNum);
        witch.follow(player.getPlayerX(),player.getPlayerY(),trees,treeNum);

        if (CheckCollisionRecs(player.getCol(), witch.getCol()))
        {
            player.damage(1);
            player.gracePeriod(0.1);
        }

        if (player.getHealth() == 0) break;

        BeginDrawing();
        for (int i = 0; i < treeNum; i++)
        {
            trees[i].draw();
        }

        ClearBackground(DARKGREEN);
        player.draw();
        witch.draw();
        EndDrawing();
    }
    UnloadTexture(spriteSheet);
    CloseWindow();

    return 0;
}