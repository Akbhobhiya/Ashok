#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int front=-1,rear=-1,queue[MAX];
void enqueue();
void dequeue();
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
	if(rear==MAX-1)
	{
		printf("queue is full!!\n");
	}
	else
	{
		front=0;
		rear++;
		printf("\nEnter element to inseart:");
		scanf("%d",&x);
		queue[rear]=x;
	}
}
void dequeue()
{
	if(front==-1)
	{
		printf("\nqueue is empty!!\n");
	}
	else
	{
	    printf("\nDeleted element is %d\n",queue[front]);
	    front++;
		if(front>rear)
			front=rear=-1;
	}
}
