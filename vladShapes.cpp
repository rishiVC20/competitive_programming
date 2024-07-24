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
        string arr[n];
        for (ll i=0; i<n; i++)
        {
                cin >> arr[i];
        }
        vector<ll>row(n+1,0);
        ll k=1;
        for (auto i:arr)
        {
            string s = i;
            for (ll j=0; j<s.size(); j++)
            {
                if(s[j]=='1')
                    row[k]++;
            }
            k++;
        }
        sort(row.begin(),row.end());
        if (row[n] != row[n-1])
        {
            cout<<"TRIANGLE";
        }
        else
            cout<<"SQUARE";

        cout<<endl;        

    }
    return 0;
}