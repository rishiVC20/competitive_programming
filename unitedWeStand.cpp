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
        for (ll i=0; i<n; i++)
            cin>>a[i];
        vector<ll>b;           
        vector<ll>c;
        sort(a.begin(),a.end());
        ll maxi = *std::max_element(a.begin(),a.end());
        for (ll i=0; i<n; i++)
        {
            if (a[i] != maxi)
                b.push_back(a[i]);
            else
                c.push_back(a[i]);    
        }           
        if (b.size() < 1 || c.size() < 1)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<b.size()<<" "<<c.size()<<endl;
        for (ll i=0; i<b.size(); i++)
            cout<<b[i]<<" ";
        cout<<endl;
        for (ll i=0; i<c.size(); i++)
            cout<<c[i]<<" ";
        cout<<endl;    
    }
    return 0;
}