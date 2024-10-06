// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  


int main() {
    ll t=1;
    // cin>>t;
    while (t--)
    {
        // cout<<(ll)sqrtl(200) << ' ';
        ll n,m;
        cin>>n>>m;
        vector<vi>v(n,vector<ll>(m));
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                cin>>v[i][j];
            }
        }       
        unordered_map<ll,vector<pair<ll,ll>>>mp;
        for(ll i=0; i<n; i++){
            for(ll j=0; j<m; j++){
                ll k=v[i][j];
                mp[k].pb({i,j});
            }
        }

        ll cn=0;
        ll sum=0;
        for(auto i:mp){
            ll b=i.first;
            // cout<<b<<' ';
            ll cn=0;
            vector<pair<ll,ll>>c=i.second;
            // for(auto h:c)
            //     cout<<h.first<<' '<<h.second<<"k ";
            sort(c.begin(),c.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
                return a.first<b.first;
            });
            ll u=0,w=0;
            for(auto j:c){
                sum += j.first*u-w;
                w += j.first;
                u++;
            }
            sort(c.begin(),c.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
                return a.second<b.second;
            });
            u=0,w=0;
            for(auto j:c){
                sum+=j.second*u-w;
                w+=j.second;
                u++;
            }
        }

        cout<<sum<<endl;    
    }
    return 0;
}