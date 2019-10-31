#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n=0,a[100];
void heapify(int i)
{
    while(i<=(n/2)-1)
    {
    if(a[i]<a[2*(i+1)]||a[i]<a[2*(i+1)-1])
    {
    	if(n==2*(i+1))
    	{
    		int temp;
            temp=a[i];
            a[i]=a[2*(i+1)-1];
            a[2*(i+1)-1]=temp;
            i=2*(i+1)-1;
    	}
    	else
    	{
            if(a[2*(i+1)]>a[2*(i+1)-1])
            {
            int temp;
            temp=a[i];
            a[i]=a[2*(i+1)];
            a[2*(i+1)]=temp;
            i=2*(i+1);
            }
            else
            {
            int temp;
            temp=a[i];
            a[i]=a[2*(i+1)-1];
            a[2*(i+1)-1]=temp;
            i=2*(i+1)-1;
            }
        }
    }
    else
    {
        break;
    }
    }
}
void display()
{
    for(int j=0;j<n;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n"); 
}
void insert(int k1)
{
    a[n]=k1;
    n++;
    int l,m;
    l=n/2-1;
    m=n-1;
    while((m>0)&&(a[m]>a[l]))
    {
        int temp;
        temp=a[m];
        a[m]=a[l];
        a[l]=temp;
        m=l;
        l=(ceil((float)l/2))-1;
    }
}
void maxi()
{
    printf("the maximum element in the heap is %d\n",a[0]);
}
void exmax()
{
    printf("the element we are going to delete is %d\n",a[0]);
    int temp;
    temp=a[0];
    a[0]=a[n-1];
    a[n-1]=temp;
    n=n-1;
    heapify(0);
}
int main()
{
    int n1,k1;
    while(1)
    {
        printf("\nEnter your choice for HEAP:\n");
        printf("1 for buildheap\n");
        printf("2.to insert the element\n");
        printf("3.for maximum\n");
        printf("4.to extract maximum\n");
        printf("5.to display the elements\n");
        printf("6.to exit\n");
        scanf("%d",&n1);
        switch(n1)
        {
            case 1:
            {
                int num;
                printf("How many elements you want in a array:\n");
                scanf("%d",&num);
                printf("start...\n");
                for(int i=0;i<num;i++)
                {
                    int p;
                    scanf("%d",&p);
                    a[i]=p;n++;

                }
                for(int i=(n/2)-1;i>=0;i--)
                {
                    heapify(i);
                }
                break;
            }
            case 2:
                printf("enter the element you want to insert: ");
                scanf("%d",&k1);
                insert(k1);
                break;
            case 3:
                maxi();
                break;
            case 4:
                exmax();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:printf("Wrong Choice!! choose another option!!");
        }
    }
}
