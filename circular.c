#include<stdio.h>
#define maxsize 5
int q[maxsize],front=-1,rear=0;
void enqueue(int item)
{
	if(rear==front)
	{
		printf("queue overflow\n");
	}
	else
	{
		printf("enter the item");
		scanf("%d",&item);
		q[rear]=item;
		rear=((rear+1)%maxsize);
		if(front==-1){
			front=0;
		}
	}
}
void dequeue()
{
	if(q[front]==0)
	{
		printf("quueue is empty\n");
	}
	else
	{
		printf("%d %d",front,rear);
		printf("the item removed is %d\n",q[front]);
		front+=1;
	}
}
void display()
{
	printf("queueueueueue items are \n");
	for(int i=0;i<maxsize;i++)
	{
		printf("%d\n",q[i]);
	}
	
}
int main()
{
	int choice,item;
	do
	{
		printf("-------------------MENU----------------\n");
		printf("1.enqueue\n2.dequeue\n3.display\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue(item);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("exit");
				break;
			default:
				printf("invalid choice.try again\n");
		}
	}while(choice!=4);
	return 0;
}

