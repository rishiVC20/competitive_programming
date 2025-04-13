// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        string p,s;
        cin>>p>>s;

        ll n=(ll)p.size(),m=(ll)s.size();

        if(2*n < m || m<n){
            NO;
            continue;
        }

        ll cur=1;
        vector<pair<char,ll>>v;
        for(ll i=1; i<m; i++){
            if(s[i]==s[i-1]){
                cur++;
                if(i==m-1){
                    v.pb({s[i],cur});
                }
            }
            else{
                v.pb({s[i-1],cur});
                cur=1;
                if(i==m-1){
                    v.pb({s[i],cur});
                }
            }
        }
        if(m==1){
            v.pb({s[0],1});
        }
        
        vector<pair<char,ll>>dp;
        cur=1;
        for(ll i=1; i<n; i++){
            if(p[i]==p[i-1]){
                cur++;
                if(i==n-1){
                    dp.pb({p[i],cur});
                }
            }
            else{
                dp.pb({p[i-1],cur});
                cur=1;
                if(i==n-1){
                    dp.pb({p[i],cur});
                }
            }
        }
        if(n==1){
            dp.pb({p[0],1});
        }
        // for(auto i:dp){
        //     cout<<i.first<<' '<<i.second<<' ';
        // }
        // cout<<endl;
        // for(auto i:v){
        //     cout<<i.first<<' '<<i.second<<' ';
        // }
        // cout<<endl;
        if((ll)v.size() != (ll)dp.size()){
            NO;
            continue;
        }
        bool f=true;
        ll i=0,j=0;
        while(i<(ll)v.size() && j<(ll)dp.size()){
            if(v[i].first!=dp[j].first){
                f=false;
                break;
            }
            ll c1=v[i].second,c2=dp[j].second;
            if(c1<c2 || c1>2*c2){
                f=false;
                break;
            }
            i++,j++;
        }
        // cout<<"hi ";
        if(f){
            YES;
        }
        else{
            NO;
        }

    }
    return 0;
}