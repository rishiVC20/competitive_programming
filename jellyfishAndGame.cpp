// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll>a(n);
        vector<ll>b(m);
        ll mina = INT_MAX, minb = INT_MAX;
        ll suma = 0;
        ll maxa = 1, maxb = 1;
        for (ll i=0; i<n; i++){
            cin>>a[i];
            // suma += a[i];
            // mina = min(mina,a[i]);
            // maxa = max(maxa,a[i]);
        }
        for (ll i=0; i<m; i++){
            cin>>b[i];
            // sumb += b[i];
            // minb = min(minb,b[i]);
            // maxb = max(maxb,b[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        mina = a[0], maxa = a[n-1];
        minb = b[0], maxb = b[m-1];
        // cout<<mina<<" "<<maxa<<" "<<minb<<" "<<maxb<<" ";
        // if (k%2){
            if (mina < maxb)
            {
                swap(a[0],b[m-1]);
            }
            
        // }
        // for (ll i=0; i<n; i++)
        //     cout<<a[i]<<" ";
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        maxa = a[n-1], minb = b[0];
        if (k%2==0)
        {
            if (maxa > minb)
                swap(a[n-1],b[0]);
            // if (minb < maxa && maxa > maxb)
            //     suma = suma-maxa+minb;
            // else{
            //     suma = suma-
            // }    
        }
        for (ll i=0; i<n; i++)
            suma += a[i];
        cout<<suma<<endl;    
    }
    return 0;
}



// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         ll n,m,k;
//         cin>>n>>m>>k;
//         vector<ll>a(n);
//         vector<ll>b(m);
//         for (ll i=0; i<n; i++) cin>>a[i];
//         for (ll i=0; i<m; i++) cin>>b[i];
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
//         if (a[0] < b[m-1])
//             swap(a[0],b[m-1]);
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
//         if (k%2==0)
//         {
//             if (b[0] < a[n-1])
//                 swap(b[0],a[n-1]);
//         }    
//         ll sum = 0;
//         for (ll i=0; i<n; i++)
//             sum += a[i];
//         cout<<sum<<endl;    
//     }
//     return 0;
// }


// https://codeforces.com/contest/1875/problem/B