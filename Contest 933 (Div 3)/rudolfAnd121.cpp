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
//         vector<ll>arr(n);
//         bool flag = true;
//         for (ll i=0; i<n; i++)
//             cin>>arr[i];
//         if (arr[0]-arr[1]>=0 || arr[n-2]-arr[n-1]<=0)
//         {
//             cout<<"NO"<<endl;
//             continue;
//         }           
//         if (n==3)
//         {
//             if (arr[0]*2==arr[1] && arr[2]*2==arr[1])
//                 cout<<"YES"<<endl;
//             else
//                 cout<<"NO"<<endl;
//             continue;        
//         }
//         else if (n==4){
//             if (arr[0]*2<=arr[1] && arr[2]>=arr[3]*2)
//                 cout<<"NO"<<endl;
//             else if (abs(arr[2]-arr[1])%2)
//                 cout<<"NO"<<endl;
//             else
//                 cout<<"YES"<<endl;    
//         }
//         else{
//             for (ll i=1; i<n; i++)
//                 arr[i] += arr[i-1];
//             // for (ll i=0; i<n; i++)
//             //     cout<<arr[i]<<" ";    
//             ll ans = arr[2]-arr[1];
//             // cout<<ans<<" ";
//             // cout<<endl;
//             for (ll i=3; i<n-1; i++)
//             {
//                 // cout<<"hi"<<" ";
//                 ll p = arr[i]-arr[i-1];
//                 // cout<<p<<" ";
//                 if(p != ans)
//                 {
//                     flag = false;
//                     break;
//                 }
//             }       
//             if (flag)
//                 cout<<"YES"<<endl;
//             else
//                 cout<<"NO"<<endl;    
//         }
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
        for (ll i=0; i<n; i++)
            cin>>a[i];

        for (ll i=0; i<n-2; i++)
        {
            if (a[i] < 0){
                break;
            }
            a[i+1] -= 2*a[i];
            a[i+2] -= a[i];
            a[i] = 0;
            
        }   
        if (count(a.begin(),a.end(),0) == n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;            
    }
    return 0;
}
