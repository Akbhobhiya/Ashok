#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*front=NULL,*rear=NULL;
void push();
void pop();
void display();
int length();
int main()
{
    int choice;
    while(1)
    {
        printf("enter your choice for doubly linked list operations!!!\n");
        printf("1 for insertion\n2 for deletion\n3 for dispaly\n4 for length of list\n5 for exit prog.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:printf("%d elements are present in the list\n",length());break;
            case 5:exit(0);
            default:printf("WRONG CHOICE!!\nWHAT ARE YOU DOING MAN!!\nCHOOSE A CORRECT OPTION B/W 1-3:\n");
            
        }
    }
}
void push()
{
    int num;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data for node\n");
    scanf("%d",&num);
    temp->data=num;
    if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        temp->prev=rear;
        rear=temp;
    }
}
void display()
{
    struct node *temp=front;
    printf("All elements present in list are:\n");
    while(temp)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
int length()
{
    struct node *temp=front;
    int i=0;
    while(temp)
    {
        i++;
        temp=temp->next;
    }
    return i;
}
void pop()
{
    int l=length();
    if(l==0)
    {
        printf("Sorry you cann't delet an element!!\nlist is empty!!\n");
    }
    else
    {
        int pos;
        printf("enter a position for delet element\n");
        scanf("%d",&pos);
        if(pos>l)
        {
            printf("Invallid position!!\nTry Again with correct position b/w 1-%d:\n",l);
        }
        else if(pos==1)
        {
            struct node *temp=front;
            front=front->next;
            front->prev=NULL;
            printf("%d is deleted\n",temp->data);
            free(temp);
        }
        else if(pos==l)
        {
            struct node *temp=rear;
            rear=rear->prev;
            temp->prev=NULL;
            rear->next=NULL;
            printf("%d is deleted\n",temp->data);
            free(temp);
        }
        else
        {
            struct node *temp=front;
            while(pos-1)
            {
                temp=temp->next;
                pos--;
            }
            temp->next=temp->next->next;
            temp->next->prev=temp;
            printf("%d is deleted\n",temp->data);
            free(temp);
        }
    }
}
