#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};
struct node *header=NULL;
/*void createnode(int item)
{
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
}*/
void insertAtFront(int item)
{	
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	//make the created node as the first node
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;	
	} 
}
void insertAtEnd(int item)
{
	struct node *newnode;
	struct node *ptr;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	ptr=header;
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
}
void insertAtAny(int item, int key)
{
	struct node *newnode;
	struct node *ptr;
	struct node *ptr1;
	int flag=0;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = item;
	newnode->link = NULL;
	ptr1=header;
	ptr=ptr1->link;
	//check if key element is in the ll
	if(ptr1->data==key)
	{
		insertAtFront(item);
		flag=1;
	}
	else
	{	
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				ptr1->link=newnode;
				newnode->link=ptr;
				flag=1;
				break;	
			}
			else
			{	
				ptr1=ptr;
				ptr=ptr->link;
				continue;
			}
		}
	}  
	if(flag==0)
	{
		printf("key not found");
	}
}
void traverseList()
{
	struct node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}  
	printf("\n");
}
void DeletionAtFront()
{
	struct node *ptr;
	ptr=header;
	if(header==NULL)
	{
		printf("List is empty therefore deletion is not possible");
	}
	else
	{
		printf("The item deleted is %d\n",ptr->data);
		header=header->link;
		free(ptr);
	}
}
void DeletionAtEnd()
{
	struct node *ptr;
	struct node *ptr1;
	ptr=header;
	if(header==NULL)
	{
		printf("List is empty therefore deletion is not possible");
	}
	else
	{
		while(ptr->link!=NULL)
	        {
	        	ptr1=ptr;
			ptr=ptr->link;
	        }
	        printf("The item deleted is %d\n",ptr->data);
	        ptr1->link=NULL;
		free(ptr);
	}
}
void DeletionAtAny(int key)
{
	struct node *ptr;
	struct node *ptr1;
	int flag=0;
	ptr=header;
	//check if key element is in the ll
	if(header==NULL)
	{
		printf("List is empty therefore deletion is not possible");
	}
	else if(ptr->data==key)
	{
		DeletionAtFront();
	}
	else
	{
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				printf("The item deleted is %d\n",ptr->data);
				ptr1->link=ptr->link;
				free(ptr);
				flag=1;
				break;	
			}
			else
			{
				ptr1=ptr;
				ptr=ptr->link;
				continue;
			}
		}  
		if(flag==0)
		{
			printf("key not found");
		}
	}
}
void Search(int key)
{
	struct node *ptr;
	int count=0;
	int flag=0;
	ptr=header;
	while(ptr!=NULL)
	{
		count+=1;
		if(ptr->data==key)
		{
			printf("The key %d is in node number %d",key,count);
			flag=1;
			break;
		}
		ptr=ptr->link;
	}  
	if(flag==0)
	{
		printf("The key is not present in the linked list");
	}
	printf("\n");
}

int main()
{
	int choice,item,key;
	do
	{
		printf("-------------------MENU----------------\n");
		printf("1.Insertion at front\n2.Insertion at end\n3.Insertion at any\n4.Display\n5.Deletion at front\n6.Deletion at end\n7.Deletion at any\n8.Search\n9.Exit\n");
		printf("enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the item to be stored in the newnode");
				scanf("%d",&item);
				insertAtFront(item);
				break;
			case 2:
			        printf("Enter the item to be stored in the newnode");
	                        scanf("%d",&item);
				insertAtEnd(item);
				break;
			case 3:
			        printf("Enter the item to be stored in the newnode");
	                        scanf("%d",&item);
	                        printf("Enter the key element");
	                        scanf("%d",&key);
				insertAtAny(item,key);
				break;
			case 4:
				traverseList();
				break;
			case 5:
				DeletionAtFront();
				break;
			case 6:
				DeletionAtEnd();
				break;
			case 7:
				printf("Enter the key element");
	                        scanf("%d",&key);
				DeletionAtAny(key);
				break;
			case 8:
				printf("Enter the key element");
	                        scanf("%d",&key);
				Search(key);
				break;
			case 9:
				printf("exit\n");
				break;
			default:
				printf("invalid choice.try again\n");
		}
	}while(choice!=9);
	printf("Data: %d",*header);
	return 0;
}
