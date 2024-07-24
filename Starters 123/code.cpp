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
//         ll sum = 0;
//         for (ll i=0; i<n; i++)
//         {
//             ll x;
//             cin>>x;
//             sum += x/2;
//             if (x%2 !=0)
//                 sum++;
//         }
//         cout<<sum<<endl;
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
//         ll sum = 0;
//         ll result;
//         ll ans1 = INT_MAX;
//         ll ans2 = INT_MAX;
//         for (ll i=0; i<n; i++)
//         {
//             ll x;
//             cin>>x;
//             if (x < ans1)
//             {
//                 ans2 = ans1;
//                 ans1 = x;
//             }
//             else if (x < ans2)
//                 ans2 = x;
//             sum += x;    
//         }
//         // result = (2*sum)-(ans1+ans2);
//         cout<<(2*sum)-(ans1+ans2)<<endl;
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//  // your code goes here
//     int t;
//     cin>>t;
//     while(t--){
//         int n;
//         cin>>n;
//         int total=0;
//         int min1=INT_MAX, min2=INT_MAX;
//         for(int i=0;i<n;i++){
//             int k;
//             cin>>k;
//             if(k<min1){
//                 min2=min1;
//                 min1=k;
//             }
//             else if(k< min2) min2=k;
//             total+=k;
//         }
//         int maxSum=(2*total) -min1 -min2;
//         cout<<maxSum<<endl;
//     }
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
//         vector<ll>arr(n);
//         ll res = n*(n+1)/2;
//         if (n%2==0)
//             cout<<res+n<<endl;
//         else
//             cout<<res*res<<endl;    
        
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
//         if (n%2 ==0)
//         {
//             ll x = n/2;
//             cout<<(x*(x+1))<<endl;
//         }
//         else{
//             ll x = n/2;
//             cout<<(x*(x+1)) + (n+1)/2<<endl;
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
        ll sum = (n*(n+1))/2;
        cout<<(sum-1)+n<<endl;
    }
    return 0;
}