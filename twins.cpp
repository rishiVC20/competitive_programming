// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll n;
    cin>>n;
    // vector<int>arr(n);
    ll arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    ll sum = 0;
    // sort(arr.begin(),arr.end());
    sort(arr, arr+n);
    for (int i=0; i<n; i++){
        sum += arr[i];
    }
    ll count=0;
    int ans;
    ll p=0;
    for (int j=n-1; j>=0; j--){
        count = count+ arr[j];
        sum = sum - arr[j];
        p++;
        if (count>sum){
            // ans=n-j;
            break;
        }
    }
    cout<<p<<endl;
    return 0;
}

// https://codeforces.com/problemset/problem/160/A