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
Node* reverse(Node* head)
{  
	Node* prev=NULL;
	Node* next;
	Node* cur=head;
	while(cur!=NULL)
	{next=cur->next;
	cur->next=prev;
	prev=cur; //move the pointer
	cur=next;//move cur pointer forward
}
return prev;
}

int palindrome(Node* head  )
{int flag=0;
    Node* slow=head;
    Node* fast=head;
    Node* temp=head;
   while(fast!=NULL && fast->next!=NULL)
   {
   	slow=slow->next;
   	fast=fast->next->next;
   }
   	Node* first=head;
   	Node* second=reverse(slow);
   	while(second!=NULL)
   	{
   	 	if(first->data!=second->data)
   	 	{
   	 		flag=1;
   	 		break;
		}
		first = first->next;
        second = second->next;
	}
	if(flag==0)
	{
		printf("Palindrome");
		
	}
   	else
   	printf("Not palindrome");
   
   return 0;

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

palindrome(head);

return 0;
}
