#include <stdio.h>
void merge(int a[],int l,int mid,int h)
{
    int i=l;
    int j=mid+1;
    int k=0;
    int temp[h-l+1];
    while(i<=mid&&j<=h)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=a[i++];
    }
    while(j<=h)
    {
        temp[k++]=a[j++];
    }
    for(i=l,k=0;i<=h;i++,k++)
    {
        a[i]=temp[k];
    }
}
void mergeSort(int a[],int l,int h)
{
    if (l<h)
    {
        int mid=(l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    for (int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
