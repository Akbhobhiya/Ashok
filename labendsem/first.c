#include<stdio.h>
#include<stdlib.h>
struct node
{
	int s1,s2,s3;
	struct node* next;
}*rear=NULL,*front=NULL;
void insert(int s1,int s2,int s3)
{
	struct node*temp= (struct node*)malloc(sizeof(struct node));
	temp->s1=s1;
	temp->s2=s2;
	temp->s3=s3;
	temp->next=NULL;
	if(rear==NULL)
	{
		rear=temp;
		front=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
void result()
{
	struct node*temp=front;
	printf("The results are as follows:\n");
	int i=0;
	while(temp)
	{
		int s1,s2,s3,total;
		s1=temp->s1;
		s2=temp->s2;
		s3=temp->s3;
		total=s1+s2+s3;
		printf("student %d:",++i);
		if((s1>=40)&&(s2>=40)&&(s3>=40))
		{
			printf("PASS,");
			if(total>=270)
			{
				printf("Distinction\n");
			}
			else if((total>=230)&&(total<270))
			{
				printf("First class\n");
			}
			else if((total<230)&&(total>=180))
			{
				printf("Second class\n");
			}
			else
			{
				printf("Third class\n");
			}
		}
		else
		{
			printf("FAIL\n");
		}
		temp=temp->next;
	}
}
int main()
{
	int n;
	printf("Enter the number of student:");
	scanf("%d",&n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		int s1,s2,s3;
		printf("Enter the marks of student %d :",i+1);
		scanf("%d",&s1);
		scanf("%d",&s2);
		scanf("%d",&s3);
		printf("\n");
		insert(s1,s2,s3);
	}
	result();
}
