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
        ll count = 0;
        bool flag = false;
        ll l;
        for (ll i=0; i<n; i++){
            ll x;  cin>>x;
            // cout<<x<<" ";
            arr.push_back(x);
            if (x <0 )
                count++;
            if (x == 0){
                flag = true;
            }    
            if (x)
                l = i;
        }
        if (flag || count%2!=0){
            cout<<0<<endl;
            continue;
        }
        cout<<1<<endl;
        cout<<l+1<<" "<<0<<endl;
    }
    return 0;
}