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
        {
            cin>>arr[i];
        }     
        sort(arr.begin(),arr.end());
        ll i = n/2;
        // cout<<i<<" ";
        if (n%2)
            i++;
        // cout<<i<<" ";    
        if (n==1){
            cout<<1<<endl;
            continue;
        }
        // for (int j=i-1; j<n; j++)
        // {
        //     cout<<arr[j]<<" ";
        // }
        // cout<<arr[i-1]<<endl;
        ll p = count(arr.begin()+(i-1), arr.end(),arr[i-1]);
        cout<<p<<endl;     
    }
    return 0;
}

/*
1
2
1
3
2
1
2
3

*/