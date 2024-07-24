// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll att,per;
        cin>>att>>per;
        if (att < 50 ) 
            cout<<'Z'<<endl;
        else if (att>=50 && per<50)
            cout<<'F'<<endl;
        else    
            cout<<'A'<<endl;    
    }
    return 0;
}