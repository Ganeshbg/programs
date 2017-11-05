#include<iostream>
#include<stdbool.h>
using namespace std;
bool sub_sum(int arr[],int n,int sum)
{
    bool sub[n+1][sum+1];
    for(int i=1;i<n;i++)
    {
        sub[i][0]=true;
    }
    for(int j=1;j<sum;j++)
    {
        sub[0][j]=false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<arr[i])
            {
                sub[i][j]=sub[i-1][j];
            }
            else if(j>=arr[i])
            {
                sub[i][j]=sub[i-1][j]||sub[i-1][j-arr[i]];
            }
        }
    }
    return sub[n][sum];
    
}

int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout<<sub_sum(arr,10,15);
    return 0;
}
