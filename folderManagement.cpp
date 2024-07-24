// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,x;
        cin>>n>>x;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        sort(arr.begin(),arr.end());
        ll count = 0;
        for (ll i=0; i<n; i++)
        {
            if (arr[i] <= x){
                x -= arr[i];
                count++;
            }
            else{
                break;
            }    
        }    
        cout<<count<<endl;
    }
    return 0;
}