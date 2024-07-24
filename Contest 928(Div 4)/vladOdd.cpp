// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// bool found(ll &x, vector<ll> &arr)
// {
//     for (ll i=0; i<arr.size(); i++)
//     {
//         if (arr[i] == x)
//             return true;
//     }
//     return false;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {   
//         ll n,k;
//         cin>>n>>k;
//         vector<ll>arr(n);
//         // for (ll i=1; i<=n; i++)
//         //     arr[i] = i;
//         for (ll i=1; i<=n; i++)
//         {
//             if(i%2 != 0)
//                 arr.push_back(i);
//         }
//         for (ll i=2; i<=n; i+=4)
//         {
//             // if (i%2 == 0)
//             arr.push_back(i);
//         }
//         for (ll i=3; i<=n; i+=6)
//         {
//             // if (found(i,arr))
//             //     continue;
//             if (!found(i,arr))
//                 arr.push_back(i);    
//         }
//         for (ll i=4; i<=n; i+=8)
//         {
//             // if (found(i,arr))
//             //     continue;
//             if (!found(i,arr))
//                 arr.push_back(i);
//         }
//         cout<<arr[k-1]<<endl;
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
        ll n,k;
        cin>>n>>k;
        if (k <= (n+1)/2)
            cout<<2*k-1<<endl;
        else
        {
            ll sum = (n+1)/2;
            ll power = 2;
            while (power <= n)
            {
                int odd = n/power;  
                sum += (odd+1)/2;
                if (sum >= k)
                {
                    ll idx = (odd+1)/2-(sum-k);
                    cout<<(2*idx-1)*power<<endl;
                    break;
                }
                power *= 2;
            }
        }    
    }   
    return 0;
}

// https://codeforces.com/contest/1926/problem/E