// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         string s,t;
//         cin>>s>>t;
//         vector<ll>a(t.size());
//         for (ll i=0; i<t.size(); i++)
//         {
//             ll occurence = s.find_last_of(t[i]);
//             cout<<occurence<<" ";
//             a[i] = occurence;
//         }
//         vector<ll>b = a;
//         sort(b.begin(),b.end());
//         bool flag = true;
//         for (ll i=0; i<a.size(); i++)
//         {
//             if (a[i] != b[i])
//             {
//                 flag = false;
//                 break;;
//             }
//         }
//         if (flag)
//             cout<<"YES"<<endl;
//         else
//             cout<<"NO"<<endl;
//     }
//     return 0;
// }

// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll nthoccurrence(string &s, char &ch, ll &p)
{
    ll count = 0;
    for (ll i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ch)
        {
            // cout<<s[i]<<" ";
            count++;
            if (count == p)
                return i;
        }
    }
    return -1;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> s >> t;
        // cout<<s<<" "<<s.size()<<" ";
        // cout<<t<<" "<<t.size()<<" ";
        vector<ll> store(30, 0);
        // for (ll i=0; i<store.size(); i++)
        //     cout<<store[i]<<" ";
        for (ll i = 0; i < t.size(); i++)
        {
            // cout<<t[i]<<" ";
            store[t[i] - 'A']++;
            // cout<<store[t[i]-'A']<<" ";
        }
        // for (ll i=0; i<t.size(); i++)
        //     cout<<store[t[i]]<<" ";
        vector<ll> v;
        bool flag = true;
        for (ll i = 0; i < t.size(); i++)
        {
            ll p = store[t[i] - 'A'];
            // cout<<p<<" ";
            store[t[i] - 'A']--;
            ll occ = nthoccurrence(s, t[i], p);
            if (occ == -1)
            {
                flag = false;
                break;
            }
            v.push_back(occ);
        }
        if (!flag)
        {
            cout << "NO" << endl;
            continue;
        }
        vector<ll> p = v;
        // for (ll i=0; i<p.size(); i++)
        //     cout<<p[i]<<" ";
        sort(p.begin(), p.end());

        for (ll i = 0; i < v.size(); i++)
        {
            if (p[i] != v[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// https://codeforces.com/problemset/problem/1666/D
/*
YES
YES
NO
NO
YES
NO
YES
YES
NO
NO
*/