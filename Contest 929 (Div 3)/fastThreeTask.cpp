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
//         ll sum = 0;
//         for (ll i=0; i<n; i++){
//             cin>>arr[i];
//             sum += arr[i];
//         }
//         if (n==1){
//             cout<<1<<endl;
//             continue;
//         }  
//         if (sum%3 ==0 ){
//             cout<<0<<endl;
//             continue;
//         }     
        
//         sort(arr.begin(),arr.end());
//         ll sum1=0,sum2=0;
//         for (ll i=0; i<n-1; i++)
//             sum1 += arr[i];
//         for (ll i=1; i<n; i++)
//             sum2 += arr[i];

//         if (sum1%3==0 || sum2%3==0)
//             cout<<1<<endl;
//         else if (sum%3 == 2){
//             cout<<1<<endl;
//             // continue;
//         }     
//         else
//             cout<<2<<endl;            
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
        vector<ll>arr(n);
        ll cnt = 0;
        for (ll i=0; i<n; i++){
            cin>>arr[i];
            if (arr[i]%3 == 0)
                cnt++;
            sum += arr[i];
        }
        if (sum%3 == 0){
            cout<<0<<endl;
            continue;
        }
        else if (sum%3 == 2){
            cout<<1<<endl;
            continue;
        }
        bool flag = false;
        for (ll i=0; i<n; i++)
        {
            if ((sum-arr[i])%3 == 0)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout<<1<<endl;
        else
            cout<<2<<endl;    
          
    } 
    return 0;
}

// https://codeforces.com/contest/1933/problem/B