#include<stdio.h>
void sortarray(int a[],int n)
{
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}	
		}
	}
}
void merge(int a[], int b[], int c[],int n,int n1,int n2)
{	
	int i;
	for(i=0;i<n;i++)
		c[i]=a[i];
	for(int j=0;j<n2;j++)
	{
		c[i]=b[j];
		i++;
	}
	/*int j;
	for(int i=0;i<n;i++)
		c[i]=a[i];
	for(int i=0,j=n;i<n1,j<n2;i++,j++)
		c[j]=b[i];*/
}
void display_array(int a[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void input(int a[], int n)
{
	if(n<50)
	{
		printf("Enter %d elemenets\n",n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
	}
	else
	{
		printf("n is bigger than the size of the array");
	} 
}
int main()
{
	int a[50],n,n1,b[50],temp,c[100],n2;
	printf("enter the size of your array");
	scanf("%d",&n);
	input(a,n);
	printf("enter the size of your array");
	scanf("%d",&n1);
	input(b,n1);
	printf("before sorting,\n");
	printf("array one ");
	display_array(a,n);
	printf("array two ");
	display_array(b,n1);
	sortarray(a,n);
	sortarray(b,n1);
	printf("after sorting,\n");
	printf("array one ");
	display_array(a,n);
	printf("array two ");
	display_array(b,n1);
	n2=n+n1;
	printf("the merged array is\n");
	merge(a,b,c,n,n1,n2);
	sortarray(c,n2);
	display_array(c,n2);

}
