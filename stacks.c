#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int top=-1,stack[MAX];
void push();
void pop();
void main()
{
	int ch;
	while(1)
	{
		printf("1.Push\n2.Pop\n3.Exit");
		printf("\nEnter your choice(1-3):");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: exit(0);
			default: printf("\nWrong Choice!!\n");
		}
	}
}
void push()
{
	int x;
	if(top==MAX-1)
	{
		printf("Stack is full!!\n");
	}
	else
	{
		printf("\nEnter element to push:");
		scanf("%d",&x);
		top=top+1;
		stack[top]=x;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\nStack is empty!!\n");
	}
	else
	{
		printf("\nDeleted element is %d\n",stack[top]);
		top=top-1;
	}
}
