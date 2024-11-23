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
        ll n,d,l;
        cin>>n>>d>>l;
        if(n==2 && d==1 && l==2){
            cout<<1<<' '<<2<<endl;
            continue;
        }
        if(n<=l){
            cout<<-1<<endl;
            continue;
        }       
        if(l==n-1 && d==2){
            ll k=2;
            for(ll i=0; i<n-1; i++){
                cout<<1<<' '<<k<<endl;
                k++;
            }
            continue;
        }
        ll p=n-l;
        ll k=p+1;
        if(k!=d){
            cout<<-1<<endl;
            continue;
        }
        vector<pair<ll,ll>>v;
        ll m=2;
        ll j=1;
        for(ll i=0; i<l-1; i++){
            v.pb({1,m});
            m++;
            j++;
        }
        // cout<<x<<"h ";
        ll y=1;
        for(ll i=0; i<n-j; i++){
            v.pb({y,m});
            y=m,m++;
        }
        for(auto i:v){
            cout<<i.first<<' '<<i.second<<endl;
        }

    }
    return 0;
}