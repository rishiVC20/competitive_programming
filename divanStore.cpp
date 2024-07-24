// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,l,r,k;
        cin>>n>>l>>r>>k;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll count = 0;
        for (ll i=0; i<n; i++){
            if (arr[i]>=l && arr[i]<=r && arr[i]<=k){
                // cout<<arr[i]<<" ";
                count++;
                k -= arr[i];

            }
        }    
        cout<<count<<endl;
    }
    return 0;
}