#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int table=0;
        vector<int> index;
        for(int i=0;i<s.length();i++) if(s.at(i)=='1') index.push_back(i);
        if(index.size()>=2)
        {
            for(int i=0;i<=index.size()-2;i++) table+=((index[i+1]-index[i])/(k+1)-1);
            table+=(index[0])/(k+1);
            table+=(s.length()-1-index[index.size()-1])/(k+1);
        }
        else if(index.size()==1)
        {
            table+=(index[0])/(k+1);
            table+=(s.length()-1-index[index.size()-1])/(k+1);
        }
        else table+=(s.length()-1)/(k+1)+1;
        cout<<table<<endl;
    }
}