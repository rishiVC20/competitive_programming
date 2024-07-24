//n m k
// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        // cout<<n<<" "<<m<<" "<<k<<endl;
        vector<pair<ll,ll>> arr(n);
        // pair<ll,ll>arr[n];
        for (ll i=0; i<n; i++)
        {
            cin>>arr[i].second;
        }       
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
        // sort(arr.begin(), arr.end());
        ll p = k;
        ll i = 0;
        while (p > 0 )
        {
            if (p>=m){
                arr[i].first = m;
            }
            else{
                arr[i].first = p;
            }
            p -= m;
            i++;
        }
        // cout<<i<<" ";
        if (i<n)
        {
            for (ll i=i; i<n; i++)
            {
                arr[i].first = 0;
            }
        }
        // for (ll i=0; i<n; i++)
        //     cout<<arr[i].first<<" ";
        // cout<<endl;
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });   
        ll ticket = 0;
        ll sum = 0;
        // for (ll i=0; i<n; i++)
        //     cout<<arr[i].first<<" ";
        // cout<<endl;
        for (ll i=0; i<n; i++)
        {
            
            if (arr[i].first > 0)
            {
                sum += (arr[i].second + ticket)*arr[i].first;                
                ticket += arr[i].first;
                
            }
            // cout<<ticket<<" ";
        }
        cout<<sum<<endl;
        // cout<<endl;
    }
    return 0;
}