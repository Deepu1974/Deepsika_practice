#include <stdio.h>
#include <stdlib.h>
#define n 3

void transpose(int *a)
{int temp;
	for(int i=0;i<n;i++)
{
	for(int j=i+1;j<n;j++)
{
	temp=*(a+i*n+j);
	*(a+i*n+j)=*(a+j*n+i);
	*(a+j*n+i)=temp;
}
}
}

void reverse(int *a)
{ for(int i=0;i<n;i++)
	{
	int *left=a+i*n;
	int *right=a+i*n+(n-1);
	while(left<right)
	{
	 *left=*left+*right;
	 *right=*left-*right;
	 *left=*left-*right;
	left++;
	right--;
    }
}
}


int main()
{
int *a=(int*)malloc(n*n*sizeof(int));
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
{
	scanf("%d",(a+i*n+j));
}
}
transpose(a);
reverse(a);
for(int i=0;i<n;i++)
{
	for(int j=0;j<n;j++)
{
	printf("%d ",*(a+i*n+j));
}
printf("\n");
}
free(a);
}
