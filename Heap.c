#include "stdio.h"
#define max 10

void insertHeap(int ele, int heap[], int *n)
{
    int i;
    if(*n==max)
    {
        printf("Heap is full\n");
    }
    i=++(*n);
    while(i!=1&&ele>heap[i/2])
    {
        heap[i]=heap[i/2];
        i=i/2;
    }
    heap[i]=ele;
}

void display(int heap[],int n)
{
    int i;
    if(n==0)
        printf("heap is empty");
    for(i=1;i<=n;i++)
    {
        printf("%d\n",heap[i]);
    }
}
int main()
{
    int heap[max],n=0,ele=0,choice;
    for(;;)
    {
        printf("Enter 1 to insert 2 to display, 3 to exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the element to insert\n");
                    scanf("%d",&ele);
                    insertHeap(ele,heap,&n);
                    break;
            case 2: display(heap,n);break;
            case 3: exit(0);
        }
    }
return 0;
}
