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
        if (s[0]=='a' || s[1]=='b' || s[2]=='c')
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
    }
    return 0;
}