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
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            cout<<n-x+1<<" ";
        }
        // for (ll i=1; i<=n; i++)
        //     cout<<i<<" ";
        cout<<endl;    
    }
    return 0;
}