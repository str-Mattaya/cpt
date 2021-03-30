#include <stdio.h>

int detA(int a[3][3]);

int main()
{
    
    int matrix[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    
    int row, col;
    
    while(1)
    {
        printf("Enter: ");
        scanf("%d%d", &row,&col);
        scanf("%d", &matrix[row][col]);
        if(row == -1)
        {
            break;
        }
    }
    
    printf("=%d", detA(matrix));
    
    return 0;
}

int detA(int a[3][3])
{
    int result = 0;
    int i;
    for(i=0;i<3;i++)
    {
        result += a[i%3][0]*a[(i+1)%3][1]*a[(i+2)%3][2];
    }
    for(i=0;i<3;i++)
    {
        result -= a[i%3][2]*a[(i+1)%3][1]*a[(i+2)%3][0];
    }
    return result;
}