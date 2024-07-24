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
        bool flag = true;
        ll x = 0, y = 0;
        for (ll i=0; i<n; i++)
        {
            if (s[i]=='U')
                y++;
            if (s[i]=='D')
                y--;
            if (s[i]=='R')
                x++;
            if (s[i]=='L')
                x--;    
            if (x==1 && y==1){
                cout<<"YES"<<endl;
                flag = false;
                break;
            }             
        }    
        if (!flag)
            continue;   
        cout<<"NO"<<endl;
    }
    return 0;
}