#include <stdio.h>
#include <stdlib.h>

struct listnode{
    int data;
    struct listnode *next;
};

typedef struct listnode LN;
typedef LN *LNP;

void push(LNP *sptr, int v);
int pop(LNP *sptr);

int main(){
    LNP stack = NULL;
    int buff, i = 1;
    
    do{
        printf("N%02d: ", i++);
        scanf(" %d", &buff);
        if(buff > 0)
        {
            push(&stack, buff);
        }
    }while(buff > 0);
    
    printf("= ");
    while(stack != NULL)
    {
        printf("%d ", pop(&stack));
    }
    printf("\n");
    
    //free stack
    while(stack != NULL)
    {
        pop(&stack);
    }
    return 0;
}

void push(LNP *sptr, int v)
{
    
    LNP new_node = (LNP)malloc(sizeof(LN));
    new_node->data = v;
    new_node->next = NULL;
    
    if(*sptr == NULL)
    {
        *sptr = new_node;
    }else{
        new_node->next = *sptr;
        *sptr = new_node;
    }
}

int pop(LNP *sptr)
{
    int temp;
    LNP curr = *sptr;
    if(curr == NULL)
    {
        return 0;
    }
    
    temp = curr->data;
    curr = curr->next;
    free(*sptr);
    *sptr = NULL;
    *sptr = curr;
    
    return temp;
}
