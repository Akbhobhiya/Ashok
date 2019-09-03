#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int rollno;
	float cgpa;
	float marks;
	struct stu *link;
}*front=NULL,*rear=NULL;
void push();
void sortm();
void list();
void display();
int main()
{
	int choice;
	while(1)
	{
		printf("Enter your choice for list::\n");
		printf("1 for Add a student\n2 for sort acc.to marks\n3 for acc.to cgpa\n4 for dispaly\n5 for exit the prog.\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:push();break;
			case 2:sortm();break;
			case 3:list();break;
			case 4:display();break;
			case 5:exit(0);
			default:printf("Enter a correct choice b/w (1-4):\n");
		}
	}

}
void push()
{
	struct stu *temp=(struct stu*)malloc(sizeof(struct stu));
	printf("enter the data of student (rollno.,cgpa,marks)::\n");
	int r;
	float c,m;
	scanf("%d%f%f",&r,&c,&m);
	temp->rollno=r;
	temp->cgpa=c;
	temp->marks=m;
	if(front==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}
void display()
{
	struct stu *p=front;
	if(p==NULL)
		printf("there is no student in the list\n");
	else
	{
		printf("ROLLNO.                  MARKS               CGPA\n");
		while(p)
		{
			printf("%d                    %.2f                  %.2f\n",p->rollno,p->marks,p->cgpa);
			p=p->link;
		}
	}
}
void sortm()
{
	float mark;
	printf("enter the cutoff acc.to marks\n");
	scanf("%f",&mark);
	struct stu *p=front;
	printf("ROLLNO.                  MARKS               CGPA\n");
	while(p)
	{
		if(p->marks>=mark)
		{
			printf("%d                    %.2f                  %.2f\n",p->rollno,p->marks,p->cgpa);
			p=p->link;
		}
		else
		{
			p=p->link;
		}
	}
}
void list()
{
    int rol,num;
    float swapc,swapm,cgp;
    struct stu *s=front,*t,*p=front;
    for(s;s!=NULL;s=s->link)
    {
        for(t=s->link;t!=NULL;t=t->link)
        {
            if(s->marks<t->marks)
            {
                swapc=s->cgpa;
                s->cgpa=t->cgpa;
                t->cgpa=swapc;
                swapm=s->marks;
                s->marks=t->marks;
                t->marks=swapm;
                rol=s->rollno;
                s->rollno=t->rollno;
                t->rollno=rol;
            }
        }
    }
    printf("How many student you want to select:\n");
    scanf("%d",&num);
    printf("enter cutoff CGPA:\n");
    scanf("%f",&cgp);
    int i=0,j=0;
    printf("ROLLNO.                  MARKS               CGPA\n");
    while(p)
    {
    	if(j<num)
    	{
		    if(p->cgpa>=cgp)
		    {
		        printf("%d                    %.2f                  %.2f\n",p->rollno,p->marks,p->cgpa);
		        p=p->link;
		        J++;
		    }
		}
		else
		{
			p=p->link;
		}
		i++;
    }
}