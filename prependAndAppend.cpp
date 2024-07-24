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
        ll count = 0;
        ll i = 0;
        ll j = n-1;
        while (i<j)
        {
            if ((s[i]=='1'&&s[j]=='0') || (s[i]=='0'&&s[j]=='1')){
                count++;
                i++;
                j--;
            }
            else    
                break;    
        }       
        count *= 2;
        cout<<n-count<<endl;
    }
    return 0;
}