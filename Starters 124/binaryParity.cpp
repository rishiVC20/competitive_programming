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
        ll p = __builtin_popcount(n);
        if (p%2)
            cout<<"ODD"<<endl;
        else
            cout<<"EVEN"<<endl;    
    }
    return 0;
}