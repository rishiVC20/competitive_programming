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
        ll cnt = 0;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            // ll k = count(arr.begin(),arr.end(),x);
            // if (k==1)
            //     cnt++;
            arr.push_back(x);    
        }       
        sort(arr.begin(),arr.end());
        for (ll i=1; i<n; i++)
        {
            if (arr[i]==arr[i-1])
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}