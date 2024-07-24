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
        vector<ll>arr;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            arr.push_back(x);
        }       
        sort(arr.begin(),arr.end());
        ll ans = 0;
        for (ll i=0; i<n; i++)
        {
            ans += abs(arr[i]-i);
        }
        cout<<ans<<endl;
    }
    return 0;
}