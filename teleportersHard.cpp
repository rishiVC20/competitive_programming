// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,c;
        cin>>n>>c;
        vector<ll>arr;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            if (i+1 > n/2)
            {
                arr.push_back(x+(n-i));
            }
            else{
                arr.push_back(x+i+1);
            }
        }       
        sort(arr.begin(),arr.end());
        for (auto i:arr)
            cout<<i<<" ";
        ll count = 0;
        for (ll i=0; i<n; i++)
        {
            if (c >= arr[i])
            {
                count++;
                c -= arr[i];
            }
            else
                break;
        }
        cout<<count<<endl;
    }
    return 0;
}


/*
2
3
0
1
3
2
1
1
2
2

*/