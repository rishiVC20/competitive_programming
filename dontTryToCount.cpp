// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;
        ll cnt = 0;
        ll i=0;
        while (i < 6)
        {
            size_t found = x.find(s);
            if (found != std::string::npos)
                break;
            x = x + x;    
            cnt++;  
            if (i==5)
                cnt = -1; 
            i++; 
        }
        cout<<cnt<<endl;
    }   
    return 0;
}

// https://codeforces.com/problemset/problem/1881/A