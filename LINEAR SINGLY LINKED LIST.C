#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODEPTR;
#define NODEALLOC (struct node *)malloc(sizeof(struct node));
NODEPTR create(NODEPTR slist)
{
	NODEPTR temp,newnode;
	int c,n;
	slist=NULL;
	printf("How Many Nodes?");
	scanf("%d",&n);
	for(c=1;c<=n;c++)
	{
		newnode=NODEALLOC;
		printf("Enter Value For Node");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(slist==NULL)
		{
			slist=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		
	}
	return(slist);
}
void display(NODEPTR slist)
{
	NODEPTR temp=slist;
	while(temp!=NULL)
	{
		printf("%4d",temp->data);
		temp=temp->next;
	}
}
NODEPTR insertbeg(NODEPTR slist,int n)
{
	NODEPTR newnode;
	newnode=NODEALLOC;
	newnode->data=n;
	newnode->next=slist;
	slist=newnode;
	return(slist);
}
NODEPTR insertend(NODEPTR slist,int n)
{
	NODEPTR newnode,temp;
	temp=slist;
	while(temp->next!=NULL)
	temp=temp->next;
	newnode=NODEALLOC;
	newnode->data=n;
	newnode->next=NULL;
	temp->next=newnode;
	return(slist);
}
int main()
{
	NODEPTR slist=NULL;
	int ch,n,p;
	do
	{
		printf("1.Create List\n");
		printf("2.Display\n");
		printf("3.Insert Begin\n");
		printf("4.Insert End\n");
		printf("5.Insert Between\n");
		printf("6.Exit\n");
		printf("ENTER CHOICE....=");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:slist=create(slist);
			       printf("\nList is created...\n");
			       
			       break;
			case 2:display(slist);
			       printf("\nPress any key...\n");
			       
			       break;
			case 3:printf("Enter New value");
			       scanf("%d",&n);
				   slist=insertbeg(slist,n);
				   printf("\nValue Is Inserted...\n");
				   
				   break; 
			case 4:printf("Enter New value");
			       scanf("%d",&n);
				   slist=insertend(slist,n);
				   printf("\nValue Is Inserted...\n");
				   break; 	   
		}
	}while(ch<9);
}












