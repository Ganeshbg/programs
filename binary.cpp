#include<iostream>
using namespace std;
bool BinarySearch(int arr[],int size,int item)
{
    int low=0;
    int high=size-1;
    int mid;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]==item)
        {
            return true;
        }
        else if(arr[mid]>item)
        {
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return false;
    
}
int main()
{
int a[]={1,2,3,4,5,6,7,8};
int size = sizeof(a)/sizeof(a[0]);
bool result=BinarySearch(a,size,10);
if(result)
{
    cout<<"Found";
}
else
{
    cout<<"Not Found";
}
return 0;

}