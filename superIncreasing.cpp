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
//         ll p = pow(2,k-1);
//         if (k > 31){
//             cout<<"NO"<<endl;
//             continue;
//         }
//         if (x >= p)
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
        char c;
        cin>>c;
        if (c=='c' || c=='o' ||c=='d' ||c=='e' ||c=='f' ||c=='o' ||c=='r' ||c=='c' ||c=='e' ||c=='s'  )
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
    }
    return 0;
}