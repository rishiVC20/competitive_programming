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
//         for (ll i=0; i<n; i++)
//             cin>>arr[i];
//         bool flag = true;
//         bool l = true;
//         ll p;
//         ll c = 0;
//         for (ll i=1; i<n; i++)
//         {
//             if (arr[i] >= arr[i-1]){
//                 c++;
//                 continue;
//             }
//             if (flag){
//                 // c++;
//                 p = arr[i-1];
//                 flag = false;
//             }    
//             else if (arr[i-1] != p)
//             {
//                 l = false;
//                 // break;
//             }
//         }    
//         if (c == n){
//             cout<<"Yes"<<endl;
//             continue;
//         }
//         if (!l){
//             cout<<"No"<<endl;
//             continue;
//         }
//         if (l){
//             cout<<"Yes"<<endl;
//             continue;
//         }
        
        
//     }
//     return 0;
// }



// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// bool checkvector(vector<ll> &arr)
// {
//     for (ll i=1; i<arr.size(); i++)
//     {
//         if (arr[i] < arr[i-1])
//             return false;
//     }
//     return true;
// }
// vector<ll> makeVector(vector<ll> &arr)
// {
//     vector<ll>a;
//     a.push_back(0);
//     for (ll i=1; i<arr.size(); i++)
//     {
//         a.push_back(a[i]-a[i-1]);
//     }
//     return a;
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         vector<ll>arr1;
//         vector<ll>arr2;
//         for (ll i=0; i<n; i++){
//             ll x;
//             cin>>x;
//             if (i%2)
//                 arr2.push_back(x);
//             else
//                 arr1.push_back(x);    
//         }
//         // bool p1 = checkvector(arr1);
//         // bool p2 = checkvector(arr2);
//         vector<ll>p1 = makeVector(arr1);
//         vector<ll>p2 = makeVector(arr2);
//         if (n%2 == 0)
//         {
//             bool flag = true;
//             for (ll i=0; i<n; i++)
//             {
//                 if (arr1[i] >= arr2[i])
//                     continue;
//                 else{
//                     flag = false;
//                     break;
//                 }    
                        
//             }
//             if (flag)
//                     cout<<"Yes"<<endl;
//                 else
//                     cout<<"No"<<endl;
//                 continue;
//         }
//         else{
//             bool flag = true;
//             for (ll i=0; i<arr2.size(); i++)
//             {
//                 if (arr2[i] >= arr1[i])
//                     continue;
//                 else{
//                     flag = false;
//                     break;
//                 }    
                

//             }
//             if (flag)
//                     cout<<"Yes"<<endl;
//                 else
//                     cout<<"No"<<endl;
//                 continue; 
//         }
//         // if (p1 && p2)
//         //     cout<<"Yes"<<endl;
//         // else
//         //     cout<<"No"<<endl;    

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
//         cout<<"safety"<<endl;
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
        string s;
        cin>>s;
        if (s=="it" || s=="submit" || s=="timelimitexceeded")
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;           
    }
    return 0;
}