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
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            sum += abs(x);
        }
        cout<<sum<<endl;
    }
    return 0;
}

// https://codeforces.com/contest/1933/problem/A