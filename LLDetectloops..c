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

 int detectloop( Node* head) {
     Node* fast=head;
     Node* slow=head;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL)
    {   slow=slow->next;
	    fast=fast->next->next;
        if(slow==fast)
        {
        	return 1;
		}
    }
    return 0;
}



int main()
{
Node *head=NULL;
push(&head,6);
push(&head,14);
push(&head,26);
push(&head,8);
head->next->next->next->next=head;
if(detectloop(head))
{
	printf("Loop Detected");
}
else
{
	printf("Not detected");
}
return 0;
}

