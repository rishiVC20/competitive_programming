// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>arr(n);
        vector<ll>sortedArr(n);
        for (ll i=0; i<n; i++)
        {
            cin>>arr[i];
            sortedArr[i] = arr[i];
        }
        sort(sortedArr.begin(),sortedArr.end());
        if (k==1)
        {
            ll flag = 1;
            for (ll i=0; i<n; i++)
            {
                if (arr[i] != sortedArr[i]){
                    flag = 0;
                    break;
                }
            }
            if (flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;    
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}