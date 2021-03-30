#include<stdio.h>
#include<stdlib.h>

struct listnode {
  char data;
  struct listnode *nextptr;
};

typedef struct listnode  LISTNODE;
typedef LISTNODE *LNP;

LNP string_to_list(char s[]);
void all_cap(LNP cptr);

int main(){
  LNP head = NULL;
  char line[128];

  printf("Enter: ");
  gets(line);
  
  head = string_to_list(line);
  all_cap(head);
  
  printf("=");
  
  LNP cur = head;
  while(cur != NULL)
  {
      printf("%c", cur->data);
      cur = cur->nextptr;
  }
  
  //free
  while(head->nextptr != NULL)
  {
      cur = head;
      head = head->nextptr;
      free(cur);
  }
  
  if(head != NULL)
  {
      free(head);
  }
  
  return 0;
}

LNP string_to_list(char s[]){ 
  LNP head = NULL, tail;
  int i;
  if (s[0] != '\0') {
    head = malloc(sizeof(LISTNODE));
    head->data = s[0];
    tail = head;
    for (i=1; s[i] != '\0'; i++){
      tail->nextptr = malloc(sizeof(LISTNODE));
      tail = tail->nextptr;
      tail->data = s[i];
    }
    tail->nextptr = NULL; /* list end */
  }
  return head;
}

void all_cap(LNP cptr)
{
    while(cptr != NULL)
    {
        if(cptr->data >= 'a' && cptr->data <= 'z')
        {
            cptr->data = 'A' + (cptr->data - 'a');
        }
        cptr = cptr->nextptr;
    }
}
