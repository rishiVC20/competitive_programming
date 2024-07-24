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
        vector<ll>a(n);       
        vector<ll>b; 
        for (ll i=0; i<n; i++)
            cin>>a[i];
        ll count = 0;    
        for (ll i=0; i<n; i++)
        {
            if (a[i] != 0)
            {
                count++;
                while (i<n && a[i])
                    i++;
            }   
        }         
        // if (count > 0)
        //         b.push_back(count);
        // cout<<min(count,2)<<endl;
        if (count > 2)
            cout<<2<<endl;
        else
            cout<<count<<endl;    
    }
    return 0;
}