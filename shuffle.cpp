// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
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
        ll n,x,m;
        cin>>n>>x>>m;
        // 1<=x<=n      n<=10^9
        // vi a(n+1,0);
        // a[x]=1;
        vector<pair<ll,ll>>v;
        bool f=false;
        for(ll i=0; i<m; i++){
            ll l,r;
            cin>>l>>r;
            // cout<<f<<'l'<<' ';
            if(x>=l && x<=r && f==false){
                v.pb({l,r});
                f=true;
                // cout<<'m';
                continue;
            }
            if(f){
                for(ll j=0; j<v.size(); j++){
                    // cout<<'k';
                    if((l>=v[j].first && l<=v[j].second) || (r>=v[j].first && r<=v[j].second)){
                        v.pb({l,r});
                        // cout<<'k';
                        break;
                    }
                    else if(l<=v[j].first && r>=v[j].second){
                        v.pb({l,r});
                        break;
                    }
                }
            }
        }       
        if(v.size()==0){
            cout<<1<<endl;
            continue;
        }
        // for(auto i:v)
        //     cout<<i.first<<' '<<i.second<<' ';
        ll cn=0;
        sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.first<b.first;
        });
        // cout<<'i';
        // for(auto i:v)
        //     cout<<i.first<<' '<<i.second<<' ';
        ll mini = v[0].first;
        ll maxi = v[0].second;
        if(v.size()==1){
            cout<<maxi-mini+1<<endl;
            continue;
        }
        vector<pair<ll,ll>>b;
        bool mm=false;
        for(ll i=1; i<v.size(); i++){
            if(v[i].first>= mini && v[i].first<=maxi){
                maxi = max(maxi,v[i].second);
                mm=true;
            }
            else if(v[i].second>=mini && v[i].second<=maxi){ 
                mini=min(mini,v[i].first);
                mm=true;
            }
            else{
                b.pb({mini,maxi});
                mini=v[i].first;
                maxi=v[i].second;
                mm=false;
            }
        }
        if(mm){
            b.pb({mini,maxi});
        }
        // for(auto i:b)
        //     cout<<i.first<<' '<<i.second<<' ';
        for(ll i=0; i<b.size(); i++){
            cn += (b[i].second-b[i].first)+1;
        }
        bool h=false;
        for(ll i=0; i<b.size(); i++){
            if(x>=b[i].first && x<=b[i].second){
                h=true;
                break;
            }
        }
        cout<<cn<<endl;
    }
    return 0;
}