#include "Player.h"
#include "Tree.h"
#include "raylib.h"

void Player::move(Tree* trees, int amount) {
    if (invincible > 0.0f)
    {
        invincible -= GetFrameTime();
        if (invincible < 0.0f) invincible = 0.0f;
    }
    float nextX, nextY;
    bool collides = false;

    if (IsKeyDown(KEY_A)) {
        nextX = x - speed;
        Rectangle nextLeft = { nextX,y,size,size };
        for (int i = 0; i < amount; i++)
        {
            if (CheckCollisionRecs(nextLeft, trees[i].getCol()))
            {
                collides = true;
                break;
            }
        }
        if (!collides) x = nextX;
    }
    else if (IsKeyDown(KEY_W))
    {
        nextY = y - speed;
        Rectangle nextUp = { x,nextY,size,size };
        for (int i = 0; i < amount; i++)
        {
            if (CheckCollisionRecs(nextUp, trees[i].getCol()))
            {
                collides = true;
                break;
            }
        }
        if (!collides)y = nextY;
    }
    else if (IsKeyDown(KEY_D))
    {
        nextX = x + speed;
        Rectangle nextRight = { nextX,y,size,size };
        for (int i = 0; i < amount; i++)
        {
            if (CheckCollisionRecs(nextRight, trees[i].getCol()))
            {
                collides = true;
                break;
            }

        }
        if (!collides)x = nextX;
    }
    else if (IsKeyDown(KEY_S))
    {
        nextY = y + speed;
        Rectangle nextDown = { x,nextY,size,size };
        for (int i = 0; i < amount; i++)
        {
            if (CheckCollisionRecs(nextDown, trees[i].getCol()))
            {
                collides = true;
                break;
            }

        }
        if (!collides)y = nextY;
    }
}

void Player::draw() {
    DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(size),
        static_cast<int>(size), RAYWHITE);
    int circX = 50;
    for (int i = 0; i < health; i++)
    {
        DrawCircle(circX, 50, 10, RED);
        circX += 25;
    }
}

float Player::getPlayerX() { return x; }
float Player::getPlayerY() { return y; }
float Player::getPlayerSize() { return size; }
void Player::damage(int damageTaken) {
    if (invincible > 0.0f) return;
    if (health != 0) health -= damageTaken;
}
int Player::getHealth() { return health; }
void Player::gracePeriod(float duration) { invincible = duration; }

Rectangle Player::getCol()
{
    return { x,y,size,size };
}
