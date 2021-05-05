#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long int m=0;
        cin>>n;
        while(n>1)
        {
            m+=2*pow(n-1,2);
            n-=2;
        }
        cout<<m<<"\n";
    }
}