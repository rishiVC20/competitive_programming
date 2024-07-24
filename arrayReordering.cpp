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
        vector<ll>ans(n);
        for (ll i=0; i<n; i++)
            cin>>ans[i];
        // sort(ans.begin(),ans.end(),greater<int>());
        sort(ans.begin(),ans.end(),[](int x,int y){
            return x%2 < y%2;
        });
        ll count1 = 0;
        for (ll i=0; i<n-1; i++){
            for (ll j=i+1; j<n; j++){
                ll a = ans[i];
                ll b = 2*ans[j];
                if (__gcd(a,b) > 1)
                    count1++;
            }
        }    
        // sort(ans.begin(),ans.end());
        // ll count2 = 0;
        // for (ll i=0; i<n-1; i++){
        //     for (ll j=i+1; j<n; j++){
        //         ll a = ans[i];
        //         ll b = 2*ans[j];
        //         if (__gcd(a,b) > 1)
        //             count2++;
        //     }
        // }
        // cout<<max(count1,count2)<<endl;
        cout<<count1<<endl;
    }   
    return 0;
}

// https://codeforces.com/problemset/problem/1535/B