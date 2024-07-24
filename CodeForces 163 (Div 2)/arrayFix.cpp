// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// bool check2digits(vector<ll> &b){
//     for (ll i=1; i<b.size(); i++){
//         if (b[i] < b[i-1])
//             return false;
//     }
//     return true;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vector<ll>a(n);
//         vector<ll>b;
//         ll p=0;
//         // bool 
//         for (ll i=0; i<n; i++){
//             cin>>a[i];
//             // cout<<a[i]<<" ";
//         }       
//         vector<ll>k = a;
//         sort(k.begin(),k.end());
//         bool see = true;
//         for (ll i=0; i<n; i++)
//         {
//             if (a[i] != k[i])
//             {
//                 see = false;
//                 break;
//             }
//         }
//         if (see){
//             cout<<"YES"<<endl;
//             continue;
//         }
//         vector<bool>ci(n,true);
//         // for (ll i=0; i<b.size(); i++)
//         //     cout<<b[i]<<" ";
//         // bool l = check2digits(b); 
//         // if (!l){
//         //     cout<<"NO"<<endl;
//         //     continue;
//         // }
//         bool flag = true;
//         for (ll i=1; i<n-2; i++)
//         {
//             // if (a[i-1] <= a[i] )
//             // {   
//                 if (a[i]>=a[i-1] && a[i]<=a[i+1])
//                     continue;
//                 else if (a[i+1]>=10 && a[i+1]/10>=a[i]%10)
//                 {
//                     continue;
//                 }
//                 if (a[i+1]<10 && a[i+1]>=a[i]%10)
//                 {
//                     continue;
//                 }
//                 else if (a[i-1]>=10 && a[i]>=10){
//                     if (a[i-1]%10 <= a[i]/10 && a[i])
//                         continue;
//                     else{
//                         flag = false;
//                     break;
//                     }    
//                 }
//                  else{
//                     flag = false;
//                     break;
//                 }
//             // }
           
//         }
//         if (a[n-2]%10 > a[n-1]){
//             flag = false;
//         }
//         if (flag){
//             cout<<"YES"<<endl;
//         }
//         else{
//             cout<<"NO"<<endl;
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
        ll curr = -1;
        for (ll i=0; i<n-1; i++){
            if (a[i] > a[i+1])
                curr = i;
        }          
        // cout<<curr<<" ";
        if (curr == -1){
            // cout<<"hi"<<" ";
            cout<<"YES"<<endl;
            continue;
        }
        vector<ll>z;
        for (ll i=0; i<=curr; i++){
            ll p1 = a[i];
            ll p2 = a[i]%10;
            ll p3 = a[i]/10;
            if (p1>=10){
                z.push_back(p3);
            }
            z.push_back(p2);
        }
        // for (ll i=0; i<z.size(); i++){
        //     cout<<z[i]<<" ";
        // }
        for (ll i=curr+1; i<n; i++){
            z.push_back(a[i]);
        }
        // for (ll i=0; i<z.size(); i++){
        //     cout<<z[i]<<" ";
        // }
        ll flag = true;
        for (ll i=0; i<z.size()-1; i++)
        {
            if (z[i]>z[i+1]){
                flag = false;
                break;
            }
        }
        if (!flag){
            cout<<"NO"<<endl;
        }
        else    
            cout<<"YES"<<endl;
    }
    return 0;
}

