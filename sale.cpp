// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll maxElement(vector<ll> &arr)
{
    ll maxi = 0;
    for (ll i=0; i<arr.size(); i++)
    {
        maxi = max(maxi,arr[i]);
    }
    return maxi;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll>arr;
        for (ll i=0; i<n; i++)
            cin>>arr[i];
            for (ll i=0; i<n; i++)
            cout<<arr[i]<<" ";
        //auto maxElement = std::max_element(arr.begin(),arr.end());
        ll maxi = maxElement(arr);
        cout<<maxi<<" ";
        ll cnt = count(arr.begin(),arr.end(),maxi);
        cout<<cnt<<" ";
        ll sum = 0;
        ll c = 0;
        for (ll i=0; i<n; i++)
        {
            cout<<"hi"<<" ";
            sum += arr[i];
            if (arr[i]==maxi)
                c++;
            if (arr[i]==maxi && c==cnt)  {
                sum += arr[i];
                
                break;
            }  
        }    
        cout<<sum<<endl;
    }   
    return 0;
}