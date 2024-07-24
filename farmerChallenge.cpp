// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        if (n>k && k>1){
            cout<<-1<<endl;
            continue;
        }       
        if (k==1)
        {
            for (ll i=1; i<=n; i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else if (n==k){
            while (n){
                cout<<1<<" ";
                n--;
            }
            cout<<endl;
        }
        // cout<<endl;
    }
    return 0;
}