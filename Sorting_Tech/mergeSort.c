#include <stdio.h>
#include <stdlib.h>
void merge(int a[],int low,int mid,int high)
{
	int l[mid-low+1],r[high-mid];
	for(int i=0;i<mid-low+1;i++)
	{
		l[i]=a[i+low];
	}
	for(int i=0;i<high-mid;i++)
	{
		r[i]=a[i+mid+1];
	}
	int i=0,j=0,k=low;
	while((i<mid-low+1)&&(j<high-mid))
	{
		if(l[i]<=r[j])
		{
			a[k]=l[i];
			i++;
			k++;
		}
		else 
		{
			a[k]=r[j];
			j++;
			k++;
		}
	}
	while(i<mid-low+1)
	{
		a[k]=l[i];
		i++;
		k++;
	}
	while(j<high-mid)
	{
		a[k]=r[j];
		j++;
		k++;
	}
}
void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
	int m=(low+high)/2;
	mergesort(a,low,m);
	mergesort(a,m+1,high);
	merge(a,low,m,high);
	}
}
int main()
{
	int n;
	printf("Enter the number of element\n");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements\n");
	printf("Start...\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Sorted Array::\n");
	mergesort(a,0,n);
	for(int i=0;i<n;i++)printf("%d   ",a[i]);
}
