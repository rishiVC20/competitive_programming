// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(string a, string b)
{
    // string a, b;
    ll i = 0;
    ll n = a.size();
    // while (i < n)
    // {
    //     if (x[i] > y[i])
    //     {
    //         a = x;
    //         b = y;
    //         break;
    //     }
    //     else if (x[i] < y[i])
    //     {
    //         a = y;
    //         b = x;
    //         break;
    //     }
    //     i++;
    // }
    if (a<b)
        swap(a,b);
    // i = 0;
    bool flag = false;
    for (ll i=0; i<n; i++)
    {
        if (a[i] != b[i])
        {
            if (flag)
            {
                if (a[i] > b[i])
                    swap(a[i], b[i]);
                // flag = false;
            }
            else
            {
                if (a[i] != b[i])
                    flag = true;
                    
            }
            // flag = false;
        }
        // i++;
    }
    // ll p = stoi(a);
    // ll q = stoi(b);
    cout << a << endl;
    cout << b << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;
        solve(x, y);
        // cout<<s<<endl;
    }
    return 0;
}