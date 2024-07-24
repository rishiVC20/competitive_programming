// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a1,a2,a3;
        cin>>a1>>a2>>a3;
        if (a1 > a2)
        {
            ll temp = a2;
            a2 = a1;
            a1 = temp;
        }
        if (a1 > a3)
        {
            ll temp = a3;
            a3 = a1;
            a1 = temp;
        }
        if (a1==a2 && a2==a3)
            cout<<"YES"<<endl;
        else if ((a2%a1==0 && a3%a1==0) && (a2/a1-1+a3/a1-1 <= 3))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;        
    }
    
    return 0;
}

// https://codeforces.com/contest/1881/problem/B