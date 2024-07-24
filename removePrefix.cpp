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
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        vector<ll>store(n+1,0);
        for (ll i=0; i<n; i++){
            arr[store[i]]++;
        }    

        ll count = 0;
        for (ll i=0; i<n; i++){
            if (arr[store[i]] > 1){
                arr[store[i]]--;
                store.pop_back();
            }
        }
        cout<<n - store.size()<<endl;
    } 
    return 0;
}

// https://codeforces.com/contest/1714/problem/B