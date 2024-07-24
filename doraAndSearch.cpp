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
        vector<ll>arr;
        for (ll i=0; i<n; i++){
            ll x;
            cin>>x;
            arr.push_back(x);
        }     
        if (n <= 3){
            cout<<-1<<endl;
            continue;
        }  
        ll l = 0;
        ll r = n-1;
        ll a = 1;
        ll b = n;
        bool f = true;
        while (l < r){
            if (arr[l]==a){
                a++;
                l++;
            }
            else if (arr[l]==b){
                b--;
                l++;
            }
            else if (arr[r]==a){
                a++;
                r--;
            }
            else if (arr[r]==b){
                b--;
                r--;
            }
            else{
                cout<<l+1<<" "<<r+1<<endl;
                f = false;
                break;
            }
        }
        if (f){
            cout<<-1<<endl;
        }
    }
    return 0;
}