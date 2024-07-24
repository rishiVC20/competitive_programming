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
        ll k = arr[0];
        if(count(arr.begin(),arr.end(),k)==n){
            cout<<-1<<endl;
            continue;
        }
        vector<ll>p = arr;
        sort(p.begin(),p.end());
        ll curr = 1;
        ll maxi = 1;
        ll ans;
        for (ll i=1; i<n; i++){
            ll cnt = maxi;
            if (p[i]==p[i-1]){
                curr++;
            }
            else{
                curr = 1;
            }
            maxi = max(maxi, curr);
            if (cnt!=maxi)
                ans = p[i];
            // cout<<ans<<" ";    
        }
        // cout<<ans<<" ";
        // for(auto i:arr){
        //     cout<<i<<" ";
        // }
        curr = 1;
        ll mini = INT_MAX;
        bool f = true;
        for (ll i=1; i<n; i++)
        {
            if (arr[i]==ans && arr[i-1]==ans){
                curr++;
            }
            else if (arr[i]!=ans){
                mini = min(curr,mini);
                curr = 1;
                if (i==n)
                    f = false;
            }
        }
        if (!f){
            cout<<mini<<endl;
            continue;
        }
        mini = min(curr,mini);
        cout<<mini<<endl;
    }
    return 0;
}