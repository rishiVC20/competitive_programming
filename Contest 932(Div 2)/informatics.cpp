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
        vector<ll>arr(n);
        set<ll>st;
        for (ll i=0; i<n; i++)
        {
            cin>>arr[i];
            st.insert(arr[i]);
        }
        sort(arr.begin(),arr.end());
        bool flag = true;
        bool lk = true;
        ll sum = std::accumulate(arr.begin(),arr.end(),0);
        if (sum == 0 )
        {
            cout<<2<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<2<<" "<<n<<endl;
            continue;
        }
        if (n > st.size())
        {
            for (ll i=0; i<n; i++)
            {
                if (arr[i] >= st.size())
                {
                    lk = false;
                    break;
                }
            }
            if (lk==true && arr[n-1] < arr.size())
            {
                cout<<-1<<endl;
                continue;
            }
        }
        
        for (ll i=0; i<n; i++)
        {
            if (i != arr[i])
            {
                flag = false;
                break;
            }
        }    
        if (!flag)
        {
            cout<<2<<endl;
            cout<<1<<" "<<1<<endl;
            cout<<2<<" "<<n<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}