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


    ll tt=1;
    // cin>>tt;
    while (tt--)
    {
        string s;
        cin>>s;
        ll n=s.size();
        vector<ll>v;
        string p="";
        for(ll i=0; i<n; i++){
            if(s[i]==','){
                v.pb(stoi(p));
                p="";
            }
            else{
                p+=s[i];
            }
        }
        v.pb(stoi(p));

        ll cn=1;
        for(ll i=0; i<v.size(); i++){
            cn=(cn*v[i])%mod;
        }
        string ans="";
        for(ll i=0; i<(ll)v.size(); i++){
            ll k=cn/v[i];
            string d=to_string(k);
            if(i==(ll)v.size()-1){
               ans+=d;
            }
            else{
                ans+=d;
                ans+=",";

            }
        }

        cout<<ans<<endl;
    }
    return 0;
}