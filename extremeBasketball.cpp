// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        ll p = (b+10) - a;
        if (p<0){
            cout<<0<<endl;
            continue;
        }
        ll ans = p/3+(p%3!=0);
        cout<<ans<<endl;        
    }
    return 0;
}