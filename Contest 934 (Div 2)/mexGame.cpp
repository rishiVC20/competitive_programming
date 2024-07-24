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
//         vector<ll>b;
//         for (ll i=0; i<n; i++){
//             cin>>a[i];
            
//         }
//         sort(a.begin(),a.end());
//         for (ll i=0; i<n; i++){
//             if (i%2==0)
//                 b.push_back(a[i]);
//         }
//         for (auto i:b)
//             cout<<i<<" ";
//         ll p = 0;
//         ll count = INT_MIN;
//         for (auto num:b)
//         {
//             if (find(b.begin(),b.end(),p) != b.end()){
//                 p++;
//             }
//             else{
//                 count = p;
//                 break;
//             }
//         }
//         if (count == INT_MIN)
//             count = p;
//         cout<<count<<endl;
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
        unordered_map<ll,ll>v;
        for (ll i=0; i<n; i++)
        {
            cin>>a[i];
            v[a[i]]++;
        }       
        ll ans;
        bool p = 1;
        for (ll i=0; i<=n; i++)
        {
            if (v[i]>=2)
                continue;
            else if (v[i]==1) 
            {
                if (p){
                    p=0;
                }
                else{
                    ans = i;
                    break;
                }
            }   
            else if (v[i]==0)
            {
                ans = i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}