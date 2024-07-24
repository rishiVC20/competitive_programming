// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// #define pb push_back 
// #define onebit(x) __builtin_popcountll(x)
// #define vi vector<ll> 

// const ll mod = 1e9+7;

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
//         ll n;
//         cin>>n;
//         unordered_set<ll>st;
//         for (ll i=0; i<n; i++)
//         {
//             ll x;
//             cin>>x;
//             st.insert(x);
//         }
//         if (st.size()%2){
//             cout<<"Alice"<<endl;
//         }
//         else{
//             cout<<"Bob"<<endl;
//         }
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
        unordered_set<ll>s;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            s.insert(x);
        }       
        for (auto i:s)
        {
            a.pb(i);
        }
        
        sort(a.begin(),a.end());
        // for (auto i:a)
        //     cout<<i<<" ";
        bool ap = false;
        ll k = 0;
        for (ll i=0; i<a.size(); i++)
        {
            ap = !ap;
            // if (ap)
            //     ap = false;
            // else
            //     ap = true;    
            // cout<<ap<<" ";
            a[i] -= k;
            // cout<<a[i]<<" ";
            if (a[i]==1){
                k++;
                // continue;
            }
            else{
                break;
            }

        }
        if (ap)
            cout<<"Alice"<<endl;
        else
            cout<<"Bob"<<endl;
    }
    return 0;
}