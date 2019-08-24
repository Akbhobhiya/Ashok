//dynamic stack(linked list)
//pop, push,find the length,dispaly all the element
//using malloc function
#include <stdio.h>
#include <stdlib.h>
struct new
	{
		int data;
		struct new *link;
	}*top=NULL;
void push(void);
void pop(void);
void display(void);
void length(void);
void main(void)
{
    int choice;
    while(1)
    {
    	printf("\n\nenter 1 for push\n");
        printf("enter 2 for pop\n");
        printf("enter 3 for find the length of stack\n");
        printf("enter 4 for display all elements that are present in the stack\n");
        printf("enter 5 for stop the programe\n");
        scanf("%d",&choice);
        switch(choice)
        {
        	case 1:push();break;
        	case 2:pop();break;
        	case 3:length();break;
        	case 4:display();break;
        	case 5:exit(0);
        	default: printf("\nWrong Choice!!\n");
        }

    }
}
void push()
{
	struct new *temp;
	temp=(struct new*)malloc(sizeof(struct new*));
	int num;
	printf("enetr a number that you want to push\n");
	scanf("%d",&num);
	temp->data=num;
	temp->link=top;
	top=temp;
}
void pop()
{
	struct new *temp;
	if(top==NULL)
	{
		printf("stack is empty\n");
	}
	else
    {
        temp=top;
        printf("Value popped out is %d \n",temp->data);
        top=top->link;
        free(temp);
    }
}
void length(void)
{
	struct new *p;
	p=top;
	if(p==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
	    int i=1;
	    while(p->link!=NULL)
	    { 
		    i++;
		    p=p->link;
	    }
	    printf("length of stack is %d\n",i);
	}
}
void display()
{
	struct new *p;
	p=top;
	if(p==NULL)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("all elements of stack are:\n");
	    while(p!=NULL)
	    {
		  printf("%d\n",p->data);
		  p=p->link;
	    }
	}
}
