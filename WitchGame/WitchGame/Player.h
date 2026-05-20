#pragma once
#include "raylib.h"
class Tree;

class Player {
    float x = 400, y = 400;
    float size = 45;
    float speed = 6;
    int maxHealth = 3;
    int health = maxHealth;
    float invincible = 0;
public:
    void move(Tree* trees, int amount);
    void draw();
    float getPlayerX();
    float getPlayerY();
    float getPlayerSize();
    void damage(int damageTaken);
    int getHealth();
    void gracePeriod(float duration);
    Rectangle getCol();
};
