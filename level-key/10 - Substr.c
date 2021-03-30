#include<stdio.h>

char* substr(char *s, int from, int len)
{
    char *tmp = s, *a = NULL;
    while(*s != '\0')
    {
        if(s == tmp + from && a == NULL)
        {
            a = s;
        }
        s++;
    }
    
    //*s is now '\0'
    if(tmp+from >= s)
    {
        return NULL;
    }
    
    if(a+len < s)
    {
        *(a+len) = '\0';
    }
    
    return a;
}

int main(){
    char in[128];
    char *out = NULL;
    int from, len;

    printf("Enter: ");
    scanf("%[^\n]s", in);
    
    printf("From: ");
    scanf(" %d", &from);

    printf("Len: ");
    scanf(" %d", &len);

    //call substr appropriately
    out = substr(in, from, len);
    
    if(out != NULL)
        printf("= %s\n", out);
    else
        printf("--empty string--\n");
   
    return 0;
}