#include<stdio.h>
#include<math.h>

struct point{
    int x;
    int y;
};
typedef struct point Point;

Point point_input()
{
    Point p;
    scanf(" %d %d", &p.x, &p.y);
    return p;
}

float line_distance(Point p1, Point p2)
{
    return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
}

int main(){
    
    Point A,B;
    
    printf("P1: ");
    A = point_input();
    printf("P2: ");
    B = point_input();
    
    printf("=%.2f", line_distance(A,B));
    return 0;
}
