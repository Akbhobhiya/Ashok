#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;
void push();
void display();
int length();
int main()
{
    int choice;
    while(1)
    {
        printf("enter your choice\n");
        printf("1 for push\n2 for display\n3 for find the length\n4 for exit the prog.\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();break;
            case 2:display();break;
            case 3:printf("%d elements are present in list\n",length());break;
            case 4:exit(0);
            default:printf("WRONG CHOICE!!\nTRY AGAIN WITH CORRECT CHOICE(1-6):\n");
        }
    }
}
void push()
{
    int num,pos;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter data that you want to enter\n");
    scanf("%d",&num);
    printf("enter the position where you wanna insert the element\n");
    scanf("%d",&pos);
    temp->data=num;
    if((length()< pos)||(pos<0))
    {
        printf("Error!, position is not in the range of length of linked list \n");
    }
    else
    {
        printf("entered in else part\n");
        if(pos==0)
        {
            if(front==NULL)
            {
                front=rear=temp;
            }
            else
            {
                temp->link=front;
                front=temp;
            }
        }
        else
        {
            int temp2=pos-1;
            struct node* tempn=front;
            while(temp2--)
            {
                tempn=tempn->link;
            }
            temp->link=tempn->link;
            tempn->link=temp;
        }
    }
    
}
int length()
{
    int i=0;
    struct node *p=front;
    while(p)
    {
        i++;
        p=p->link;
    }
    return i;
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
