#include "Line.h"
#include <keypadc.h>
#include <graphx.h>

Line::Line(int upButton, int downButton, bool secondPlayer){
    speed = 400;
    pos_y = 97;
    height = 46;
    width = 10;
    if (secondPlayer)
    {
        i = 6;
        pos_x = 320 - 25 - width;
    }
    else{
        i = 2;
        pos_x = 25;
    }
    beginPos[0] = pos_x;
    beginPos[1] = pos_y;
    this->upButton = upButton;
    this->downButton = downButton;
}
void Line::Move(float timeDelta){

    if (kb_Data[i] & downButton)
    {
        float new_pos_y = pos_y + timeDelta * speed;
        if (!(new_pos_y + height > 240))
        {
            pos_y = new_pos_y;
        }
    }
    if (kb_Data[i] & upButton)
    {
        float new_line_pos_y = pos_y - timeDelta * speed;
        if (!(new_line_pos_y < 0))
        {
            pos_y = new_line_pos_y;
        }
    }
}
void Line::Draw(){
    gfx_FillRectangle_NoClip(pos_x, pos_y, width, height);
}
void Line::Reset(){
    pos_x = beginPos[0];
    pos_y = beginPos[1];
}