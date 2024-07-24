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
        sort(arr.begin(),arr.end(),greater<int>());
        double sum = (arr[0]+arr[1])/2;
        for (ll i=2; i<n; i++)
        {
            sum = (sum+arr[i])/2;
        }  
        cout<<fixed<<setprecision(8)<<sum<<endl;
    }
    return 0;
}

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    
    return 0;
}