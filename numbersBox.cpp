// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>>arr(n,vector<ll>(m));
        int count = 0;
        ll p = INT_MAX;
        ll sum = 0;
        for (ll i=0; i<n; i++)
        {
            
            
            for (ll j=0; j<m; j++)
            {
                ll x;
                cin>>x;
                arr[i][j] = x;
                sum += abs(x);
                if (x<=0)
                    count++;
                p = min(p,abs(x));    
            }
        }       
        // for (auto i:odd)
        //     cout<<i<<" ";
        
        // ll c = 0;
        
        if (count%2)
                sum -= 2*p;
        // cout<<c<<" ";
        cout<<sum<<endl;
    }
    return 0;
}