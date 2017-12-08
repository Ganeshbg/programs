#include<iostream>
using namespace std;
int gcd(int x, int y)
{
    while(x!=y)
    {
        if(x>y)
        {
            x=x-y;
        }
        else
        {
            y=y-x;
        }
    }
    return x;

}
int main()
{
int x,y,z;
cout<<"enter x and y values"<<endl;
cin>>x>>y;
z=gcd(x,y);
cout<<z;
}
