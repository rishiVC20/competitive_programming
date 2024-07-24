// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,x;
//         cin>>n>>x;
//         vector<ll>arr(n);
//         for (ll i=0; i<n; i++)
//             cin>>arr[i];

//         ll l = arr[0];           
//         ll r = arr[0];
//         ll count = 0;
//         for (ll i=0; i<n; i++)
//         {
//             l = min(l,arr[i]);
//             r = max(r,arr[i]);
//             if (r-l > 2*x) //2*x range
//             {
//                 count++;
//                 r = arr[i];
//                 l = arr[i];
//             }
//         }           
//         cout<<count<<endl;
//     }
//     return 0;
// }

// /*
// 0
// 1
// 2
// 1
// 2
// 4
// 6

// */




