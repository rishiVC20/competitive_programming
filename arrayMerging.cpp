// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vector<ll>a(n);
//         vector<ll>b(n);
//         vector<ll>c(2*n);
//         for (ll i=0; i<n; i++)
//             cin>>a[i];
//         sort(a.begin(),a.end());    
//         for (ll i=0; i<n; i++)
//             cin>>b[i];        
//         sort(b.begin(),b.end(), greater<ll>());
//         ll p = 0;
//         for (ll i=0; i<n; i++){
//             c[i] = a[p++];
//         }
//         p = 0;
//         for (ll i=n; i<2*n; i++)
//             c[i] = b[p++];
//         ll cnt = 1;
//         ll ans = INT_MIN;
//         for (ll i=1; i<2*n; i++)
//         {
//             if (c[i] == c[i-1])
//             {
//                 cnt++;
//                 ans = max(ans,cnt);
//             }
//             else{
//                 cnt = 1;
//                 ans = max(ans,cnt);
//             }
//             ans = max(ans,cnt);
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
        ll n;
        cin>>n;
        vector<ll>a(n);
        vector<ll>b(n);
        vector<ll>c;
        for (ll i=0; i<n; i++){
            cin>>a[i];
            c.push_back(a[i]);
        }
        for (ll i=0; i<n; i++){
            cin>>b[i];
            c.push_back(b[i]);
        }
        ll cnt = 0;
        for (ll i=0; i<c.size(); i++){
            ll k = count(c.begin(),c.end(),c[i]);
            cnt = max(cnt, k);
        }
        cout<<cnt<<endl;

    }
    return 0;
}