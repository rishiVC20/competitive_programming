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

        if (n%2 != 0)
        {
            cout<<4<<endl;
            cout<<1<<' '<<n-1<<endl;
            cout<<1<<' '<<n-1<<endl;
            cout<<n-1<<' '<<n<<endl;
            cout<<n-1<<' '<<n<<endl;
        }    
        else{
            cout<<2<<endl;
            cout<<1<<' '<<n<<endl;
            cout<<1<<' '<<n<<endl;
        }
    } 
    return 0;
}

// https://codeforces.com/problemset/problem/1869/A