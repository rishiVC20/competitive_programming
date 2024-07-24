// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        string p = "codeforces";
        ll sum = 0;
        for (ll i=0; i<10; i++)
            if(s[i] != p[i])
                sum++;
        cout<<sum<<endl;                
    }
    return 0;
}