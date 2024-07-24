// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         vector<string>arr(10);
//         // ll p = 10;
//         for (ll i=0; i<10; i++){
//             cin>>arr[i];
//             // cout<<arr[i]<<" ";
//         }
//         ll ans = 0;    
//         ll count = 0;
//         ll cnt = 0;
//         for (ll i=0; i<arr.size(); i++)
//         {
//             // cout<<"hi"<<" ";
//             cnt++;
//             if (i==0 || i==9){
//                 // cout<<"hi"<<" ";
//                 // count = 0;
//                 for (auto j:arr[i])
//                 {
//                     // count++;
//                     if (j=='X'){
//                         ans++;
//                         // cout<<count<<" ";
//                     }
//                 }
//                 // cout<<ans<<" ";
//             }
//             else if (i==1 || i==8)
//             {
//                 count = 0;
//                 for (auto j:arr[i])
//                 {
//                     count++;
//                     if ((count==1 && j=='X')|| (count==10 && j=='X'))
//                         ans++;
//                     else if (j=='X')
//                         ans += 2;    
//                 }
//                 // cout<<ans<<" ";
//             }
//             else if (i==2 || i==7)
//             {
//                 count = 0;
//                 for (auto j:arr[i])
//                 {
//                     count++;
//                     // cout<<count<<" ";
//                     if ((count==1 && j=='X')|| (count==10 && j=='X')){
//                         ans++;
//                         // cout<<ans<<" ";
//                     }
//                     else if ((count==2 && j=='X')|| (count==9 && j=='X')){
//                         ans+=2;
//                         // cout<<ans<<" ";
//                     }
//                     else if (j=='X'){
//                         ans+=3;     
//                         // cout<<ans<<" ";
//                     }   
//                 }
//                 // cout<<ans<<" ";
//             }
//             else if (i==3 || i==6)
//             {
//                 count = 0;
//                 for (auto j:arr[i])
//                 {
//                     count++;
//                     if ((count==1 && j=='X')|| (count==10 && j=='X'))
//                         ans++;
//                     else if ((count==2 && j=='X')|| (count==9 && j=='X'))
//                         ans+=2;
//                     else if ((count==3 && j=='X')|| (count==8 && j=='X'))
//                         ans+=3;
//                     else if (j=='X')
//                         ans += 4;            
//                 }
//             }
//             else if (i==4 || i==5)
//             {
//                 count = 0;
//                 for (auto j:arr[i])
//                 {
//                     count++;
//                     if ((count==1 && j=='X')|| (count==10 && j=='X'))
//                         ans++;
//                     else if ((count==2 && j=='X')|| (count==9 && j=='X'))
//                         ans+=2;
//                     else if ((count==3 && j=='X')|| (count==8 && j=='X'))
//                         ans+=3;
//                     else if ((count==4 && j=='X')|| (count==7 && j=='X'))
//                         ans+=4;
//                     else if (j=='X')
//                         ans+=5;               
//                 }
//             }
//         }    
//         // cout<<endl;
//         cout<<ans<<endl;
//     }
//     return 0;
// }

// // https://codeforces.com/problemset/problem/1873/C

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll score[10][10]= {
    {1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1}
};

void solve()
{
    ll ans = 0;
    for (ll i=0; i<10; i++)
    {
        for (ll j=0; j<10; j++)
        {
            char c;
            cin>>c;
            if (c=='X')
                ans += score[i][j];
        }
    }
    cout<<ans<<endl;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1873/C