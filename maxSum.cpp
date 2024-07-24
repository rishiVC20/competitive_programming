// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define MOD 1000000007
const int P = 1e9 + 7;
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>arr;
        for (ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            arr.push_back(x);
        }       
        ll sum = 0;
        ll maxi = 0;
        ll curr = 0;
        for (ll j=0; j<arr.size(); j++)
        {
            curr += arr[j];
            sum += arr[j];
            if (sum<0){
                sum = 0;
            }
            else{
                maxi = max(sum,maxi);
            }
        }
        arr.push_back((maxi%P + P)%P);
        ll m = maxi;
        while (k>0)
        {
            maxi += maxi%P;
            // maxi *= 2;
            arr.push_back((maxi%P + P)%P);
            k--;
        }
        ll ans = 0;
        curr += maxi%P - m%P;
        // for (ll i=0; i<arr.size(); i++){
        //     ans += arr[i];
        // }
        // for (ll i=0; i<arr.size(); i++)
        //     cout<<arr[i]<<" ";
        // cout<<maxi<<" ";
        // ll ans = accumulate(arr.begin(),arr.end(),0);
        // cout<<ans<<" ";
        cout<<(curr%P + P)%P<<endl;
        // cout<<generalModulo(ans,MOD)<<endl;
        // cout<<ans % MOD<<endl;
        // cout<<(-11)%1000000007<<endl;
        // cout<<endl;1000000000
    }
    return 0;
}

/*
999999996
96
896
17
351
716455332
42
2
0
897909241
0
416571966

*/