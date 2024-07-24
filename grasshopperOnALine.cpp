// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll x,k;
//         cin>>x>>k;
//         if (x%k != 0){
//             cout<<1<<endl;
//             cout<<x<<endl;
//             continue;
//         }
//         cout<<2<<endl;
//         cout<<(x-1)<<" "<<1<<endl;  
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
        ll sum = 0;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            sum += x/2;
            if (x%2 !=0)
                sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}