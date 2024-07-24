// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll k,q;
        cin>>k>>q;
        ll mini = INT_MAX;
        for (ll i=0; i<k; i++)
        {
            ll x;
            cin>>x;
            mini = min(mini,x);
        }
        vector<ll>arr;
        for (ll i=0; i<q; i++)
        {
            ll x;
            cin>>x;
            if (x < mini){
                arr.push_back(x);
            }
            else if (x >= mini){
                arr.push_back(mini-1);
            }
        }
        for (auto i:arr)
            cout<<i<<" ";
        cout<<endl;    
    }
    return 0;
}