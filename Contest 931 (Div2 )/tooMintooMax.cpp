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
        vector<ll>p(n);
        for (ll i=0; i<n; i++)
            cin>>p[i];
        sort(p.begin(),p.end());        
        ll i=0,j=(n-1),k=1,l=(n-2);   
        ll sum;
        sum = abs(p[i]-p[j]) + abs(p[j]-p[k]) + abs(p[k]-p[l]) + abs(p[l]-p[i]);
        cout<<sum<<endl; 
    }
    return 0;
}