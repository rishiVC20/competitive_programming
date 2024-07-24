// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        for (ll i=2; i<n; i++){
            ll a = i;
            ll b = (n-a-1);
            ll c = __gcd(a,b);
            if (a+b+c == n){
                cout<<a<<" "<<b<<" "<<c;
                break;
            }
            
        }
        cout<<endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1617/B