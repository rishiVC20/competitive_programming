// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
/*void solve()
{
    ll n,k;
    cin>>n>>k;
    ll count = 0;
    vector<ll>arr(n);
    for (ll i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    bool flag = true;
    for (ll i=0; i<n-1; i++)
    {
        if (arr[i] != arr[i+1])
            flag = false;
    }
    if (flag){
        cout<<0<<endl;
        continue;
    }
    for (ll i=1; i<n; i++)
    {
        if (arr[i]-arr[i-1] > k)
            count++;
    }
    cout<<(count+1)<<endl;
}*/


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
         ll n,k;
        cin>>n>>k;
        ll count = 0;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        
        // bool flag = true;
        // for (ll i=1; i<n-1; i++)
        // {
        //     if ((arr[i]-arr[i-1]) != (arr[i+1]-arr[i]))
        //         flag = false;
        // }
        // if (flag){
        //     cout<<0<<endl;
        //     continue;
        // }
        // if (n==3)
        // {
        //     if (arr[1]-arr[0]>k) 
        //         count++;
        //     if (arr[2]-arr[1]>k)
        //         count++;    
        // }
        // if (count==1)
        // {
        //     cout<<1<<endl;
        //     continue;
        // }
        // if (count==2)
        // {
        //     cout<<2<<endl;
        //     continue;
        // }
        // if (n==2)
        // {
        //     if (arr[1]-arr[0]<=k)
        //         cout<<0<<endl;
        //     else    
        //         cout<<1<<endl;
        //     continue;        
        // }
        count = 1;
        ll maxi = 1;
        for (ll i=1; i<n; i++)
        {
            if (arr[i]-arr[i-1] <= k){
                count++;
                // maxi = max(maxi,count);  
            }
            else{
                count = 1;
            }
            maxi = max(maxi,count);
        }
        cout<<n-maxi<<endl;
    }
    return 0;
}

/*
2
0
5
0
3
1
4

*/