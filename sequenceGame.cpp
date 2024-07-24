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
        vector<ll>ans;
        ans.push_back(arr[0]);
        if (n==1){
            cout<<1<<endl;
            cout<<ans[0]<<endl;
            continue;
        }
        for (ll i=1; i<n; i++)
        {
            if (arr[i]-arr[i-1] >= 0)
                ans.push_back(arr[i]);
            else if (arr[i]-arr[i-1] < 0)
            {
                ans.push_back(1);
                ans.push_back(arr[i]);
            }    
        }    
        cout<<ans.size()<<endl;
        for (ll i=0; i<ans.size(); i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

// https://codeforces.com/problemset/problem/1862/B