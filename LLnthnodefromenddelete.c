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


Node* nthnodefromend(Node* head , int n)
{   int i;
    Node* prev=head;
    Node* one=head;
    Node* two=head;
    for(i=0;i<n && two!=NULL;i++)
    {
    two=two->next;
}
    while(two!=NULL)
    {prev=one;
    one=one->next;
    two=two->next;
}
   prev->next=one->next;
   free(one);
   return head;
}

int main()
{
int s,d,n,i;
scanf("%d",&s);
scanf("%d",&n);
Node* head=NULL;
Node* temp=NULL;
Node* newnode=NULL;
for( i=0;i<s;i++)
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
if(n>s)
{
printf("exceeded list size");
}
head=nthnodefromend(head,n);
temp=head;
while(temp!=NULL)
{
printf("%d",temp->data);
temp=temp->next;
}
return 0;
}
