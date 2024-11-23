#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;



int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;
        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        sort(a.begin(),a.end());

        vi b,pre;
        pre.pb(a[0]);
        for(ll i=1; i<n; i++){
            pre.pb(pre.back()+a[i]);
        }
        // for(ll i=0; i<n; i++){
        //     if(i+1 <= k){
        //         b.pb(pre[i]);
        //         continue;
        //     }
        //     ll h=0;
        //     ll sum=0;
            
        //     b.pb(sum);
        // }
        vi g;
        // for(ll i=0; i<=k; i++){
        //     ll sum=0;
        //     for(ll j=i; j<n; j+=(k+1)){
        //         sum += a[j];
        //     }
        //     g.pb(sum);
        // }
        for(ll i=0; i<n; i++){
            if(i+1 < k){
                b.pb(pre[i]);
                continue;
            }
            ll sum=0;
            for(ll j=i-k; j>=0; j-=(k)){
                sum += a[j];
            }
            b.pb(pre[i]-sum);

        }
        for(auto i:b)
            cout<<i<<' ';
        cout<<endl;    
    }
    return 0;
}