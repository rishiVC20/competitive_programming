// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,c,d;
        cin>>n>>c>>d;
        vector<ll>k(n*n);
        ll mini = INT_MAX;
        for (ll i=0; i<n*n; i++){
            cin>>k[i];  
            mini = min(mini,k[i]);
        }
        vector<ll>arr;
        arr.push_back(mini);
        for (ll i=1; i<n; i++)
        {
            mini += d;
            arr.push_back(mini);
        }
        for (ll i=0; i<n; i++)
        {
            ll k = arr[i];
            for (ll j=1; j<n; j++)
            {
                k += c;
                arr.push_back(k);
            }
        }
        sort(arr.begin(),arr.end());
        sort(k.begin(),k.end());
        // if (arr == k)
        //     cout<<"YES"<<endl;
        // else    
        //     cout<<"NO"<<endl;    
        for (ll i=0; i<n*n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;   
        for (ll i=0; i<n*n; i++)
            cout<<k[i]<<" ";
        cout<<endl;  

    }
    return 0;
}