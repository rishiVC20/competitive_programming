// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,l,r;
        cin>>n>>l>>r;

        vi a;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }

        vi k;
        for(ll i=0; i<r; i++){
            k.pb(a[i]);
        }
        vi p;
        for(ll i=l-1; i<n; i++){
            p.pb(a[i]);
        }

        sort(k.begin(),k.end());
        sort(p.begin(),p.end());
        ll mini1=0,mini2=0;

        ll t=r-l+1;
        ll x=k.size(),y=p.size();
        for(ll i=0; i<min(t,x); i++){
            mini1 += k[i];
        }

        for(ll i=0; i<min(t,y); i++){
            mini2 += p[i];
        }

        cout<<min(mini1,mini2)<<endl;

    }
    return 0;
}