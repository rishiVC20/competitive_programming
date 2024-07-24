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
//         vector<ll>arr;
//         ll sum = 0;
//         for (ll i=0; i<n; i++)
//         {
//             ll x;
//             cin>>x;
            
//             ll k = pow(2,x);
//             sum += k;
//             arr.push_back(k);
//         }       
//         sort(arr.begin(),arr.end());
//         ll s = sum/2;
//         vector<ll>pre(n);
//         pre[n-1] = arr[n-1];
//         for (ll i=n-2; i>=0; i--)
//         {
//             pre[i] = pre[i-1]+arr[i];
//         }
//         if (count(pre.begin(),pre.end(),s) == 1)
//             cout<<"YES"<<endl;
//         else
//             cout<<"NO"<<endl;    
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
        vector<ll>arr;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            // ll k = powl(2,x);
            arr.push_back(x);
        }       
        ll c = true;
        for (ll i=0; i<n; i++)
        {
            if (count(arr.begin(),arr.end(),arr[i]) > 1)
            {
                c = false;
                break;
            }
        }
        if (!c){
            cout<<"YES"<<endl;
            continue;
        }
        else {
            cout<<"NO"<<endl;
        }
            
    }
    return 0;
}