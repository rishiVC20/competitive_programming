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
        a.pb(0);
        map<ll,ll>mp;
        // for (ll i=1; i<=n; i++)
        // {
        //     mp[i] = 0;
        // } 
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            a.pb(x);
            mp[x]++;
        }       
        // for (auto i:mp){
        //     cout<<i.first<<' '<<i.second<<' ';
        // }
        
        bool f = true;
        ll sum = 0;
        // sort(a.begin(),a.end());
        for (ll i=1; i<=n; i++)
        {
        //     cout<<mp[i]<<' ';
            if (mp[i]==0 && sum==0){
                f = false;
                break;
                for (auto j:mp){
                    // if (j.first > i)
                    //     continue;
                    // ll k = i-j.first;
                    // // if (k<=0)
                    // //     continue;
                    // if (mp.find(k) != mp.end()){
                    //     mp[j.first]--;
                    //     break;
                    // }
                    // else{
                    //     f = false;
                    //     break;
                    // }
                    // cout<<j.first<<' ';
                    if (j.first < i && mp[j.first] > 0){
                        // j.second--;
                        mp[j.first]--;
                        break;
                    }
                    else{
                        f = false;
                        break;
                    }
                }
                // cout<<mp[i]<<' ';
                // if (f==false)
                //     break;
            }
            else {
                sum = sum+ mp[i]-1;
                // mp[i]--;
                // cout<<i<<'h'<<' ';
            }
        }
        // for (auto i:mp){
        //     cout<<i.first<<' '<<i.second<<' ';
        // }
        if (f == true)
            YES;
        else if (f==false)
            NO;    

    }
    return 0;
}