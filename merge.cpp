#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i,j,k;
    i=0;
    j=0;
    k=l;
    int n1=m-l+1;
    int n2=r-m;
    int lt[n1];
    int rt[n2];
    for(int x=0;x<n1;x++)
    {
        lt[x]=arr[x+l];
    }
    for(int y=0;y<n2;y++)
    {
        rt[y]=arr[y+m+1];
    }
    while(i<n1 && j<n2)
    {
        if(lt[i]<=rt[j])
        {
            arr[k]=lt[i];
            i=i+1;
        }
        else
        {
            arr[k]=rt[j];
            j=j+1;
        }
        k=k+1;
    }
    while(i<n1)
    {
        arr[k]=lt[i];
        i=i+1;
        k=k+1;
    }
    while(j<n2)
    {
        arr[k]=rt[j];
        j=j+1;
        k=k+1;
    }
    
}

void mergesort(int arr[],int l,int r)
{
    int mid;
    if(l>=r)
    {
        return;
    }
    else
    {
        mid=(l+r-1)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);        
    }
}
int main()
{
    int arr[]={9,8,7,6,5,4,3,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}