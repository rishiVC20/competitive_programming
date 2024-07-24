// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        vector<int>arr(n);
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }       
        sort(arr.begin(),arr.end());
        ll maxi = 0;
        for (int i=1; i<n; i++){
            maxi += (arr[i]-arr[i-1]);
        }
        cout<<maxi<<endl;
    }
    return 0;
}