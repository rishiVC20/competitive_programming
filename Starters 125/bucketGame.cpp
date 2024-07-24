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
//             sum += x;         
//         }
//         if (sum%2)
//             cout<<"Alice"<<endl;
//         else
//             cout<<"Bob"<<endl;    
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
        ll count1 = 0;
        ll count2 = 0;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            sum += x;
            if (sum%2==0)
                count1++;
            else
                count2++;    
        }
        // cout<<count1<<" ";
        // cout<<count2<<" ";
        if (count1 > count2){
            cout<<"Bob"<<endl;
        }
        else if (count1 == count2){
            cout<<"Draw"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define vi vector<ll> 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        
    }
    return 0;
}

