// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        while (q--)
        {
            ll l,r,k;
            cin>>l>>r>>k;
            ll sum = 0;
            for (ll i=0; i<l-1; i++)
                sum += arr[i];
            for (ll i=r; i<n; i++)
                sum += arr[i];
            sum += (r-l+1)*k;
            if (sum%2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;           
        }    
    }
    return 0;
}