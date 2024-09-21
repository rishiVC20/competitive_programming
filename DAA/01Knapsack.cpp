#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cout << "Enter the number of items: ";
    cin >> n;
    ll cap;
    cout << "Enter the capacity of bag: ";
    cin >> cap;
    vector<ll> profit(n + 1);
    vector<ll> weight(n + 1);
    profit[0] = 0, weight[0] = 0;
    cout << "Enter " << n << " profits from each item: ";
    for (ll i = 1; i <= n; i++)
    {
        cin >> profit[i];
    }
    cout << "Enter " << n << " weights from each item: ";
    for (ll i = 1; i <= n; i++)
    {
        cin >> weight[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(cap + 1, 0));
    // for (ll i=0; i<n; i++){
    //     for(ll j=0; j<cap+1; j++){
    //         dp[i][j]=0;
    //     }
    //     break;
    // }
    // for (ll i=0; i<cap; i++){
    //     for(ll j=0; j<n+1; j++){
    //         dp[j][i]=0;
    //     }
    //     break;
    // }
    vector<int> b;
    for (ll i = 1; i < n + 1; i++)
    {
        for (ll j = 1; j < cap + 1; j++)
        {
            if (j - weight[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], profit[i] + dp[i - 1][j - weight[i]]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << "The final dp matrix is as shown below: " << endl;
    for (ll i = 0; i < n + 1; i++)
    {
        for (ll j = 0; j < cap + 1; j++)
        {
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    ll i = n, j = cap;
    // cout<<i<<' '<<j<<endl;
    vector<int> d;

    while (i > 0 && j > 0)
    {
        while (dp[i][j] == dp[i - 1][j] && i > 0 && j > 0)
        {
            i--;
        }
        d.push_back(i);
        // cout<<i<<' ';
        if (i > 0)
            j -= weight[i];

        i--;
        if (i == -1)
            break;
    }
    cout << "max profit: " << dp[n][cap] << endl;
    cout << "Items taken into considerations are: ";
    for (auto i : d)
        cout << i << ' ';
    cout << endl;
}