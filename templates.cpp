#include<iostream>
using namespace std;
template <class T>
T sum(T x, T y)
{
    T z;
    z=x+y;
    return z;
}
int main()
{
    cout<<sum(10,20)<<endl;
    cout<<sum(10.2,20.3)<<endl;
    return 0;
}
