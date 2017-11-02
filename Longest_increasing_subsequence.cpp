#include<iostream>
using namespace std;

int LIC(int arr[], int size)
{
    int count;
    int max=0;
    int lis[size];
    for(int j=0;j<size;j++)
    {
        lis[j]=1;
    }
    for(int i=1;i<size;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
            }
        }
    }
    for(int i=0;i<size;i++)
    {
        if(lis[i]>max)
        {
            max=lis[i];
        }
    }
    return max;
}

int main()
{
    int arr[10]={ 10, 22, 9, 33, 21, 50, 41, 60 };
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<LIC(arr,size)<<endl;
    return 0;
    
}
