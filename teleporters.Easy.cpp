// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,c;
//         cin>>n>>c;
//         // vector<ll>arr(n);
//         pair<ll,ll>arr[n];
//         for (ll i=0; i<n; i++){
//             cin>>arr[i].second;
//             arr[i].first = i+1;
//         }
//         // sort(arr,arr+n, [&](pair<ll,ll>x, pair<ll,ll>y){
//         //     return x.second < y.second;
//         // });
//         ll count = 0;    
//         for (ll i=0; i<n; i++)
//         {
//             if (c >= arr[i].second)
//             {
//                 c -= arr[i].first;
//                 if (c >= arr[i].second)
//                 {
//                     count++;
//                     c -= arr[i].second;
//                 }
//                 else    
//                     break;
//             }
//         }           
//         cout<<count<<endl;
//     }
//     return 0;
// }


// /*
// 2
// 2
// 0
// 1
// 2
// 2
// 1
// 1
// 1
// 2
// */






// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,c;
        cin>>n>>c;
        vector<ll>arr;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            arr.push_back(x+i+1);
        }
        sort(arr.begin(),arr.end());
        ll count = 0;
        for (ll i=0; i<n; i++)
        {
            if (c >= arr[i])
            {
                count++;
                c -= arr[i];
            }
            else
                break;
        }
        cout<<count<<endl;
    }
    return 0;
}