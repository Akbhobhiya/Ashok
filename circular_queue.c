#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front=-1,rear=-1,cqueue[MAX];
void enqueue();
void dequeue();
int isFull()
{
    if( (front == rear + 1) || (front == 0 && rear == MAX-1)) return 1;
    return 0;
}
int isEmpty()
{
    if(front == -1) return 1;
    return 0;
}
void main()
{
	int ch;
	while(1)
	{
		printf("1.enqueue\n2.dequeue\n3.Exit");
		printf("\nEnter your choice(1-3):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: exit(0);
			default: printf("\nWrong Choice!!\n");
		}
	}
}
void enqueue()
{
	int x;
	if(isFull()) printf("\n Queue is full!! \n");
    else
    {
    	printf("enter a element to inseart\n");
    	scanf("%d",&x);
        if(front == -1)front = 0;
        rear=(rear + 1) % MAX;
        cqueue[rear] =x;
    }
}
void dequeue()
{
	int x;
    if(isEmpty()) 
    {
        printf("\n Queue is empty !! \n");
    }
    else 
    {
        x=cqueue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else 
        {
            front = (front + 1) %MAX;    
        }
        printf("\n Deleted element -> %d \n",x);
   }
}
