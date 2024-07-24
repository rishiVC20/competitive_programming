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
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        ll i,j,k;
        ll curr = -1;
        for (ll p=0; p<n-1; p++)
        {
            if (arr[p]>arr[p-1] && arr[p]>arr[p+1]){
                i = p;
                j = p+1;
                k = p+2;
                curr = n;
                break;
            }
        }           
        if (curr == -1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<i<<" "<<j<<" "<<k<<endl;
        }
        
    }
    return 0;
}