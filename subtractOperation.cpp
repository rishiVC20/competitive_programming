// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>

const ll mod = 1e9 + 7;

ll mul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
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

bool check(vi a, ll i, ll p)
{
    for (ll j = 0; j <= i; j++)
        if (a[j] == p)
            return true;

    return false;
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
        set<int> st;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            a.pb(x);
            st.insert(x);
        }
        sort(a.begin(), a.end());
        // if (a[n-1]==a[n-2]){
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        ll j = 0;
        ll si = 0;
        vi kp;
        for (auto i : st)
        {
            kp.pb(i);
        }
        if (kp[0] < 0)
        {
            ll m = abs(kp[0]);
            for (ll i = 0; i < kp.size(); i++)
                kp[i] += m;
        }
        for (auto i : kp)
        {
            // kp.pb(i);
            // cout << i << " ";
        }
        bool f = false;
        // for (ll i=kp.size()-1; i>=0; i--)
        // {
        //     ll p = kp[i]-k;
        //     // cout<<i<<" ";
        //     if (check(kp,i-1,p)){
        //         f = true;
        //         break;
        //     }
        // }

        // for (ll i=0; i<kp.size(); i++)
        // {
        //     ll it = lower_bound(kp.begin(),kp.end(),kp[i]+k) - kp.begin();
        //     if (kp[it]-kp[i] == k)
        //     {
        //         f = true;
        //         break;
        //     }
        // }

        if (n==1){
            if (kp[0]==k)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            continue;        
        }
        ll i = 0, x = 1;
        while (x < kp.size() && i < kp.size())
        {
            if (kp[i] + k == kp[x])
            {
                f = true;
                break;
            }
            else if (kp[i] + k < kp[x])
            {
                i++;
            }
            else
            {
                x++;
            }
        }

        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        // cout<<endl;
    }
    return 0;
}