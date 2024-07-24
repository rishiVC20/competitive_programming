// // // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// vector<ll> zeroCounts(vector<ll>& arr) {
//     vector<ll> zeros;
//     ll zeroCount = 0;
//     bool ones_found = false;

//     for (ll num : arr) {
//         if (num == 1) {
//             if (ones_found && zeroCount > 0) {
//                 zeros.push_back(zeroCount);
//             }
//             ones_found = true;
//             zeroCount = 0;
//         } else if (ones_found) {
//             zeroCount++;
//         }
//     }

//     return zeros;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vector<ll>arr(n);
//         for (ll i=0; i<n; i++)
//             cin>>arr[i];

//         vector<ll>zeros = zeroCounts(arr);
//         ll sum = 0;
//         for (ll count:zeros)
//             sum += count;

//         cout<<sum<<endl;    
//     }
//     return 0;
// }

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        ll cnt = 0;
        for (ll i=0; i<n; i++){
            cin>>arr[i];
            cnt += (arr[i]==1);
        }
        // cout<<cnt<<endl;
        ll ans = 0;
        ll one = 0;
        for (auto e:arr)
        {
            if (one)
                ans += (e==0);

            // cout<<ans<<" ";
            one += (e==1);
            // cout<<one<<" ";
            if (one == cnt);
                break;    
        }
        // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}