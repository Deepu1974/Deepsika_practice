#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
}Node;

Node* createnode(int d)
{
	Node* newnode=(Node*)malloc(sizeof(Node));
	newnode->data=d;
	newnode->next=NULL;
	newnode->prev=NULL;
	return newnode;
}

Node* deletemiddle(Node *head)
{
    if(head == NULL)
        return NULL;

    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow->prev == NULL)
    {
        head = slow->next;
        if(head != NULL)
            head->prev = NULL;
    }
    else
    {
        slow->prev->next = slow->next;

        if(slow->next != NULL)
            slow->next->prev = slow->prev;
    }

    free(slow);

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
	{ scanf("%d",&d);
	 newnode=createnode(d);
	  if(head==NULL)
	  {
	  	head=newnode;
	  	temp=head;
		  }	
	   else
	   {
	   	temp->next=newnode;
	   	newnode->prev=temp;
	   	temp=newnode;
	   }
	}
head = deletemiddle(head);

	temp=head;
	while(temp!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
	return 0;
}
