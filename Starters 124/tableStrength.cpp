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
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll j=1;
        ll p = 0;
        ll maxi = 0;
        for (ll i=n-1; i>=0; i--)
        {
            p = arr[i]*j;
            maxi = max(maxi,p);
            j++;
        }   
        cout<<maxi<<endl;
    }
    return 0;
}