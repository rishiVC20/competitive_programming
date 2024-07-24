// #include<bits/stdc++.h>
// using namespace std;
// const int P=1e9+7;
// #define ll long long
// int main()
// {
//     int t,n;
//     cin>>t;
//     while(t--)
//     {
//         cin>>n;
//         if(n==1)
//         {
//             cout<<"8"<<endl;
//         }
//         else
//         {
//             ll t = (ll)(72 * pow(8, n - 2));
//             ll s = t%P;
//             cout<<s<<endl;
//         }
// }
// }



// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// //  const int P=1e9+7;
// ll P=1e9+7;
// int main()
// {
//     ll t,n;
//     cin>>t;
//     while(t--)
//     {
//             cin>>n;
//             ll s = 1;
//             //ll t = (ll)((8 * pow(9, n - 1)))%P;
//             for(int i=0;i<n-1;i++) {
//                 s = (s*9)%P; 
//             }
             
//              cout<<(s*8)%P<<endl;

//             //cout<<t<<endl;
//     }
// }


#include<bits/stdc++.h>
using namespace std;

#define lli long long
 lli P=1e9+7;
 
lli power(lli base, lli exponent, lli modulus) {
    lli result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
    lli t,n;
    cin>>t;
    while(t--)
    {
            cin>>n;
            lli s=1;
            //ll t = (ll)((8 * pow(9, n - 1)))%P;
           /* for(int i=0;i<n-1;i++) {
                s = (s*9)%P; 
            }*/
            cout<<(8*power(9, n-1, P))%P<<endl;
            //cout<<t<<endl;
    }
}