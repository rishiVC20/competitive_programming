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
        unordered_map<char,int>mpp;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];

        for (ll i=0; i<26; i++){
            mpp[i+'a']=0;
            // cout<<mpp[i]<<" ";
        }
        
        string ans = "";
        for (ll i=0; i<n; i++)
        {
            for (auto it:mpp)
            {
                if (it.second == arr[i])
                {
                    ans += it.first;
                    // it.second = it.second+1;
                    mpp[it.first]++;
                    break;
                }
            }
        }
        cout<<ans<<endl;        
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1927/B