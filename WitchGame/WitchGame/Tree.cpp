#include "Tree.h"
#include "Player.h"
#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include "Witch.h"


const int cellSize = 50;
const int cellCount = 16;



void Tree::setPos(Player player, Witch witch)
{
    do {
        x = rand() % cellCount*cellSize;
        y = rand() % cellCount * cellSize;
    } while (CheckCollisionRecs({ x, y, static_cast<float>(size), static_cast<float>(size) }, player.getCol()) ||
        CheckCollisionRecs({ x, y, static_cast<float>(size), static_cast<float>(size) }, witch.getCol()));
}

void Tree::draw() {
    DrawRectangle(static_cast<int>(x), static_cast<int>(y), size, size, GREEN);
}

Rectangle Tree::getCol() {
    return { x, y, static_cast<float>(size), static_cast<float>(size) };
}
