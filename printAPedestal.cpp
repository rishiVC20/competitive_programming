// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        // cout<<2<<" "<<n-3<<" "<<1<<endl;   
        ll c = 1;
        ll p = (n-1)/2;
        ll k = n-1-p;
        cout<<min(p,k)<<" "<<max(p,k)<<" "<<c<<endl;   
    }
    return 0;
}