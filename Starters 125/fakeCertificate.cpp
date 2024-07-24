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
        string s;
        cin>>s;
        ll sum1 = 0;
        ll maxi = INT_MIN;
        ll curr = 0;
        for (ll i=0; i<n; i++){
            if (s[i]=='1')
                sum1++;
        }      
        if (sum1 == n)
        {
            cout<<n<<endl;
        }
        else{
            for (ll i=0; i<n; i++)
            {
                if (s[i]=='0'){
                    curr++;
                    maxi = max(maxi,curr);
                }
                else{
                    curr = 0;
                }
                maxi = max(maxi,curr);
            }
            cout<<maxi+sum1<<endl;
        }
    }
    return 0;
}