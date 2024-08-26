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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        map<char,ll>mp;
        set<char>st;
        for(auto i:s){
            mp[i]++;
            st.insert(i);
        }
        // if(st.size()==1 || st.size()==n){
        //     cout<<s<<endl;
        //     continue;
        // }
        vector<pair<char,ll>>v;
        for(auto i:mp){
            v.pb({i.first,i.second});
        }
        sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.second>b.second;
        });
        ll j=0;
        vector<char>bb(n,'-');
        for(ll i=0; i<v.size(); i++){
            ll k=v[i].second;
            char m=v[i].first;
            
            while(k>0){
                bb[j]=m;
                
                k--;
                if(j>=n-2){
                    j=1;
                    continue;
                }
                j+=2;
            }
        }
        string b="";
        for(auto i:bb){
            b += i;
        }
        cout<<b;
        cout<<endl;
    }
    return 0;
}