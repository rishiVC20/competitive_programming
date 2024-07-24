// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b,c,x,y;
        cin>>a>>b>>c>>x>>y;
        ll p = x-a;
        if (p>0)
            c = c-p;
        ll k = y-b;
        if (k>0)
            c = c-k;
        if (c<0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;                      
    }
    return 0;
}