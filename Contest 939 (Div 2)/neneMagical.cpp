// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// ll calculateSum (ll &n)
// {
//     // return (n*(n+1)*(n-1))/2 + n*n;
//     return (n*(n+1))/2 + (n*(n+1)/2 - 1)*n;
// }
// void printArray(ll &n)
// {
//     for (ll i=1; i<=n; i++)
//         cout<<i<<" ";
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n;
//         cin>>n;
//         ll sum = calculateSum(n);  
//         cout<<sum<<" ";
//         cout<<n+1<<endl;
//         for (ll i=0; i<n; i++)
//         {
//             cout<<1<<" ";
//             cout<<(i+1)<<" ";
//             printArray(n);
//             cout<<endl;
//         }
//         // for (ll i=0; i<n-1; i++)
//         // {
//             cout<<2<<" ";
//             cout<<1<<" ";
//             printArray(n);
//             cout<<endl;
//         // }
//     }
//     return 0;
// }



// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
void printArray(ll &n)
{
    for (ll i=1; i<=n; i++)
        cout<<i<<" ";
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll sum = 0;
        ll p = 1;
        for (ll i=1; i<=n; i++){
            sum += i*p;       
            p += 2;
        }
        cout<<sum<<" "<<2*n<<endl;
        ll k1 = n; 
        ll k2 = n;
        for (ll i=0; i<n; i++)
        {
            // if (i%2==0)
            // {
                cout<<1<<" "<<k1<<" ";
                printArray(n);
                cout<<endl;
                k1--;
            // }
            // else{
                cout<<2<<" "<<k2<<" ";
                printArray(n);
                cout<<endl;
                k2--;
            // }
        }
        // cout<<endl;
    }
    return 0;
}