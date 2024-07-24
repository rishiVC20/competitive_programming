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
        string a,b;
        cin>>a>>b;
        ll x = a.size();
        ll y = b.size();
        // vector<vector<ll>>k(x+1,vector<ll>(y+1,-1));
        vector<vector<ll>>k(x+1,vector<ll>(y+1,0));

        ll sum = 0;
        // for (ll i=1; i<=x; i++)
        // {
        //     for (ll j=1; j<=y; j++)
        //     {
        //         // while (a[i-1]==b[j-1] && j<y){
        //         //     j++;
        //         //     sum++;
        //         // }
        //         if (a[i-1]==b[j-1]){
        //             // if (k[i-1][j-1]==-1){
        //             //     k[i-1][j-1] = 0;
        //             // }
        //             k[i][j] = k[i-1][j-1]+1;
        //         }
        //         else{
        //             k[i][j] = max(k[i-1][j],k[i][j-1]);
        //         }

        //         // cout<<k[i][j]<<' ';
        //     }
        // }

        // for (ll i=0; i<x; i++)
        // {
        //     for (ll j=0; j<y; j++)
        //     {
        //         if (a[i]==b[j])
        //             sum++;
        //     }
        // }

        // // if (sum > (x+y)){
        // //     cout<<x+y<<endl;
        // //     continue;
        // // }
        // cout<<(x+y) - sum<<endl;

        // cout<<(x+y)-sum<<endl;

        vector<bool>v(x,false);

        // for (ll i=0; i<y; i++)
        // {
        //     for (ll j=0; j<x; j++)
        //     {
        //         if (b[i]==a[j] && v[j]==false){
        //             v[j] = true;
        //             sum++;
        //         }
        //         // else if (b[i]==a[j] && v[j]==true){
                    
        //         // }
        //     }
        // }
        for (ll i=0; i<y; i++)
        {
            ll n = i;
            ll cn = 0;
            for (ll j=0; j<x; j++)
            {
                if (b[n]==a[j]){
                    cn++;
                    n++;
                }
            }
            sum = max(sum,cn);
        }

        cout<<(x+y) - sum<<endl;

    }
    return 0;
}