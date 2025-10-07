#include<stdio.h>
#define maxsize 10
int s[maxsize],top=-1;
void push(int item)
{
	if(top>=maxsize)
	{
		printf("stack overflow");
	}
	else
	{
		top=top+1;
		s[top]=item;
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack underflow");
	}
	else
	{
		printf("element poped is %d\n",s[top]);
		top=top-1;
	}
}
void display()
{
	for(int i=top;i>-1;i--)
	{
		printf("%d\n",s[i]);
	}
}
int main()
{
	int choice,item;
	do
	{
		printf("_____________Menu---------------\n");
		printf("1.push\n2.pop\n3.display\n");
		printf("enter your chiuce");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("enter the item");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exit\n");
				break;
			default:
				printf("invalid choice.try again\n");
		}
	}while(choice!=4);
return 0;
}
