#ifndef LINE_H
#define LINE_H
class Line{
public:
    Line(int upButton, int downButton, bool secondPlayer);
    void Move(float timeDelta);
    void Draw();
    void Reset();
    float pos_x;
    float pos_y;
    int height;
    int width;

private:
    int speed;
    int upButton;
    int downButton;
    int beginPos[2];
    int i;
};
#endif