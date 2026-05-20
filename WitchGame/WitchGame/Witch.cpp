#include "Witch.h"
#include "raylib.h"
#include "Player.h"
#include <cmath>
#include "Tree.h"

void Witch::follow(float X, float Y, Tree* trees, int amount)
{
    bool collideX = false, collideY=false;
    float nextX, nextY;
    if ((fabs(X - x) > 0.01f))
    {
        float step = fmin(speed, fabs(X - x));
        nextX = x + (X > x ? step : -step);
        Rectangle nextXCol = { nextX,y,size,size };
        for (int i = 0; i < amount; i++)
        {
            if (CheckCollisionRecs(nextXCol, trees[i].getCol()))
            {
                collideX = true;
                break;
            }
        }
        if (!collideX) x = nextX;
        else if ((fabs(Y - y) > 0.01f))
        {
            float step = fmin(speed, fabs(Y - y));
            nextY = y + (Y > y ? step : -step);
            Rectangle nextYCol = { x,nextY,size,size };
            for (int i = 0; i < amount; i++)
            {
                if (CheckCollisionRecs(nextYCol, trees[i].getCol()))
                {
                    collideY = true;
                    break;
                }
            }
            if (!collideY) y = nextY;
        }
    }
    else if ((fabs(Y - y) > 0.01f))
    {
        float step = fmin(speed, fabs(Y - y));
        nextY = y + (Y > y ? step : -step);
        Rectangle nextYCol = { x,nextY,size,size };
        for (int i = 0; i < amount; i++)
        {
            if (CheckCollisionRecs(nextYCol, trees[i].getCol()))
            {
                collideY = true;
                break;
            }
        }
        if (!collideY) y = nextY;
    }
    if (collideX && collideY)
    {
        y = y + (Y > y ? size : -size);
        x = x + (X > x ? size : -size);
    }

}
void Witch::draw()
{
    DrawRectangle(static_cast<int>(x), static_cast<int>(y), static_cast<int>(size),
        static_cast<int>(size), RED);
}
float Witch::getWitchX() { return x; }
float Witch::getWitchY() { return y; }
float Witch::getWitchSize() { return size; }

Rectangle Witch::getCol()
{
    return { x,y,size,size };
}
