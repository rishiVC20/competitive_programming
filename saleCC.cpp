// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// ll maxElement(vector<ll> &arr)
// {
//     ll maxi = 0;
//     for (ll i=0; i<arr.size(); i++)
//     {
//         maxi = max(maxi,arr[i]);
//     }
//     return maxi;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         // cout<<n<<" ";
//         vector<ll>arr(n);
//         for (ll i=0; i<n; i++)
//             cin>>arr[i];
//          ll maxi = maxElement(arr);
//         // cout<<maxi<<" ";
//         ll cnt = count(arr.begin(),arr.end(),maxi);
//         // cout<<cnt<<" ";
//         ll sum = 0;
//         ll c = 0;
//         for (ll i=0; i<n; i++)
//         {
//             // cout<<"hi"<<" ";
//             sum += arr[i];
//             if (arr[i]==maxi)
//                 c++;
//             if (arr[i]==maxi && c==cnt)  {
//                 sum += arr[i];
                
//                 break;
//             }  
//         }    
//         cout<<sum<<endl;
//     }   
//     return 0;
// }


// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// ll maxElement(vector<ll> &arr)
// {
//     ll maxi = 0;
//     for (ll i=0; i<arr.size(); i++)
//     {
//         maxi = max(maxi,arr[i]);
//     }
//     return maxi;
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
//         bool p = true;
//         ll k;
//         ll sum1 = arr[n-1];
//         for (ll i=n-2; i>=0; i--)
//         {
//             if (arr[i] > sum1)
//             {
//                 k = i;
//                 p = false;
//                 // break;
//             }
//             // else{
//             sum1 += arr[i];
//             // }
//         }         
//         if (p)
//         {
//             ll sum = accumulate(arr.begin(),arr.end(),0);
//             cout<<sum+arr[n-1]<<endl;
//             continue;
//         }
//         // ll sit = n-k;
//         ll ans = 0;
//         ll maxi = maxElement(arr);
//         for (ll i=0; i<=k; i++)
//         {
//             ans += arr[i];
//             if (i==k)
//                 ans += arr[i];
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }












// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll maxElement(vector<ll> &arr)
{
    ll maxi = 0;
    for (ll i=0; i<arr.size(); i++)
    {
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        vector<ll>store(n);
        ll sum = 0;
        for (ll i=0; i<n; i++)
        {
            cin>>arr[i];
            sum += arr[i];
            store[i] = sum + arr[i];
        }
        ll res = maxElement(store);
        cout<<res<<endl;

    }
    return 0;
}