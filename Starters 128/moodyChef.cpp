// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,l,r;
        cin>>n>>l>>r;
        ll mini = 0;       
        ll maxi = 0;
        ll k = 0;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            if (x >=l && x<=r){
                k++;
            }
            else
                k--;
            maxi = max(maxi,k);
            mini = min(mini,k);    
        }       
        cout<<maxi<<" "<<mini<<endl;
    }
    return 0;
}