// // // Rishikesh Chaudhari
// // #include<bits/stdc++.h>
// // using namespace std;

// // #define ll long long 
// // int main() {
// //     ll t;
// //     cin>>t;
// //     while (t--)
// //     {
// //         ll l,r;
// //         cin>>l>>r;
// //         ll n = (r-l+1);
// //         vector<ll>a(n);
// //         vector<ll>b(n);
// //         ll p=0;
// //         for (ll i=l; i<=r; i++)
// //             a[p++] = i;
// //         if (__gcd(l,r) != 1 && n%2!=0 && l!=1){
// //             cout<<-1<<endl;  
// //             continue;
// //         }
// //         else if (r%l==0 && n%2==0 && l!=1 ) 
// //         {
// //             for (ll i=0; i<n-1; i+=2)
// //             {
// //                 swap(a[i],a[i+1]);
// //             }
// //         }
// //         else{
// //             if (__gcd(l,r) != 1 && l!=1){
// //                 cout<<-1<<endl;
// //                 continue;
// //             }
// //             ll temp = a[0];
// //             for (ll i=0; i<n-1; i++)
// //             {
// //                 a[i] = a[i+1];
// //             }
// //             a[n-1] = temp;

// //         }
// //         for (ll i=0; i<n; i++)
// //             cout<<a[i]<<" ";
// //         cout<<endl;    
// //     }
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// int main()
// {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         string s;
//         cin >> s;
//         ll nes = s.size();
//         ll maxi=INT_MAX;
//         for (int i = 0; i < 26; i++)
//         {
//             char x = 'a';
//             x += i;
//             ll count=0;
//             for(int i=0;i<nes;i++)
//             {
//                 if(s[i]==x)
//                 {
//                     count++;
//                 }
//             }
//             if(count==0)
//             {
//                 continue;
//             }
//             ll l=0;
//             ll r=count-1;
//             ll extra=0;
//             for(int i=l;i<=r;i++)
//             {
//                 if(s[i]!=x)
//                 {
//                     extra++;
//                 }
//             }
//             ll ans=extra;
//             while(r<=nes-1)
//             {
//                 ans=min(ans,extra);
//                 if(s[l]!=x)
//                 {
//                     extra--;
//                 }
//                 l++;
//                 r++;
//                 if(r<=nes-1 && s[r]!=x)
//                 {
//                     extra++;
//                 }
                
//             }
//             maxi=min(ans,maxi);
//         }
//         cout<<maxi<<endl;
//     }
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
        ll l,r;
        cin>>l>>r;
        ll n = (r-l+1);
        vector<ll>a(n);
        ll p = 0;
        for (ll i=l; i<=r; i++)
            a[p++] = i;
        if (n%2 == 0)
        {
            for (ll i=0; i<n-1; i+=2)
            {
                swap(a[i],a[i+1]);
            }
        }
        else 
        {
            if (r%2 == 0)
            {
                cout<<-1<<endl;
                continue;
            }
            for (ll i=0; i<(n-4); i+=2)
            {
                swap(a[i],a[i+1]);
            }
            ll temp = a[n-3];
            a[n-3] = a[n-2];
            a[n-2] = a[n-1];
            a[n-1] = temp;
        }
        for (ll i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<endl;    
    }
    return 0;
}