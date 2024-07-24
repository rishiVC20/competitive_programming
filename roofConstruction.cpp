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
//         for (ll i=0; i<n; i++)
//             arr.push_back(i);
//         double p = log2(n-1);
//         // for (auto i:arr)
//         //         cout<<arr[i]<<" ";
        
//         if (ceil(p) == floor(p))
//         {
//             // cout<<"hi"<<" ";
//             swap(arr[0],arr[n-2]);
                
//         }          
//         else{
//             swap(arr[0],arr[n-3]);
            
//         }
//         for (ll i=0; i<arr.size(); i++)
//             cout<<arr[i]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }


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
//         for (ll i=0; i<n; i++)
//             arr.push_back(i);
//         ll k = (n-1)/2;
//         for (ll i=k-1; i>=0; i--)
//             cout<<i<<" ";
//         for (ll i=k; i<n; i++)
//             cout<<i<<" ";
//         cout<<endl;                   
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
        ll l = 0;
        while (1<<(l+1) <= n-1)
            l++;
        for (ll i=(1<<l)-1; i>=0; i--)
            cout<<i<<" ";
        for (ll i=1<<l; i<n; i++)
            cout<<i<<" ";
        cout<<endl;                   
    }
    return 0;
}