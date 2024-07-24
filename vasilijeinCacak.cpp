// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k,x;
        cin>>n>>k>>x;
        ll sum2 = k*(k+1)/2;
        ll sum1 = n*(n+1)/2 - (n-k)*(n-k+1)/2;
        // ll sum1 = sum2 + (k+1);
        if (sum2>x || sum1<x)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;           
    }
    return 0;
}


// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,k,x;
//         cin>>n>>k>>x;
//         ll sum = 0;
//         ll flag = true;
//         for (ll i=n; i>n-k; i--)
//         {
//             cout<<i<<" ";
//             sum += (i+1);
//             if (sum>=x)
//                 break;
//             if (i==n-k){
//                 if (sum < x)
//                     flag = false;
//             }    
//         }       
//         if (!flag)
//             cout<<"NO"<<endl;
//         else
//             cout<<"YES"<<endl;    
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
//         ll n,k,x;
//         cin>>n>>k>>x;
//         ll sum = 0;
//         ll p =0;
//         for (ll i=n; i>=1; i--)
//         {
//             if (i > x-sum)
//             {
//                 // p++;
//                 continue;
//             }
//             else{
//                 p++;
//                 sum += i;
//             }
//             if (sum > x){
//                 break;
//             }
//         }
//         cout<<p<<" ";
//         if (p==k)
//             cout<<"YES"<<endl;
//         else
//             cout<<"NO"<<endl;    
//     }
//     return 0;
// }
/*
YES
NO
YES
YES
NO
NO
YES
NO
NO
NO
YES
YES

*/