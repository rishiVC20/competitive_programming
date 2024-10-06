// Rishikesh Chaudhari
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const ll mod = 1e9 + 7;

int main()
{
    ll n;
    cout << "Enter number of nodes: ";
    cin >> n;
    ll edj;
    cout << "Enter number of edges: ";
    cin >> edj;
    ll s;
    cout << "Enter source node: ";
    cin >> s;
    vector<vector<ll>> v(edj, vector<ll>(3, INT_MAX));
    for (ll i = 0; i < edj; i++)
    {
        cout << "Enter x,y,z: ";
        ll x, y, z;
        cin >> x >> y >> z;
        v[i][0] = x;
        v[i][1] = y;
        v[i][2] = z;
    }
    vector<ll> dis(n, INT_MAX);
    dis[s] = 0;
    for (ll i = 0; i < edj - 1; i++)
    {
        for (auto j : v)
        {
            ll x = j[0];
            ll y = j[1];
            ll z = j[2];
            if (dis[x] + z < dis[y])
            {
                dis[y] = dis[x] + z;
            }
        }
    }
    cout << "Corresponding distance array: ";
    for (auto i : dis)
        cout << i << ' ';
    return 0;
}