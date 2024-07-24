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
        string s;
        cin >> s;
        ll n = s.size();
        // s += s;
        bool f = false;
        ll maxi1 = 0;
        ll cur = 0;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                cur++;
            else
            {
                cur = 0;
            }
            if (s[i] == '0')
                f = true;
            maxi1 = max(cur, maxi1);
        }
        // cout<<maxi1<<" ";
        if (!f)
        {
            cout << n * n << endl;
            continue;
        }
        s = s + s;
        // cout<<s<<" ";
        ll maxi2 = 0;
        cur = 0;
        for (ll i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                cur++;
            else
                cur = 0;
            if (cur > n)
                break;
            maxi2 = max(maxi2, cur);
        }
        // cout << maxi2 << " " ;
        // if (maxi1 == 0)
        // {
        //     cout << 0 << endl;
        //     continue;
        // }
        // if (maxi1 == 1 && maxi2 == 1)
        // {
        //     cout << 1 << endl;
        //     continue;
        // }
        // if (maxi1==1 && maxi2==2){
        //     cout<<2<<endl;
        //     continue;
        // }
        // if (maxi1 == 1 || maxi2 == 1)
        // {
        //     if (maxi2 != 1)
        //         cout << maxi2 << endl;
        //     else if (maxi1 != 1)
        //         cout << maxi1 << endl;
        //     else
        //         cout << 1 << endl;
        //     continue;
        // }
        ll u = (maxi2 + 1) / 2;
        // cout<<u<<" ";
        // cout << ((maxi2 + 1) / 2)*((maxi2 + 1) / 2)<< endl;
        cout<<((maxi2+1)*(maxi2+1))/4<<endl;
    }
    return 0;
}