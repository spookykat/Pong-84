#include <stdlib.h>
#include <graphx.h>
#include <tice.h>
#include "Ball.h"
#include "Line.h"
#include <keypadc.h>

Ball *ball = new Ball();
Line *lines = new Line[2] {Line(kb_Log, kb_Ln, false), Line(kb_Mul, kb_Sub, true)};
int *scoreboard = new int[2] {0,0};

void begin(){
    timer_Enable(1, TIMER_32K, TIMER_NOINT, TIMER_UP);
    rtc_Enable(0);
    srand(rtc_Time());
    gfx_SetTextScale(2,2);
}
void end(){
    delete ball;
    delete [] lines;
    delete [] scoreboard;
}
void drawScoreboard(){
    gfx_SetTextXY(126, 5);
    gfx_PrintInt(scoreboard[0], 2);

    gfx_Rectangle(159, 2, 2, 20);

    gfx_SetTextXY(164, 5);
    gfx_PrintInt(scoreboard[1], 2);
}

void draw(){
    ball->Draw();
    for (int i = 0; i < 2; i++)
    {
        lines[i].Draw();
    }
    drawScoreboard();
}
void step(float timeDelta){
    for (int i = 0; i < 2; i++)
    {
        lines[i].Move(timeDelta);
    }
    int gameOver = ball->Move(timeDelta, lines);
    if (gameOver != 0)
    {
        for (int i = 0; i < 2; i++)
        {
            lines[i].Reset();
        }
        ball->Reset();
        scoreboard[gameOver - 1]++;
    }
}
int main(void) {
    begin();
    gfx_Begin();
    gfx_SetDrawBuffer(); 
    do
    {
        kb_Scan();
        timer_Set(1,0);
        gfx_FillScreen(255);
        float timeDelta = timer_Get(1) / 32768.0f;

        step(timeDelta);
        draw();
        
        gfx_SwapDraw();
    } while (!(kb_Data[6] & kb_Clear));
    gfx_End();
    end();
    return 0;
}