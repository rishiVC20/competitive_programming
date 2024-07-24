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
        ll n, k;
        cin >> n >> k;
        vi a;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.pb(x);
        }
        vi v;
        ll curr = 1;
        bool f = true;
        sort(a.begin(), a.end());
        for (ll i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                curr++;
            }
            else
            {
                // curr = 1;
                v.pb(curr);
                curr = 1;
                if (i == n - 1){
                    v.pb(1);
                    f = false;
                }
            }
        }
        if (f)
            v.pb(curr);
        // for (auto o:v)
        //     cout<<o<<" ";    
        sort(v.begin(), v.end());
        ll m = v.size();
        // cout << m << " ";
        if (v[m-1] < k || n<k){
            cout<<n<<endl;
            continue;
        }

        // cout << "j"<< " ";
        ll cn = 1;
        ll c=m-1;
        ll w;
        vi u = v;
        for (ll i = m - 2; i >= 0; i--)
        {
            // v[i] += (k - 1);
            if (v[i] < k-1)
            {
                c = i;
                break;
            }
            w = i;
            // v[i]-=k;
        }
        if (w==0){
            cout<<k-1<<endl;
            continue;
        }
        else{
            cout<<k-1<<endl;
        }
        // ll sum = 0;
        // for (ll i = 0; i <= c; i++)
        //     sum ++;
        // cout << sum << endl;
    }
    return 0;
}