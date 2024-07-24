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
        string s;
        cin >> s;
        ll cn = 0;
        // set<string>store;
        vi arr(26, 0);
        for (ll i = 0; i < n; i++)
        {
            //     string str = s.substr(i);
            //     // cout<<str<<" ";
            //     if (str[0]==str[1]){
            //         cn++;
            //         // string k = str.substr(i+1);
            //         // store.insert(k);
            //         // continue;
            //     }
            //     else{
            //         // string k1 = str.substr(1);
            //         // string k2 = str[0]+str.substr(2);
            //         // store.insert(k1);
            //         // store.insert(k2);
            //         cn+=2;
            //         if (s[0]==s[2])
            //             cn++;
            //         else
            //             cn+=2;
            // }

            // if (str[0]!=str[2]){
            //     string k1 = str.substr(i+2);
            //     cn+=2;
            // }
            // else
            //     cn+=1;
            ll c = s[i] - 'a';
            if (!arr[c])
            {
                cn += n - i;
                arr[c]++;
            }
        }
        cout << cn << endl;
    }
    return 0;
}