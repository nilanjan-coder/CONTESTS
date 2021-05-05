#include <bits/stdc++.h>
using namespace std;
void swap(int *p, int *q)
{
    int t=*p;
    *p=*q;
    *q=t;
}
int main()
{
       int t;
       cin>>t;
       while(t--)
       {
           int n;
           cin>>n;
           int a[n];
           stack<int> oae,eao;
           int move=0;
           for(int i=0;i<n;i++) 
           {
               cin>>a[i];
               if(i%2==0 && a[i]%2!=0)
               {
                   oae.push(i);
                   if(!eao.empty()) 
                   {
                       swap(&a[oae.top()],&a[eao.top()]);
                       move++;
                       eao.pop();
                       oae.pop();
                   }
               }
               else if(i%2!=0 && a[i]%2==0)
               {
                   eao.push(i);
                   if(!oae.empty())
                   {
                       swap(&a[oae.top()],&a[eao.top()]);
                       move++;
                       eao.pop();
                       oae.pop();
                   }
               }
           }
           if(!oae.empty() || !eao.empty()) move=-1;
           cout<<move<<endl;
       }
}