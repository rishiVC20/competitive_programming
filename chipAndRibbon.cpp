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
        vector<ll>m(n);
        for (ll i=0; i<n; i++)
            cin>>m[i];

        ll sum = 0;
        for (ll i=1; i<n; i++)
        {
            // sum += max(0,m[i]-m[i-1]);
            if (m[i]-m[i-1] > 0)
                sum += (m[i]-m[i-1]);
        }
        sum += m[0]-1;
        cout<<sum<<endl;
    }
    return 0;
}