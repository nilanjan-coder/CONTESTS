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
        int n,k;
        cin>>n>>k;
        priority_queue<int> a,b;
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            a.push(-x);
        }
        for(int i=0;i<n;i++)
        {
            cin>>y;
            b.push(y);
        }
        while(k--)
        {
            x=-a.top();
            y=b.top();
            if(y>x)
            {
                a.pop();
                b.pop();
                a.push(-y);
                b.push(x);
            }
            else break;
        }
        int s=0;
        for(int i=0;i<n;i++)
        {
            s+=(-a.top());
            a.pop();
        }
        cout<<s<<"\n";
    }
}