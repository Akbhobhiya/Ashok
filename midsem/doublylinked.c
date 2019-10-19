#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node* next;
	struct node* prev;
}*rear1=NULL,*rear2=NULL,*front1=NULL,*front2=NULL;
void push1(int n1)
{	
	printf("Enter the elements in the first list:\n");
	for(int i=0;i<n1;i++)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node*));
		temp->next=NULL;
		temp->prev=NULL;
		scanf("%d",&temp->data);
		if(front1==NULL)
		{
			front1=rear1=temp;
		}
		else
		{
			struct node*p=front1,*q;
			while((p!=rear1)&&(p->data>=temp->data))
			{
				p=p->next;
			}
			if(p->data<temp->data)
			{
				temp->prev=rear1;
				p->next=temp;
				rear1=temp;
			}
			else if(p==front1)
			{
				if(p->data<temp->data)
				{
					p->next=temp;
					temp->prev=p;		
				}
				else
				{
					temp->next=p;
					p->prev=temp;
					front1=temp;
				}
			}
			else
			{
				q=p->prev;
			    temp->prev=q;
			    temp->next=p;
			    p->prev=temp;
			    q->next=temp;
			}
		}
	}
}
void push2(int n1)
{	
	printf("Enter the elements in the first list:\n");
	for(int i=0;i<n1;i++)
	{
		struct node* temp=(struct node*)malloc(sizeof(struct node*));
		temp->next=NULL;
		temp->prev=NULL;
		scanf("%d",&temp->data);
		if(front2==NULL)
		{
			front2=rear2=temp;
		}
		else
		{
			struct node*p=front2,*q;
			while((p!=rear2)&&(p->data>=temp->data))
			{
				p=p->next;
			}
			if(p->data<temp->data)
			{
				temp->prev=rear2;
				p->next=temp;
				rear2=temp;
			}
			else if(p==front2)
			{
				if(p->data<temp->data)
				{
					p->next=temp;
					temp->prev=p;		
				}
				else
				{
					temp->next=p;
					p->prev=temp;
					front2=temp;
				}
			}
			else
			{
				q=p->prev;
			    temp->prev=q;
			    temp->next=p;
			    p->prev=temp;
			    q->next=temp;
			}
		}
	}
}
void print(struct node* temp)
{
	while(temp)
	{
		printf("%d  ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
void add()
{
	rear1->next=front2;
	front2->prev=rear1;
}
void push()
{	
	printf("Enter data to insert:\n");
		struct node* temp=(struct node*)malloc(sizeof(struct node*));
		temp->next=NULL;
		temp->prev=NULL;
		scanf("%d",&temp->data);
		if(front1==NULL)
		{
			front1=rear2=temp;
		}
		else
		{
			struct node*p=front1,*q;
			while((p!=rear2)&&(p->data>=temp->data))
			{
				p=p->next;
			}
			if(p->data<temp->data)
			{
				temp->prev=rear2;
				p->next=temp;
				rear2=temp;
			}
			else if(p==front1)
			{
				if(p->data<temp->data)
				{
					p->next=temp;
					temp->prev=p;		
				}
				else
				{
					temp->next=p;
					p->prev=temp;
					front1=temp;
				}
			}
			else
			{
				q=p->prev;
			    temp->prev=q;
			    temp->next=p;
			    p->prev=temp;
			    q->next=temp;
			}
		}
}
int main()
{
	int n1,n2;
	printf("Enter the size of the first doubly linked list:\n");
	scanf("%d",&n1);
	push1(n1);
	printf("Data of first list are:\n");print(rear1);
	printf("Enter the size of second doubly linked list:\n");
	scanf("%d",&n2);
	push2(n2);
	printf("Data of second list are:\n");print(rear2);
	add();
	printf("after addind list:\n");
	print(rear2);
	while(1)
	{
		printf("Menu Option:\n");
	    printf("1. Inseart an element:\n2. Delete an element:\n3. Exit the program:\n");
	    int i;
	    scanf("%d",&i);
	    switch(i)
	    {
	    	case 1:push();printf("now data are:\n");print(rear2);break;
	    	case 3:exit(0);
	    	default:printf("Wrong choice\n");
	    }
	}
}
