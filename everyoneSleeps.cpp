// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n,h,m;
        cin>>n>>h>>m;
        vector<ll>store;
        ll ans1 = (h*60)+m;
        ll p=n;
        while(p--){
            ll h1,m1;
            cin>>h1>>m1;
            ll ans = (h1*60)+m1;
            store.push_back(ans);
        }
        ll mini = INT_MAX;
        for (ll i=0; i<n; i++){
            ll diff = store[i]-ans1;
            if (diff < 0){
                diff = (1440-ans1)+store[i];
            }
            mini = min(mini,diff);
        }
        cout<<mini/60<<" ";
        cout<<mini%60<<endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1714/A