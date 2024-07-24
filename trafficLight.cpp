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
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        s += s;
        // cout<<s<<" ";
        ll digit = INT_MIN; 
        ll ans = 0;
        for (ll i=s.size()-1; i>=0; i--)
        {
            if (s[i]=='g')
                digit = 0;
            if (s[i]==c)
                ans = max(ans,digit);
            digit++;      
            // cout<<digit<<" ";  
        }       
        cout<<ans<<endl;
    }
    return 0;
}