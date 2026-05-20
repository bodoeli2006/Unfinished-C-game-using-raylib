#pragma once
#include "raylib.h"
#include "Witch.h"
class Player;
class Witch;

class Tree {
    float x;
    float y;
    int size = 45;
    Rectangle collision = { x, y, static_cast<float>(size), static_cast<float>(size) };
public:
    void setPos(Player player, Witch witch);
    void draw();
    Rectangle getCol();
};
