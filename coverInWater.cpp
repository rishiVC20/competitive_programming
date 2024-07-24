// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll curr=0, total = 0;
        ll maxi = INT_MIN;
        for (ll i=0; i<n; i++)
        {
            if (s[i]=='.')
            {
                curr++;
                total++;
            }
            else{
                maxi = max(maxi,curr);
                curr=0;
            }
            maxi = max(maxi,curr);
        }
        if (maxi>=3)
            cout<<2<<endl;
        else
            cout<<total<<endl;    
    }
    return 0;
}