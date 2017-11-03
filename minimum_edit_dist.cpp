#include<iostream>
#include<string>
using namespace std;

void min_edit_distance(string str1, string str2, int m, int n)
{
    int L[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
            {
                L[i][j]=j;
            }
            else if(j==0)
            {
                L[i][j]=i;
            }
            else if(str1[i-1]==str2[j-1])
            {
                L[i][j]=L[i-1][j-1];
            }
            else
            {
                L[i][j]=1+min(L[i][j-1],min(L[i-1][j],L[i-1][j-1]));
            }
        }
    }
    cout<<L[m][n];
}
int main()
{
    string str1 = "Sunday";
    string str2 = "Saturday";
    min_edit_distance(str1, str2, str1.length(), str2.length());
    return 0;
}
