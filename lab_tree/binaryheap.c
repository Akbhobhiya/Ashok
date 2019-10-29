#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int n;
void heapify(int a[],int i)
{
    while(i<=(floor(n/2))-1)
    {
    if(a[i]<a[2*(i+1)]||a[i]<a[2*(i+1)-1])
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
    else
    {
        break;
    }
    }
}
void buildheap(int a[])
{
    int i;
    for(i=floor(n/2)-1;i>=0;i--)
    {
        heapify(a,i);
    }
}
void display(int a[])
{
    for(int j=0;j<n;j++)
    {
        printf("%d ",a[j]);
    }
    printf("\n"); 
}
void insert(int a[],int k1)
{
    a[n]=k1;
    n++;
    int l,m;
    l=floor(n/2)-1;
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
void maxi(int a[])
{
    printf("the maximum element in the heap is %d\n",a[0]);
}
void exmax(int a[])
{
    printf("the element we are going to delete is %d\n",a[0]);
    int temp;
    temp=a[0];
    a[0]=a[n-1];
    a[n-1]=temp;
    n--;
    heapify(a,0);
}
int main()
{
    int n1,k1;
    int a[]={1,17,23,4,12, 11, 13};
    n=sizeof(a)/sizeof(a[0]);
    buildheap(a);
    while(1)
    {
        printf("1.to insert the element\n");
        printf("2.for maximum\n");
        printf("3.to extract maximum\n");
        printf("4.to display the elements\n");
        printf("5.to exit\n");
        printf("now enter your choice :");
        scanf("%d",&n1);
        switch(n1)
        {
            case 1:
            printf("enter the element you want to insert: ");
            scanf("%d",&k1);
            insert(a,k1);
            break;
            case 2:
            maxi(a);
            break;
            case 3:
            exmax(a);
            break;
            case 4:
            display(a);
            break;
            case 5:
            exit(0);
            break;
        }
    }
}
