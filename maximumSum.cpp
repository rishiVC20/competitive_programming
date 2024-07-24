// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> arr;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        while (k != 0)
        {
            ll p1 = arr[0]+arr[1];
            ll p2 = arr[arr.size()-1];
            if (p1<p2){
                arr.erase(0);
                arr.erase(1);
            }
            else{
                arr.erase(arr.size()-1);
            }
        }
        ll sum = accumulate(arr.begin(),arr.end(),0);
        cout<<sum<<endl;
    }
    return 0;
}