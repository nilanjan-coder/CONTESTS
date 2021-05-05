#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string b,a="";
        cin>>b;
        //a.append(b[0]);
        cout<<b.at(0);
        for(int i=1;i<=b.length()-2;i+=2) 
        {
            //a.append(b[i]);
            cout<<b.at(i);
        }
        //a.append(b[b.length()-1]);
        cout<<b.at(b.length()-1);
        cout<<endl;
    }
}