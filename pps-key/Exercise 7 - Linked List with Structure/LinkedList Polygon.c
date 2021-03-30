#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point {
   int x;
   int y;
};
typedef struct point Point;

struct listnode {
   Point p;
   struct listnode *next;
};

typedef struct listnode LN;
typedef struct listnode* Polygon;

int next_point(Polygon *gon, Point *p);
float distance(Point *p1, Point *p2);
float iter_perim(Polygon gon);
float recur_perim(Point *start, Polygon gon);

int main(){
   Polygon gon = NULL;
   Point p;
   int i = 0;
   do{
      printf("P%02d: ", ++i);
      scanf(" %d %d", &p.x, &p.y);
   }while(next_point(&gon, &p));

   printf("iterative = %.2f\n", iter_perim(gon));
   printf("recursive = %.2f\n", recur_perim(&gon->p, gon));
   
   //free Polygon list
   Polygon temp = NULL;
   while(gon != NULL)
   {
       temp = gon;
       gon = gon->next;
       free(temp);
   }
   
   return 0;
}

int next_point(Polygon *gon, Point *p){
    
    //create new polygon node
    Polygon new_node = (Polygon)malloc(sizeof(LN));
    new_node->p.x = p->x;
    new_node->p.y = p->y;
    new_node->next = NULL;
    
    if(*gon != NULL)
    {
        Polygon temp = *gon, head = *gon;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        //link
        temp->next = new_node;
        //check
        if(head->p.x == p->x && head->p.y == p->y)
        {
            return 0;
        }
    }else{
        *gon = new_node;
    }
   return 1;
}

float distance(Point *p1, Point *p2){
   float xdiff = p1->x - p2->x;
   float ydiff = p1->y - p2->y;
   return sqrt(xdiff*xdiff + ydiff*ydiff);
}

float iter_perim(Polygon gon){
   float perim = 0.0;
   Polygon temp = gon;
   while(gon->next != NULL && temp != NULL)
   {
       gon = gon->next;
       perim += distance(&(gon->p), &(temp->p));
       temp = gon;
   }
   return perim;
}

float recur_perim(Point *start, Polygon gon){
    if(!(gon->p.x == start->x && gon->p.y == start->y && &(gon->p) != start))
    {
        return distance(&(gon->p), &(gon->next->p)) + recur_perim(start, gon->next);
    }
    return 0.0;
}
