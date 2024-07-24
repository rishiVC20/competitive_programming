// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long 
// // ll sumOfDigits(ll n, vector<ll>&dp)
// // {
// //     if (n<10)
// //         return n;

// //     if (dp[n] != -1)
// //         return dp[n];

// //     dp[n] = n%10 + sumOfDigits(n/10,dp);    
// //     return dp[n];
// // }

// // int main() {
// //     ll t;
// //     cin>>t;
// //     while(t--)
// //     {
// //         ll n;
// //         cin>>n;
// //         vector<ll>arr(n);
// //         vector<ll>store(n);
// //         for (ll i=0; i<n; i++)
// //         {
// //             store[i]=i+1;
// //         }
// //         vector<ll>dp(n+1,-1);
// //         for (ll i=0; i<store.size(); i++)
// //         {
// //             if (store[i]>=10)
// //             {
// //                 ll p = sumOfDigits(store[i],dp);
// //                 arr[i] = p;
// //             }
// //             else
// //                 arr[i] = store[i];   
// //         }

// //         ll sum = 0;
// //         for (ll i=0; i<arr.size(); i++)
// //         {
// //             sum += arr[i];
// //         }
// //         cout<<sum;
// //         cout<<endl;
// //     }
// //     return 0;
// // }


// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         if (n<=9)
//         {
//             cout<<(n*(n+1))/2<<endl;
//             continue;
//         }
//         ll i=1;
//         ll grp = 1;
//         ll grpNo = 1;
//         ll count = 1;
//         ll ans = 45;
//         while (count <= n)
//         {
//             if (count==200)
//                 cout<<grp<<" "<<endl;
//             if (count%100==0)
//             {
//                     i=count/100;
//                 grpNo = 1;
//                 grp=1;
//             }
//             if (grp <= 10)
//             {
//                 ans += i;
//                 cout<<count<<": "<<i<<" ";
//             }
//             else{
//                 grp = 1;
//                 grpNo++;
//                 i = grpNo;
//                 ans += i;
//             cout<<count<<" :"<<i<<" ";      
//                      }
//             i++;
//             grp++;
//             count++;
            
//         }
//         cout<<endl;
//         cout<<ans<<endl;
//     }

//     return 0;
// }

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int MAX = 200'007;
const int MOD = 1'000'000'007;
ll arr[MAX];
ll Sum (ll x)
{
    ll res = 0;
    while (x)
    {
        res += x%10;
        x /= 10;
    }
    return res;
}
int main() {
    // ll totallen = 200000;
    
    ll ans = 0;
    arr[0]=0;
    for (ll i=1; i<MAX; i++)
    {
            arr[i] = arr[i-1]+Sum(i);        
    }
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        cout<<arr[n];
        cout<<endl;
    }
    return 0;
}

// https://codeforces.com/contest/1926/problem/C