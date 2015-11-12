#include "stdio.h"
#include "stdlib.h"
#define size 10
// Create a Program to implement SPARSE MATRIX

struct sparse
{
    int val;
    int row;
    int col;

};
typedef struct sparse MATRIX;

void search(MATRIX sm[],int key);

int main()// You must always return some shit to the compiler
{
    MATRIX sm[size];
    int nr,nc,nv,i,ele,val;
    printf("Enter the number of rows,column and values\n");
    scanf("%d%d%d",&nr,&nc,&nv);

    sm[0].row=nr;
    sm[0].col=nc;
    sm[0].val=nv;

    printf("Enter the elements into the Sparse Matrix:\n");
    for(i=1;i<=nv;i++)
    {
        scanf("%d%d%d",&sm[i].row,&sm[i].col,&sm[i].val);

    }

    printf("The Matrix elements are\n");
    printf("\n\n\tRow\tColumn\tValue\n");
    for(i=1;i<=sm[0].val;i++)
    {
        printf("\nSM[%d]\t%d\t%d\t%d\n",i,sm[i].row,sm[i].col,sm[i].val);

    }
    printf("Enter an element to be searched for \n");
    scanf("%d",&ele);

    search(sm,ele);
    return 0;
}

void search(MATRIX sm[],int key)
{
    int i;
    for(i=1;i<=sm[0].val;i++)
    {
        if(sm[i].val==key)
        {
            printf("Element %d is found at row %d column %d\n",sm[i].val,sm[i].row,sm[i].col);
            return;
        }

    }
    printf("\nElement not found\n");
}
