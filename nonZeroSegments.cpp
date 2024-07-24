// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    
        ll n;
        cin>>n;
        vector<ll>arr(n);
        set<ll>st;
        ll ans = 0;
        ll sum = 0;
        for (ll i=0; i<n;i++)
        {
            ll x;
            cin>>x;
            sum += x;
            st.insert(0);
            if (st.count(sum))
            {
                // st.insert(0);
                st.clear();
                ans++;
                sum = x;
                st.insert(0);
            }
            st.insert(sum);
        }    
        cout<<ans<<endl;
    return 0;
}
