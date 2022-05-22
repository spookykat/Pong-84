#include "Ball.h"
#include <tice.h>
#include <stdlib.h>
#include <graphx.h>

Ball::Ball(){
    pos_x = 190;
    pos_y = 120;
    speed = 250;
    size = 5;
    backward_x = randInt(0,1);
    backward_y = randInt(0,1);
}
void Ball::Draw(){
    gfx_FillCircle(pos_x, pos_y, size);
}
int Ball::Move(float timeDelta, Line *lines){
    if (gfx_CheckRectangleHotspot(pos_x, pos_y, size, size, lines[0].pos_x, lines[0].pos_y, lines[0].width, lines[0].height) || gfx_CheckRectangleHotspot(pos_x, pos_y, size, size, lines[1].pos_x, lines[1].pos_y, lines[1].width, lines[1].height))
    {
        backward_x = !backward_x;
    }
    if (pos_y > 240 - size || pos_y < 0 + size) {
        backward_y = !backward_y;
    }

    if(!backward_x){
        pos_x += timeDelta * speed;
    }
    else{
        pos_x -= timeDelta * speed;
    }

    if(!backward_y){
        pos_y += timeDelta * speed;
    }
    else{
        pos_y -= timeDelta * speed;
    }
    if (pos_x < 0)
    {
        return 2;
    }
    else if (pos_x > 340)
    {
        return 1;
    }
    
    
    return 0;
}
void Ball::Reset(){
    pos_x = 160;
    pos_y = 120;
    backward_x = randInt(0,1);
    backward_y = randInt(0,1);
}