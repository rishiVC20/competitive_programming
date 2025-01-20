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

const ll mod = 1e9+7;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;

        vi a(26,0);
        for(ll i=0; i<n; i++){
            ll t=s[i]-'a';
            a[t]++;
        }
        ll m=0;
        bool f=true;
        bool h=true;
        for(ll i=0; i<26; i++){
            if(a[i]!=0 && h){
                m=a[i];
                h=false;
            }
            if(a[i]!=0 && a[i]!=m){
                f=false;
                break;
            }
        }
        if(f){
            cout<<0<<endl;
            cout<<s<<endl;
            continue;
        }
        vector<pair<char,ll>> v;
        for(ll i=0; i<26; i++){
            char d='a'+i;
            v.pb({d,a[i]});

        }

        sort(v.begin(),v.end(),[&](pair<char,ll> &a, pair<char,ll> &b){
            return a.second > b.second;
        });
        ll mini=n;
        string ss=s;
        for(ll k=1; k<=26; k++){
            if(n%k != 0)
                continue;

            ll p=n/k;
            if(p>26)
                continue;
            // cout<<p<<' ';
            ll g=min(p,(ll)v.size());
            map<char,ll>mp;
            for(ll i=0; i<g; i++){
                char d=v[i].first;
                // mp[d]=min(k,v[i].second);
                mp[d]=k;
            }    
            string t="";
            for(ll i=0; i<n; i++){
                if(mp.find(s[i]) != mp.end() && mp[s[i]] > 0){
                    t+=s[i];
                    mp[s[i]]--;
                }
                else{
                    t+='*';
                }
            }
            // cout<<t<<' ';
            vector<char>d;
            for(auto i:mp){
                for(ll j=0; j<i.second; j++){
                    d.pb(i.first);
                }
            }
            // for(ll i=0; i<g; i++){
            //     ll m=abs(k-v[i].second);
            //     if(m>0){
            //         for(ll j=0; j<m; j++){
            //             d.pb(v[i].first);
            //         }
            //     }
            // }
            ll f=0;
            for(ll i=0; i<n; i++){
                if(t[i]=='*' && f<(ll)(d.size())){
                    t[i]=d[f];
                    f++;
                }
            }

            ll cn=0;
            for(ll i=0; i<n; i++){
                cn += (t[i]!=s[i]);
            }

            if(cn<mini){
                mini=cn;
                ss=t;
            }
            mp.clear();
            d.clear();
            t.clear();
            
        }

        // cout<<mini<<endl;
        // for(auto i:a)
        //     cout<<i<<' ';
        if(mini==n){
            ll t;
            for(ll i=1; i<=n-1; i++){
                if(n%i==0){
                    t=i;
                }
            }
            string w="";
            for(ll i=0; i<n; i++)
                w+='*';
            ll k=n/t;
            // cout<<t<<' '<<k<<' ';
            vector<char>qq;
            for(ll i=0; i<k; i++){
                char f=v[i].first;
                for(ll j=0; j<n; j++){
                    if(s[j]==f){
                        w[j]=f;
                    }
                    
                }
                for(ll j=0; j<abs(t-v[i].second); j++){
                    qq.pb(f);
                }
            }
            ll e=0;
            for(ll i=0; i<n; i++){
                if(w[i]=='*' && e<(ll)(qq.size())){
                    w[i]=qq[e];
                    e++;
                }
            }
            ll cn=0;
            for(ll i=0; i<n; i++){
                cn += (w[i]!=s[i]);
            }
            mini=cn;
            ss=w;
        }
        cout<<mini<<endl;
        cout<<ss<<endl;
    }
    return 0;
}