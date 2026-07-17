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
void push(Node **head, int d)
{
    Node *newnode=createnode(d);
    newnode->next=*head;
    *head=newnode;
}

 int removeloop( Node* head) {
     Node* fast=head;
     Node* slow=head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL)
    {   slow=slow->next;
	    fast=fast->next->next;
        if(slow==fast)
        {break;}}
if(fast == NULL || fast->next == NULL)
return head;
slow = head;
if(slow == fast)
 {  while(fast->next != slow)
     fast = fast->next;
 }
else
{while(slow->next != fast->next)
       	{slow = slow->next;
	 fast = fast->next;
        }

	 }
	   fast->next = NULL;
  return head;
}


int main()
{ Node* temp=NULL; 
Node *head=NULL;
push(&head,6);
push(&head,14);
push(&head,26);
push(&head,8);
head->next->next->next->next=head;
head=removeloop(head);
temp=head;

while(temp!=NULL)
{
	printf("%d",temp->data);
	temp=temp->next;
}
return 0;
}
