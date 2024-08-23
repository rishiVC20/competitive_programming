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
        vector<vector<ll>>v;
        ll maxi = INT_MAX;
        vector<tuple<ll,ll,ll>>b;
        ll dis=-1;
        for(ll i=0; i<n; i++){
            vi a;
            ll sum=INT_MIN;
            ll m;cin>>m;
            a.pb(m);
            for(ll j=0; j<m; j++){
                ll x; cin>>x;
                x -= j;
                // cout<<x<<' ';
                a.pb(x);
            }
            
            // cout<<a[0]<<' ';
            auto max_it = max_element(a.begin()+1, a.end());
            ll k = *max_it; 
            // cout<<k<<' ';
            // cout<<endl;
            ll index = distance(a.begin(), max_it);
            // cout<<index<<' ';
            b.pb(make_tuple(index,k,a[0]));
            if(k<=maxi){
                if(k==maxi && a[0]>dis){
                    dis=a[0];
                    maxi=k;
                }
                else{
                    maxi=k;
                    dis=a[0];
                }
            }
            v.pb(a);
        }
        // cout<<maxi<<' ';
        maxi++;

        sort(b.begin(), b.end(), [](const tuple<ll, ll, ll>& x, const tuple<ll, ll, ll>& y) {
            return get<1>(x) < get<1>(y);
        });
        vi d(b.size());
        d[0]=0;
        // cout<<get<2>(b[0])<<' ';
        for(ll i=1; i<b.size(); i++){
            // cout<<get<2>(b[i])<<' ';
            d[i]=d[i-1]+get<2>(b[i-1]);
        }
        // cout<<endl;
        // for(auto i:d)
        //     cout<<i<<' ';
        // cout<<endl;    
        ll ans=INT_MIN;
        for (ll i=0; i<b.size(); i++){
            ll j=get<1>(b[i]);
            // cout<<j<<' ';
            ans=max(ans,j-d[i]);
        }

        cout<<ans+1<<endl;

        

    }
    return 0;
}