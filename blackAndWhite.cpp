// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll checkWhite(string s)
{
    ll count = 0;
    for (ll i=0; i<s.size(); i++)
        if (s[i] == 'W')
            count++;
    return count;        
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        // cout<<n-k<<" ";
        string s;
        cin>>s;
        ll mini = INT_MAX;
        vector<ll>arr(n+1);
        // for (ll i=0; i<=n-k; i++)
        // {
        //     // cout<<"hi"<<" ";
        //     string p = s.substr(i,k);
        //     ll cnt = checkWhite(p);
        //     cout<<cnt<<" ";
        //     mini = min(mini, cnt);
        // }
        arr[0] = 0;
        for (ll i=1; i<=n; i++)
        {
            // cout<<"hi"<<" ";
            arr[i] = arr[i-1] + (s[i-1]=='W');
            // cout<<arr[i]<<" ";
        }
        for (ll i=k; i<=n; i++)
        {
            mini = min(mini,arr[i]-arr[i-k]);
        }
        cout<<mini<<endl;
    }
    return 0;
}