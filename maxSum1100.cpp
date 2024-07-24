// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>arr;
        arr.push_back(0);
        for (ll i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        vector<ll>pre(n+1);
        pre[1] = arr[1];
        for (ll i=2; i<=n; i++)
            pre[i] = pre[i-1]+arr[i];

        // ll sum = accumulate(arr.begin(),arr.end(),0);
        ll sum = 0;
        // ll i=0;
        ll y=k;
        for (ll i=0; i<=k; i++)
        {
            sum = max(sum,pre[n-(k-i)]-pre[2*i]);
        }
        cout<<sum<<endl;
    }
    return 0;
}