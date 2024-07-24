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
        ll x,y,k;
        cin>>x>>y>>k;
        ll p = x%y;
        p = y-p;
        if (k<p){
            cout<<x+k<<endl;
            continue;
        }       
        // if ((x+k)%y==0){
        //     ll m = (x+k)/y;
        //     ll c = 0;
        //     ll i = x;
        //     while (i != x+k){
        //         if (i%y==0)
        //             c++;
        //         i++;
        //     }
        //     cout<<(x+k)%y + c<<'h'<<endl;
        //     continue;
        // }
        // ll z = (((x+k)/y)%y + ((y+k)/y));
        // // while (z%y==0)
        // //     z = z/y;
        // if ((x+k)%y == 0){
        //     cout<<k/y+1 + z<<endl;
        //     continue;
        // }
        // while (z%y==0)
        //     z = z/y;
        // cout<<z<<endl;
        // // ll z = ((x+k)/y)%y + ;
        // for (ll i=0; i<k; i++)
        // {
        //     x++;
        //     while (x%y==0){
        //         x /= y;
        //     }
        // }

        // cout<<x<<endl;
        bool f = false;
        while (x!=1 && k>0){
            p = y-(x%y);
            if (k<p){
                f = true;
                break;
            }
            else{
                k -= p;
                x += p;
                while (x%y==0)
                    x /= y;
            }
        }
        if (f){
            cout<<x+k<<endl;
            continue;
        }

        cout<<x + k%(y-1)<<endl;
    }
    return 0;
}

