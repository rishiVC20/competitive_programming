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
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        ll i1 = 0;
        ll i2 = 0;
        while (i1 < n && arr[i1] == arr[0])
            i1++;

        while (i2 < n && arr[n - i2 - 1] == arr[n - 1])
            i2++;

        ll res = n;
        if (arr[0] == arr[n - 1])
        {
            res = res - (i1 + i2);
        }
        else
        {
            res = res - max(i1, i2);
        }
        // cout<<max(0,res)<<endl;
        // cout << max(0, res);
        if (res > 0)
            cout<< res;
        else    
            cout<< 0;    
        cout << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1931/C