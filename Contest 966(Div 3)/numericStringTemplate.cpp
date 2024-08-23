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
        vi a;
        for (ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
        }
        ll m;cin>>m;
        for (ll i=0; i<m; i++){
            string s;cin>>s;
            if (s.size()!=n){
                NO;
                continue;
            }
            map<char,ll>mp;
            set<ll>st;
            set<char>st1;
            bool f=true;
            for (ll j=0; j<n; j++){
                // cout<<mp[s[j]]<<' '; 
                if (st.find(a[j])==st.end() && st1.find(s[j])==st1.end()){
                    mp[s[j]]=a[j];
                    st.insert(a[j]);
                    st1.insert(s[j]);
                }
                else if (st.find(a[j])!=st.end() && st1.find(s[j])!=st1.end()){
                    if (mp[s[j]]!=a[j]){
                        f=false;
                        break;
                    }
                }
                else{
                    f=false;
                    break;
                }
                // cout<<mp[s[j]]<<' ';
            }
            if (f)
                YES;
            else
                NO;    

        }      
    }
    return 0;
}