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
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        ll count = 0;
        for (ll i=0; i<n-1; i++){
            if (arr[i] < arr[i+1])  
                count++;
        }         
        if (count > 1)  
            cout<<count-1<<endl;
        else 
            cout<<0<<endl;       
    }
    return 0;
}