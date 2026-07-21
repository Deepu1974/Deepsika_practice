#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;

Node* createnode(int d)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=d;
	newnode->next=NULL;
	return newnode;
}

Node* delete(Node* head ,Node* node)
{
	Node* temp =node->next;//temp is next node of the pointed node
	node->data=temp->data;//copy the data from next node
	node->next=temp->next;//skip the node 
	free(temp);
	return head;
}

int main()
{
int n,d;
scanf("%d",&n);
Node* head=NULL;
Node* temp=NULL;
Node* newnode=NULL;
for(int i=0;i<n;i++)
{
	scanf("%d",&d);
	newnode=createnode(d);
	if(head==NULL)
	{
		head=newnode;
		temp=head;
	}
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
}	
Node* node=head->next->next;
head=delete(head,node);
temp=head;

while(temp!=NULL)
{
	printf("%d",temp->data);
	temp=temp->next;
}
return 0;
}
