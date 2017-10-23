#include<iostream>
using namespace std;

bool isunique(int arr[],int size)
{
int check=0;
    for(int i=0;i<size;i++)
    {
        if(check&(1<<arr[i])) return false;
        check |=(1<<arr[i]);
    }
    return true;
}

int main()
{
int arr[10]={1,2,3,4,5,6,7,8,9,3};
int arr1[10]={0,1,2,3,4,5,6,7,8,9};
int size=sizeof(arr)/sizeof(arr[0]);
int size1=sizeof(arr1)/sizeof(arr1[0]);
cout<<isunique(arr,size)<<endl;
cout<<isunique(arr1, size1)<<endl;
return 0;
}
