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
//         string s;
//         cin>>s;
//         string p = s.substr(k);
//         ll sum = 0;
//         for (ll i=k; i<n; i++){
//             if (p[i]=='1')
//                 sum++;
//         } 
//         if (sum==0){
//             string l = "";
//             while (n>k){
//                 l += '0';
//                 k++;
//             }
//             cout<<l<<endl;
//             continue;
//         }
//         if (sum == k){
//             string l = "";
//             while (n>k){
//                 l += '0';
//                 n--;
//             }
//             cout<<l<<endl;
//             continue;
//         }
//         // ll m = 0;
//         // while (k > 0){
//         //     if (p[m]=='1'){
//         //         k--;
//         //         p[m]='0';
//         //     }
//         //     m++;
//         // }
//         // cout<<p<<endl;
//         if (sum > k)
//         {
//             ll m=0;
//             while (k > 0){
//                 if (s[m]=='1'){
//                     k--;
//                     s[m]='0';
//                 }
//                 m++;
//             }
//         cout<<p<<endl;
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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll c1 = 0;
        for (ll i=0; i<n; i++)
            if (s[i]=='1')
                c1++;
        if (c1>k){
            ll m =0;
            while (k>0)
            {
                if (s[m]=='1'){
                    s[m]='0';
                    k--;
                }
                m++;
            }
            cout<<s<<endl;
        }               
        else{
            while (n>k){
                cout<<0;
                k++;
            }
            cout<<endl;
        }
    }
    return 0;
}