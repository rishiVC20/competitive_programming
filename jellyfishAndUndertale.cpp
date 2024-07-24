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
        ll a, b, n;
        cin >> a >> b >> n;
        ll mini = b, sum = b, count = 0;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (ll i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum <= a)
            {
                count++;
                mini = sum;
            }
            else
            {
                break;
            }
        }
        ll sec = 0;
        sec += (mini - 1);
        ll p;
        for (ll i = count; i < n; i++)
        {
            ll ans = 1 + arr[i];
            p = min(a, ans);
            sec += (p - 1);
        }
        cout << sec + 1 << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1875/A