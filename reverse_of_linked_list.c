#include <stdio.h>
#include<stdlib.h>
#define max=10;
struct node
{
    int data;
    struct node* next;
}*rear=NULL,*front=NULL;
void push();
void reverse();
void display();
int length();
int main()
{
    int choice;
    while(1)
    {
        printf("enter your choice\n");
        printf("1 for push\n2 for display\n3 for reversing of linked list and display\n4 for find the length\n5 for exit the program.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();break;
            case 2:display();break;
            case 3:reverse();break;
            case 4:printf("%d elements are present in list\n",length());break;
            case 5:exit(0);
            default:printf("WRONG CHOICE!!\nTRY AGAIN WITH CORRECT CHOICE(1-5):\n");
        }
    }
}
void push()
{
    struct node *temp=(struct node*)malloc(sizeof(struct node*));
    printf("Put a number for insert::\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(front==NULL)
    {
        rear=front=temp;
    }
    rear->next=temp;
    rear=temp;
}
void display()
{
    struct node*p=front;
    printf("Data of linked list\n");
    while(p)
    {
        printf("%d  ",p->data);p=p->next;
    }
    printf("\n");
}
int length()
{
    struct node*p=front;
    int x=0;
    while(p)
    {
        p=p->next;x++;
    }
    return x;
}
void reverse()
{
    int n=length();
    struct node *p=front,*prev=NULL,*next=NULL;
    while(p!=NULL)
    {
        next=p->next;
        p->next=prev;
        prev=p;
        p=next;
    }
    front=prev;
    printf("After reversing\n");
    display();
}
