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
//         vector<ll>arr1(n);
//         for (ll i=0; i<n; i++)
//         {
//             cin>>arr[i];
//             arr1[i] = arr[i];
//         }
//         sort(arr.begin(),arr.end(), greater<int>());
//         ll mod = arr[0];
//         for (ll i=1; i<n; i++)
//         {
//             mod = mod%arr[i];
//         }
//         ll mod1 = arr1[0];
//         for (ll i=1; i<n; i++)
//         {
//             mod1 = mod1%arr1[i];
//         }
//         if (mod != 0 || mod1 != 0)
//             cout<<"YES"<<endl;
//         else
//             cout<<"NO"<<endl;    
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
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];

        ll mini = *std::min_element(arr.begin(),arr.end());
        if (count(arr.begin(),arr.end(),mini) == 1){
            cout<<"YES"<<endl;
            continue;
        }    
        bool flag = false;
        for (ll i=0; i<n; i++)
        {
            if(arr[i]%mini != 0)
            {
                flag = true;
                break;;
            } 
        }
        if (flag)
            cout<<"YES"<<endl;
        else    
            cout<<"NO"<<endl;
    }
    return 0;
}