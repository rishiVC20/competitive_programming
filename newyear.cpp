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
        if (n<2020)
            cout<<"NO";
        else{
            ll p = n%2020;
            ll q = n/2020;
            if (p <= q)
                cout<<"YES";
            else    
                cout<<"NO";    
        }    
        cout<<endl;
    }   
    return 0;
}

// https://codeforces.com/problemset/problem/1475/B