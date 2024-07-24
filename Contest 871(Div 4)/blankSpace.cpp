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
        ll curr = 0;
        ll maxi = INT_MIN;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            if (x==0){
                curr++;   
            }
            else{
                curr = 0;
            }
            maxi = max(maxi,curr);
        }       
        cout<<maxi<<endl;
    }
    return 0;
}