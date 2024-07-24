// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll sum = 0;
        ll cnt = 0;
        ll mini = INT_MAX;
        for (ll i=0; i<n; i++)
        {
            ll x; cin>>x;
            mini = min(mini,abs(x));
            if (x <= 0)
                cnt++;
            sum += abs(x);    
        }
        // cout<<sum<<" "<<cnt<<" "<<mini<<" ";
        if (cnt%2)
        {
            sum -= 2*abs(mini);
            cout<<sum<<endl;
            continue;
        }
        cout<<sum<<endl;
    }
    return 0;
}