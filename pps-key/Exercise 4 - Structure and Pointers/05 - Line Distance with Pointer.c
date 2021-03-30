#include<stdio.h>
#include<math.h>

typedef struct{
    int x;
    int y;
} Point;

void point_input(Point *p);
float line_distance(Point *p1, Point *p2);

int main(){
    
    Point A, B;
    printf("P1: ");
    point_input(&A);
    printf("P2: ");
    point_input(&B);
    
    printf("=%.2f", line_distance(&A, &B));
    return 0;
}

void point_input(Point *p)
{
    scanf(" %d%d", &p->x, &p->y);
}

float line_distance(Point *p1, Point *p2)
{
    return sqrt(pow(p2->x - p1->x,2) + pow(p2->y - p1->y,2));
}
