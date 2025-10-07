#include<stdio.h>
int main()
{
	int arr[50],n,sum=0;
	printf("enter the size of your array");
	scanf("%d",&n);
	if(n<50)
	{
		printf("Enter %d elemenets\n",n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		for(int i=0;i<n;i++)
		{
			sum+=arr[i];
		}
		printf("sum is %d",sum);
	}
	else
	{
		printf("n is bigger than the size of the array");
	} 
	return 0;	
}
