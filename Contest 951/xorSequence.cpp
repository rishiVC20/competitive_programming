// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll> 

// const ll mod = 1e9+7;

// ll mul (ll a, ll b, ll m=mod)
// {
//     a = a % m;
//     b = b % m;
//     return (((a * b) % m) + m) % m;
// }
// ll power(ll base, ll exponent)
// {
//     if (exponent < 0)
//     {
//         return 0;
//     }
//     ll ans = 1;
//     while (exponent)
//     {
//         if (exponent%2==0)
//         {
//             base = (base*base) % mod;
//             exponent = exponent/2;
//         }
//         else
//         {
//             ans = (ans*base) % mod;
//             exponent--;
//         }
//     }
//     return ans;
// }


// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll x,y;
//         cin>>x>>y;
//         ll n = x^y;
//         ll cn = 0;
//         while ((n&1)^1 && n>0)
//         {
//             cn++;
//             n = n>>1;
//         }       

//         // ll sum = powl(2,cn);
//         ll sum = (ll)pow((ll)2,(ll) cn);


//         cout<<sum<<endl;
//     }
//     return 0;
// }



// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
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
    // for (ll i=0; i<)
    while (t--)
    {
        ll x,y;
        cin>>x>>y;    
        vi a1;
        vi a2;
        while (x){
            a1.pb(x%2);
            x >>= 1;
        }
        

        while (y){
            a2.pb(y%2);
            y >>= 1;
        }

        while (a1.size() < a2.size())
            a1.pb(0);
        while (a2.size() < a1.size())
            a2.pb(0); 
        ll cn = 0;
        for (ll i=0; i<a1.size(); i++)
        {
            if (a1[i] != a2[i])
                break;
            else
                cn++;    
        }            

        // cout<<(ll)powl((ll)2,(ll)cn)<<endl;
        cout<<power(2,cn)<<endl;
    }
    return 0;
}