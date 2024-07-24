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
        if (n%3 != 0)
            cout<<"First"<<endl;
        else
            cout<<"Second"<<endl;    
    }
    
    return 0;
}