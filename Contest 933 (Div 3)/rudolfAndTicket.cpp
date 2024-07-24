// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
// vector<vector<ll>> TLE(40000, vector<int>(7));
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll>b(n);
        vector<ll>c(m);
        for (ll i=0; i<n; i++)
            cin>>b[i];
        for (ll i=0; i<m; i++)
            cin>>c[i];
        sort(b.begin(),b.end());        
        sort(c.begin(),c.end()); 
        ll sum = 0;
        for (ll i=0; i<n; i++)
        {
            for (ll j=0; j<m; j++)
            {
                if (b[i]+c[j] <= k)
                    sum++;
                else    
                    break;    
            }
        }       
        cout<<sum<<endl;
    }
    return 0;
}