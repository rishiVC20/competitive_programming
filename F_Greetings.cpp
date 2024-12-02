// Rishikesh Chaudhari
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vector<pair<ll,ll>>v;

        for(ll i=0; i<n; i++){
            ll x,y;
            cin>>x>>y;
            v.pb({x,y});
        }

        sort(v.begin(),v.end(),[&](pair<ll,ll>&a, pair<ll,ll>&b){
            return a.first<b.first;
        });
        // vector<pair<ll,ll>>w=v;

        // sort(w.begin(),w.end(),[&](pair<ll,ll>&a, pair<ll,ll>&b){
        //     return a.second<b.second;
        // });

        ll cn=0;
        // for(ll i=0; i<n; i++){
        //     vector<pair<ll,ll>>d=v;
        //     ll x=w[i].first,y=w[i].second;

        //     auto it=lower_bound(d.begin(),d.end(),make_pair(x,0));
        //     ll m=it-d.begin();
        //     cn += m;
        //     d.erase(it);

        //     v=d;

        // }

        // cout<<cn<<endl;


        ordered_set st;
        st.clear();

        for(ll i=0; i<n; i++){
            ll x=v[i].first,y=v[i].second;
            cn += st.size()-st.order_of_key(y);

            st.insert(y);
        }

        cout<<cn<<endl;
        

    }
    return 0;
}