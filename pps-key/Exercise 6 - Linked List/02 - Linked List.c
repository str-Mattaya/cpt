#include<stdio.h>
#include <stdlib.h>

typedef struct node {
    int v;
    struct node *next;
} LN;

typedef LN* LNP;

LNP append_node(LNP tail, int v);
int length(LNP head);
void print_list(LNP head);
void print_reverse_list(LNP head);
int sum(LNP head); 
void free_list(LNP *head);

int main(){
    LNP head, tail;
    int v;
    
    head = tail =(LNP)malloc(sizeof(LN));
    tail->v = 0;
    tail->next = NULL;
    
    //iteratively append list node, DO NOT forget to update the tail
    do
    {
        printf("Enter: ");
        scanf("%d", &v);
        
        //append and update
        if(v >= 0)
        {
            tail = append_node(tail, v);
        }
        
    }while(v >= 0);
    
    printf("---Result---\n");

    //process your list here!
    printf("Len=%d\n", length(head));
    printf("List=");
    print_list(head);
    printf("\nReverse=");
    print_reverse_list(head);
    printf("\nSum=%d", sum(head));

    //free your list here!
    free_list(&head);

    return 0;
}

LNP append_node(LNP tail, int v)
{
    if(tail != NULL)
    {
        LNP new_node = (LNP)malloc(sizeof(LN));
        new_node->next = NULL;
        new_node->v = v;
        tail->next = new_node;
        tail = tail->next;
    }
    return tail;
}

int length(LNP head)
{
    if(head == NULL)
    {
        return 0;
    }
    return 1 + length(head->next);
}

void print_list(LNP head)
{
    if(head != NULL)
    {
        printf("%d ", head->v);
        print_list(head->next);
    }
}

void print_reverse_list(LNP head)
{
    if(head != NULL)
    {
        print_reverse_list(head->next);
        printf("%d ", head->v);
    }
}

int sum(LNP head)
{
    if(head == NULL)
    {
        return 0;
    }
    return head->v + sum(head->next);
}

void free_list(LNP *head)
{
    LNP curr = *head;
    while(*head != NULL)
    {
        
        *head = (*head)->next;
        
        free(curr);
        curr = *head;
    }
}