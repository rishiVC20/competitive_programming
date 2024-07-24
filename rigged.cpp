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
        vector<ll>s(n);
        vector<ll>e(n);
        for (ll i=0; i<n; i++)
        {
            cin>>s[i];
            cin>>e[i];
        }
        // bool p = true;
        ll w;
        ll ans;
        bool flag = true;
        // if (s[0]==1)
        // {
            w = s[0];
            ans = w*e[0];
            // bool flag = true;
            for (ll i=1; i<n; i++)
            {
                if (s[i]>=w && e[i]*w >= ans)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout<<w<<endl;
            else
                cout<<-1<<endl;   
        //     continue;   
        // }
        // w = s[0];
        // ans = w*e[0];
        // for (ll i=1; i<n; i++)
        // {
        //     if (s[i]>w && e[i]*w >= ans){
        //         flag = false;
        //         break;
        //     }
        // }
        // if (flag)
        // {
        //     cout<<w<<endl;
        // }
        // else{
        //     cout<<-1<<endl;
        // }
    }
    return 0;
    
}
https://codeforces.com/contest/1879/problem/A