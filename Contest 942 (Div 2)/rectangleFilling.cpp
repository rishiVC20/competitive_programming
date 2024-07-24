// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<char>> v(n,vector<char>(m));
        for (ll i=0; i<n; i++)
        {
            // string s;
            // cin>>s;
            // cout<<"k"<<" ";
            // v.pb(s);
            for (ll j=0; j<m; j++)
                cin>>v[i][j];
        }       
        // cout<<"j"<<" ";
        ll minw=m,maxw=0,minb=m,maxb = 0;
        ll minwl=m,maxwr=0,minbl=m,maxbr = 0;
        for (ll i=0; i<n; i++)
        {
            // string v[i];
            for (ll j=0; j<m; j++)
            {
                if (v[i][j]=='W')
                {
                    minw = min(minw,i);
                    maxw = max(maxw,i);
                    minwl = min(minwl,j);
                    maxwr = max(maxwr,j);
                }
                if (v[i][j]=='B')
                {
                    minb = min(minb,i);
                    maxb = max(maxb,i);
                    minbl = min(minbl,j);
                    maxbr = max(maxbr,j);
                }
            }
        }
        // cout<<minb<<" "<<maxb<<" "<<minw<<" "<<maxw<<" ";
        // cout<<minbl<<" "<<maxbr<<" "<<minwl<<" "<<maxwr<<" ";
        if (minw==0 && maxw==n-1 && minwl==0 && maxwr==m-1){
            cout<<"YES"<<endl;
            continue;
        }

        else if ((minb==0 && maxb==n-1) && (minbl==0 && maxbr==m-1)){
            cout<<"YES"<<endl;
            continue;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}