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
        ll count = 0;
        for (ll i=0; i<n; i++)
        {
            if (s[i]=='+')
                count++;
            else
                count--;    
        }   
        cout<<abs(count)<<endl;
    }
    return 0;
}