#include<stdio.h>
int partition(int a[],int p,int r)
{
    int pivot=a[r],i=p-1;
    for(int j=p;j<=r-1;++j)
    {
        if(a[j]<pivot)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else continue;
    }
    a[r]=a[i+1];
    a[i+1]=pivot;
    return i+1;
}
quicksort(int a[],int p,int r)
{
    if(p<r)
    {
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int main()
{
    int n;
    printf("Enter the number of element in Array\n");
    scanf("%d",&n);
    printf("Enter the element one by one\nStart...\n");
    int a[n];
    for(int i=0;i<n;++i)scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("After sorting Array looks like\n");
    for(int i=0;i<n;i++)printf("%d  ",a[i]);
}
