// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b,l;
        cin>>a>>b>>l;
        set<ll>s;
        while (true)
        {
            ll x = l;
            while (true)
            {
                s.insert(x);
                if (x%b != 0)
                    break;
                x /= b;    
            }
            if (l%a != 0)
                break;
            l /= a;    
        }
        cout<<s.size()<<endl;
    }
    return 0;
}

// https://codeforces.com/contest/1933/problem/C