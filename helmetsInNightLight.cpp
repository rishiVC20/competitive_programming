// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,p;
//         cin>>n>>p;
//         pair<ll,ll>arr[n];
//         for (ll i=0; i<n; i++)
//             cin>>arr[i].first;
//         for (ll i=0; i<n; i++)
//             cin>>arr[i].second;

//         sort(arr,arr+n,[&](pair<ll,ll> x, pair<ll,ll> y){
//             return x.second < y.second;
//         });
//         ll ans = 0;
//         queue<ll>q;
//         for (ll i=0; i<n; i++)
//         {
//             if (q.empty())
//                 ans += p;
//             else{
//                 ans += q.front();
//                 q.pop();
//             }    
//             if (arr[i].second < p)
//             {
//                 for (ll j=0; j<arr[i].first; j++)
//                 {
//                     if (q.size() >= n)
//                         break;
//                     q.push(arr[i].second);    
//                 }
//             }
//         }
//         cout<<ans<<endl;        
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
        ll n,p;
        cin>>n>>p;
        pair<ll,ll>arr[n];
        for (ll i=0; i<n; i++)
            cin>>arr[i].first;
        for (ll i=0; i<n; i++)
            cin>>arr[i].second;    
        sort(arr,arr+n,[&](pair<ll,ll>x, pair<ll,ll>y){
            return x.second < y.second;
        });
        queue<ll>q;
        ll ans = 0;
        for (ll i=0; i<n; i++)
        {
            if (q.empty())
                ans += p;
            else{
                ans += q.front();
                q.pop();
            }     
            if (arr[i].second < p)
            {
                for (ll j=0; j<arr[i].first; j++)
                {
                    if (q.size() >= n)
                        break;
                    q.push(arr[i].second);    
                }
            }
        }       
        cout<<ans<<endl;
    }
    return 0;
}