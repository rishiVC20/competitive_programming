// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,k;
//         cin>>n>>k;
//         vector<ll>arr(n+1);
//         arr[0]=0;
//         for (ll i=1; i<=n; i++)
//         {
//             cin>>arr[i];
//         }       
//         ll ow = arr[k];
//         // cout<<ow<<" ";
//         ll l = 0;
//         // cout<<k-1<<" ";
//         for (ll i=1; i<=k; i++)
//         {
//             // if (arr[i] <= ow){
//                 l = i;
//                 break;
//             }
//         }
//         // cout<<l<<" ";
//         // cout<<k-1<<" ";
//         ll count = 0;
//         // if (l>1)
//         //     count++;    
//         if(l==0){
//             cout<<0<<endl;
//             continue;
//         } 
//         swap(arr[l],arr[k]);
//         for (auto i:arr)
//             cout<<i<<" ";
//         // cout<<ow<<" ";
//         for (ll i=l; i<=n; i++)
//         {
//             if (arr[i] < ow){
//                 count++;
//             }
//             else if (arr[i]==ow)
//                 continue;
//             else{
//                 break;
//             }
//         }
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
        ll n,k;
        cin>>n>>k;
        vector<ll>arr(n+1);
        for (ll i=1; i<=n; i++)
            cin>>arr[i];
        bool f = true;
        ll count = 0;
        for (ll i=1; i<=n; i++)
        {
            if (arr[i] == arr[k])
                continue;
            if (f && arr[i] < arr[k])
            {
                count++;
            }
            else if (f){
                f = false;
            }
        }           
        cout<<count<<endl;
    }
    return 0;
}

