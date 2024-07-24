#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n,k;
        cin>>n>>k;
        for (int i=0; i<n; i++){
            for (char c='a'; c<'a'+k; c++)
                cout<<c;
        }
        cout<<endl;
    }
    return 0;
}

//https://codeforces.com/contest/1925/problem/A