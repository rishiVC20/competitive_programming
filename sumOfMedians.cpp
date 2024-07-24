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
        vector<ll>a(n*k);
        for (ll i=0; i<n*k; i++)
            cin>>a[i];
        // for (ll i=0; i<n*k; i++)
        //     cout<<a[i]<<" ";    
        ll p = n/2;
        
        if (n%2)
            p += 1;
            // cout<<p<<" ";
        ll sum = 0;    
        for (ll i=0; i<n*k; i++)
        {
            cout<<p<<" ";
            if (i == p-1){
                sum += a[i];
                p += n;
            }
        }    
        cout<<sum<<endl;

    }
    return 0;
}

/*
165
108
145
234
11
3
*/