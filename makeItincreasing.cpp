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
//         for (ll i=0; i<n; i++)
//             cin>>a[i];
//         // sort(arr.begin(),arr.end(),greater <ll> ());
//         // for (ll i=0; i<n; i++)
//         //     cout<<arr[i]<<" ";
//         // cout<<endl;    
//         ll count = 0;
//         vector<ll>b;
//         ll m = 0; 
//         cout<<"hi"<<" ";
//         for (ll i=n-2; i>=0; i--)
//         {
//             ll p = a[i];
//             while (p >= a[i+1])
//             {
//                 cout<<"hi"<<" ";
//                 p = p/2;
//                 // cout<<p<<" ";
//                 count++;
//             }
//             a[i] = p;
//             b[m++] = a[i];
//         }    
//         b[m++] = a[n-1];
//         // vector<ll>b = a;
//         sort(b.begin(),b.end());
//         for (ll i=0; i<n; i++)
//             cout<<b[i]<<" ";
        
//         ll flag = true;
//         for (ll i=0; i<n; i++){
//             if (a[i] != b[i])
//             {
//                 flag = false;
//                 break;
//             }
//         }
//         if (flag)
//             cout<<count<<endl;
//         else
//             cout<<-1<<endl;    
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

        ll count = 0;
        ll flag = true;
        for (ll i=n-2; i>=0; i--)
        {
            while (a[i] >= a[i+1] && a[i]>0)
            {
                a[i] /= 2;
                count++;
            }
            if (a[i] == a[i+1])
            {
                flag = false;
                break;
            }
        }           
        if (flag)
            cout<<count<<endl;
        else
            cout<<-1<<endl;    
    }
    return 0;
}


