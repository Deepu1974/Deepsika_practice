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
    Node* one=head;
    Node* two=head;
    for(i=0;i<n && two!=NULL;i++)
    {
    two=two->next;
}
    while(two!=NULL)
    {
    one=one->next;
    two=two->next;
}
return one;
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
printf("%d",head->data);

return 0;
}
