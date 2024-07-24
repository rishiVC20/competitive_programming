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
        ll maxi = 1;
        ll mini = 999;
        for (ll i=0; i<n; i++){
            cin>>arr[i];
            maxi = max(maxi,arr[i]);
            mini = min(mini,arr[i]);
        }
        cout<<(maxi-mini)<<endl;

    }
    return 0;
}

