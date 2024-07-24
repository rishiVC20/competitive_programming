// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        string a,b;
        cin>>a>>b;
        string c = a+b;
        ll n; cin>>n;
        vector<string>arr(n);
        for (ll i=0; i<n; i++)
            cin>>arr[i];
        string sum = "";
        for (ll i=0; i<n; i++)
            sum += arr[i];
        // sort(sum.begin(),sum.end());
        // sort(c.begin(),c.end());
        // if (sum==c)
        //     cout<<"YES"<<endl;
        // else
        //     cout<<"NO"<<endl;  

        vector<ll>arr1(27,0);  
        vector<ll>arr2(27,0);
        for (ll i=0; i<n; i++)
            arr1[c[i]]++;  
        for (ll i=0; i<n; i++)
            arr2[sum[i]]++;
            
   }
    return 0;
}