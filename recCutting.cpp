// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         /* code */
//         ll a,b;
//         cin>>a>>b;
//         bool flag = false;
//         if (a>b){
//             int temp = b;
//             b = a;
//             a = temp;
//         }
//         for (int i=2; i<b; i++){
//             if (b%i==a){
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag)
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
    while (t--){
        ll a,b;
        cin>>a>>b;
        if (a>b){
            swap(a,b);
        }

        if ((a%2==1)&&(b%2==1) || (a%2==1)&&(b==2*a))
            cout<<"NO"<<endl;
        else    
            cout<<"YES"<<endl;    
    }
    return 0;
}
// https://codeforces.com/contest/1928/problem/A