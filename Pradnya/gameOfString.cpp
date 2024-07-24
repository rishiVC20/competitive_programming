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
        string s;
        cin>>s;
        // cout<<s<<" ";
        vector<ll>v;
        for (ll i=0; i<26; i++){
            ll x;
            cin>>x;
            v.push_back(x);   
        }

        ll cnt = 0;
        vector<ll>p(26,0);
        for (ll i=0; i<n; i++)
        {
            // cout<<s[i]<<" ";
            // cout<<"hi"<<" ";
            if (s[i] == '?')
                cnt++;
            else {
                p[s[i]-'a']++;
            }    
        }
        // for (auto i:p)
        //     cout<<i<<" ";
        // cout<<endl;
        // for (auto i:v)
        //     cout<<i<<" ";    
        vector<ll>k(26,0);
        ll si = 0;
        for (ll i=0; i<p.size(); i++)
        {
            if (v[i]>p[i]){
                // k[i] = p[i] - v[i];
                si += v[i]-p[i];
            }
        }
        // cout<<si<<" ";
        // ll sum = accumulate(k.begin(),k.end(),0);
        // cout<<sum<<" ";
        if (si <= cnt)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
                
    }
    return 0;
}