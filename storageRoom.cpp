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
        
        // vector<vector<ll>> arr(n, vector<ll>(n));
        ll arr[n][n];
        vector<ll>result(n,(1<<30)-1);
        for (ll i=0; i<n; i++)
        {
            for (ll j=0; j<n; j++)
            {
                cin>>arr[i][j];
                if (i!=j){
                    result[i] = result[i] & arr[i][j];
                    result[j] = result[j] & arr[i][j];
                }
            }
        }
        // if (n==1){
        //     cout<<"YES"<<endl;
        //     // cout<<0<<endl;
        //     // continue;
        // }
        // else{
            
            ll flag = 1;
            for (ll i=0; i<n; i++)
            {
                for (ll j=0; j<n; j++)
                {
                    // result[i] = result[i] & arr[i][j];
                    // result[j] = result[j] & arr[i][j];
                    if (arr[i][j] != (result[i] | result[j]) && i!=j){
                        flag = 0;
                        // break;
                    }
                }
                if (flag==0)
                    break;
            }
            if (flag){
                cout<<"YES"<<endl;
                for (ll i=0; i<n; i++)
                    cout<<result[i]<<" ";
            }
            else{
                cout<<"NO"<<" ";
            }
            cout<<endl;
        // }

    }
    return 0;
}