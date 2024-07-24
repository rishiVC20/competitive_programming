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
        for (ll i=0; i<n-1; i++){
            ll x; cin>>x;
            sum += x;
        }
        cout<<-1*sum<<endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1877/A