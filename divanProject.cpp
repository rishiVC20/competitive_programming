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
        pair<ll,ll>arr[n];
        vector<ll>k(n);
        for (ll i=0; i<n; i++)
            arr[i].first = i;
        for (ll i=0; i<n; i++){
            cin>>arr[i].second;
            k[i] = arr[i].second;
        }
        sort (arr,arr+n, [&](pair<ll,ll>x,pair<ll,ll>y){
            return x.second < y.second;
        });
        ll p = 1;
        ll l = -1;
        for (ll i=n-1; i>=0; i--){
            if (i%2){
                arr[i].second = p;
                p++;
            }
            else{
                arr[i].second = l;
                l--;
            }
        }           
        sort(arr,arr+n, [&](pair<ll,ll>x,pair<ll,ll>y){
            return x.first < y.first;
        });
        ll sum = 0;
        for (ll i=0; i<n; i++)
        {
            sum += 2*(abs(arr[i].second))*k[i];
        }
        cout<<sum<<endl;
        cout<<0<<" ";
        for (ll i=0; i<n; i++){
            cout<<arr[i].second<<" ";
        }    
        cout<<endl;
    }
    return 0;
}