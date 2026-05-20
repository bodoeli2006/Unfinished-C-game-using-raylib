#pragma once
#include "raylib.h"
#include "Tree.h"
class Tree;

class Witch {
    float x = 200, y = 150;
    float size = 45;
    float speed = 3;
public:
    void follow(float, float, Tree*, int);
    void draw();
    float getWitchX();
    float getWitchY();
    float getWitchSize();
    Rectangle getCol();
};