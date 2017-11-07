#include<iostream>
using namespace std;
void min_cost_bag(int arr[], int size, int w)
{
    int arr_wt[size+1][w+1];
    for(int i=0;i<=w;i++)
    {
        arr_wt[0][i]=999;
    }
    for(int j=0; j<=size; j++)
    {
        arr_wt[j][0]=0;
    }
    for(int i=1;i<=size; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(i>w)
            {
                arr_wt[i][j]=arr_wt[i-1][j];
            }
            else
            {
                arr_wt[i][j]=min(arr_wt[i-1][j],arr[i-1]+arr_wt[i][j-i]);
            }
        }
    }
    for(int i=0;i<size; i++)
    {
        for(int j=0;j<=w;j++)
        {
            cout<<arr_wt[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<arr_wt[size][w];
}
int main()
{
    int arr[5]={20,10,4,50,100};
    min_cost_bag(arr, 5, 5);
    return 0;

}
