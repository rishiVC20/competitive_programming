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
        vector<ll>arr1(n);
        vector<ll>arr2(n);
        for (ll i=0; i<n; i++){
            cin>>arr1[i];
            arr2[i] = arr1[i];
        }       
        sort(arr2.begin(),arr2.end());
        // for (ll i=0; i<n; i++)
        //     cout<<arr2[i]<<" ";
        // cout<<endl;    
        ll cnt = 0;
        for (ll i=0; i<n; i++){
            if (arr1[i] == arr2[i]){
                cnt++;    
                // cout<<"hi"<<" ";
            }
        }
        if (cnt != n){
            // cout<<"hi"<<" ";
            cout<<0<<endl;
            continue;
        }
        ll mini = INT_MAX;
        for (ll i=1; i<n; i++){
            mini = min(mini,arr1[i]-arr1[i-1]);
        }
        if (mini == 0){
            // cout<<"hi"<<" ";
            cout<<1<<endl;
        }
        // else if (mini == 2)
        //     cout<<2<<endl;
        // else if (mini%2 == 0){
        //     cout<<mini/2<<endl;
        // }
        else{
            cout<<mini/2+1<<endl;
        }
    }
    return 0;
}