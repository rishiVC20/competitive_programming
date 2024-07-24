// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll x,y,n;
        cin>>x>>y>>n;
        if (n<x){
            cout<<0<<endl;
            continue;
        }
        while (n)
        {
            if (n%x==y){
                cout<<n<<endl;
                break;
            }
            n--;
        }       
        // cout<<n<<endl;
    }
    return 0;
}