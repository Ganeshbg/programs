#include<iostream>
#include<algorithm>
using namespace std;

void knap_sack(int wt[], int val[], int size, int weight)
{
    int arr[size+1][weight+1];
    for(int i=0; i<=size; i++)
    {
        for(int j=0; j<=weight; j++)
        {
            if(i==0 || j==0)
            {
                arr[i][j]=0;
            }
            else if(j<wt[i])
            {
                arr[i][j]=arr[i-1][j];
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],val[i]+arr[i-1][j-wt[i]]);
            }
        }
    }
    cout<<arr[size][weight]<<endl;
}

int main()
{
    int wt[5]={10, 20, 30};
    int val[5]={60, 100, 120};
    knap_sack(wt,val,5,50);
    return 0;
}
