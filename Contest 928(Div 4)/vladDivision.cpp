// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// const int MAX = 200'007;
// const int MOD = 1'000'000'007;
// ll binary(ll x)
// {
//     ll ans = 0;
//     ll i=0;
//     while (x != 0)
//     {
//         ll bit = x&1;
//         ans = ans + (bit*pow(10,i));;
//         // x = x>>1;
//         x = x/10;
//         i++;
//     }
//     return ans;
// }
// int main() {
//     ll t;
//     cin>>t;
//     vector<ll>store;
//     // for (ll i=0; i<=MAX; i++)
//     // {
//     //     store[i] = binary(i);
//     // }
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vector<ll>arr(n);
//         for (ll i=0; i<n; i++)
//             cin>>arr[i];
//         ll result = n;
//         for (ll i=0; i<n-1; i++)
//         {
//             // ll p1 = store[arr[i]];
//             ll p2 = ~(arr[i]);
//             cout<<p2<<" "<<endl;
//             for (ll j=i+1; j<n; j++)
//             {
//                 // ll p2 = store[arr[j]];
//                 // ll pr = p1^p2;
//                 // cout<<pr;
                
//                 if (p2 == arr[j])
//                     result--;
//             }
//         }
//         cout<<result;
//         cout<<endl;
//     }
//     return 0;
// }

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll MASK = INT_MAX; 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];

        multiset<ll>ms;
        ll ans = 0;
        for (auto i:arr)
        {
            if (ms.find(MASK^i) != ms.end())
            {
                ans++;
                ms.erase(ms.find(MASK^i));
            }
            else
                ms.insert(i);
        }
        cout<<ans + ms.size();
        cout<<endl;
    }
    return 0;
}

// https://codeforces.com/contest/1926/problem/D