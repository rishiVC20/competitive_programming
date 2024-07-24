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
//         if (n <= 9)
//         {
//             cout<<n<<endl;
//         }       
//         else if (n>=10 && n<100)
//         {
//             cout<<9+(n/10)<<endl;
//         }
//         else if(n>=100 && n<1000)
//         {
//             cout<<18+(n/100)<<endl;
//         }
//         else if (n>=1000 && n<10000)
//         {
//             cout<<27+(n/1000)<<endl;
//         }
//         else if (n>=10000 && n<100000)
//         {
//             cout<<36+(n/10000)<<endl;
//         }
//         else if (n>=100000 && n<1000000)
//         {
//             cout<<45+(n/100000)<<endl;  
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
        string s;
        cin>>s;
        cout<<(s.size()-1)*9 + s[0]-'0'<<endl;       
    }
    return 0;
}