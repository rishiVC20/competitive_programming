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
        vector<ll>arr(n+1);
        vector<ll>pre(n+1);
        pre[0] = 0;
        for (ll i=1; i<=n; i++){
            cin>>arr[i];
            pre[i] = pre[i-1]+arr[i];
        }
        ll sm = accumulate(arr.begin(),arr.end(),0);
        // for (ll i=1; i<=n; i++)
        //     cout<<pre[i]<<" ";
        ll maxi = INT_MIN;
        for (ll i=1; i<n; i++)
        {
            ll pr = __gcd(pre[i],sm-pre[i]);
            // cout<<pr<<" ";
            maxi = max(maxi,pr);
        }
        cout<<maxi<<endl;
    }
    return 0;
}