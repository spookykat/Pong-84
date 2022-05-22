#ifndef BALL_H
#define BALL_H
#include "Line.h"

class Ball
{
    public:
    Ball();
    int Move(float timeDelta, Line *lines);
    void Draw();
    void Reset();

    private:
    float pos_x;
    float pos_y;
    int speed;
    int size;
    bool backward_x;
    bool backward_y;
};
#endif