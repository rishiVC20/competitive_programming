// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll n,m;
    cin>>n>>m;
    int arr[m];
    for (int i=0; i<m; i++){
        cin>>arr[i];
    }
    sort(arr,arr+m);
    ll i=0; 
    ll j=n-1;
    ll mini=INT_MAX;
    do{
        ll ans=arr[j]-arr[i];
        mini=min(mini,ans);
        i++;
        j++;
    }
    while (j<=m-1);
    cout<<mini<<endl;
    return 0;
}

// https://codeforces.com/problemset/problem/337/A