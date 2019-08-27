#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL,*p,*q,*r,*end;
void push();
void push1(int);
void push2(int);
void sort();
void display();
int main()
{
	int choice;
	while(1)
	{
		printf("Enter your choice for list::\n");
		printf("1 for insert element\n2 for sorting of element\n3 for display of element\n4 for exit the prog.\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();break;
			case 2:sort();break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("Enter a correct choice b/w (1-4):\n");
		}
	}
}
void push()
{
	int num;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data that you want to enter\n");
    scanf("%d",&num);
    temp->data=num;
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
    p=front;
    r=front;
    end=rear;
}
void sort()
{
    while(p!=end)
    {
        q=p;
        if(q->data==2)
        {
            push1(2);
            front=front->link;
            p=p->link;
            free(q);
        }
        else if(q->data==1)
        {
            r=p;
            p=p->link;
        }
        else
        {
            if(p==front)
            {
                p=p->link;
            }
            else
            {
                push2(0);
                r->link=p->link;
                p=p->link;
                free(q);
            }    
        }
    }
}
void push1(int a)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=a;
    rear->link=temp;
    rear=temp;
}
void push2(int a)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct new*));
    temp->data=a;
    temp->link=front;
    front=temp;
}
void display()
{
    struct node *p=front;
    printf("data of linked are:\n");
    while(p)
    {
        printf("%d\n",p->data);
        p=p->link;
    }
}
