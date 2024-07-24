// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>

const ll mod = 1e9 + 7;

ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent % 2 == 0)
        {
            base = (base * base) % mod;
            exponent = exponent / 2;
        }
        else
        {
            ans = (ans * base) % mod;
            exponent--;
        }
    }
    return ans;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vi arr;
        bool neg = true;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            arr.pb(x);
            if (arr[i] >= 0)
                neg = false;
        }
        if (neg)
        {
            sort(arr.begin(), arr.end(), greater<ll>());
            cout << arr[0] << endl;
            continue;
        }
        bool f = false;
        vi v;
        ll sum = 0;
        ll maxi = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            sum += arr[i];
            maxi = max(maxi,sum);
            // if (sum > maxi)
            //     maxi = sum;

            if (sum < 0 || abs(arr[i] % 2) == abs(arr[i+1] % 2))
                sum = 0;
        }
        // l
        // for (auto i:v)
        // {
        //     sum += i;
        //     maxi = max(maxi,sum);
        //     if (sum < 0)
        //         sum = 0;
        // }
        cout << maxi << endl;
    }
    return 0;
}