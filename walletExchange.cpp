// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        if (abs(a-b) % 2)
            cout<<"Alice"<<endl;       
        else
            cout<<"Bob"<<endl;
    }
    return 0;
}