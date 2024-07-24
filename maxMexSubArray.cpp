// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll countMex(vector<ll> arr)
{
    // sort(arr.begin(),arr.end());
    for (ll i=0; i<=arr.size(); i++)
    {
        ll k = count(arr.begin(),arr.end(),i);
        // cout<<k<<" ";
        if (k==0)
            return i;
    }
    return arr.size()+1;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        ll mex = countMex(arr); 
        // cout<<mex<<" ";
        if (mex==0){
            cout<<1<<endl;
            continue;
        }
        ll count = 0;
        ll maxi = 1;
        set<ll>st;
        bool f = true;
        for (ll i=0; i<n; i++)
        {
            st.insert(arr[i]);
            // cout<<arr[i]<<" ";
            if (arr[i]<mex){
                count++;
            }
            // else if (arr[i] > mex){
            //     count++;
            //     f = false;
            // }
            else{
                count = 0;
            }
            
            maxi = max(maxi,count);
            if (!f  )
                break;
            if (st.size()==mex)
                break;
        }          
        cout<<maxi<<endl;
    }
    return 0;
}