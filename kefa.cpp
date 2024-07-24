// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll n;
    cin>>n;
    ll arr[n];
    for (ll i=0; i<n ;i++){
        cin>>arr[i];
    }   
    if (n==1)
        cout<<1<<endl;
    else{    
        ll curr=1;
        ll maxi = 1;
        for (ll i=1; i<n; i++){
            if (arr[i] >= arr[i-1]){
                curr++;
                maxi=max(maxi,curr);
            }
            else    
                curr = 1;
        }

        cout<<maxi<<endl;
    }
    return 0;
}