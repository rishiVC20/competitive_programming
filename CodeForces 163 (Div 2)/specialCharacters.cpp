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
        if (n%2 ) {
            cout<<"NO"<<endl;
            continue;
        }
        if (n==0){
            cout<<"YES"<<endl;
            cout<<"AB"<<endl;
            continue;
        }
        string l;
        char p = 'A';
        while (n>0){
            l.push_back(p);
            l.push_back(p);
            p++;
            n -= 2;
        }
        cout<<"YES"<<endl;
        cout<<l<<endl;

    }
    return 0;
}