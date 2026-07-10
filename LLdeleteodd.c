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

Node* deleteodd(Node *head)
{
    Node *temp=head;

    while(temp!=NULL&&temp->next!=NULL)
    {
        if(temp->next->data%2!=0)
        {
            Node *del=temp->next;
            temp->next=del->next;
            free(del);
        }
        else
        {
            temp=temp->next;
        }
    }

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
head=deleteodd(head);
temp=head;

while(temp!=NULL)
{
	printf("%d",temp->data);
	temp=temp->next;
}
return 0;
}
