#include <stdio.h>
void reversearray(int n,int *a)
{
    int  i;
    int *start, *end, c;
    start = a;
    end = a + n-1;

    for(i = 0; i < n/2; i++)
    {
        c = *end;
        *end = *start;
        *start = c;

        start++;
        end--;
    }
    for(int i=0;i<n;i++)
   {
   	printf("%d ",a[i]);
   }
    
}
int main()
{
	int n;
	scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++)
   {
   	scanf("%d",&a[i]);
   }
   int *p=a;
  void (*fp)(int ,int*)=reversearray;
  fp(n,a);
  return 0;
}

