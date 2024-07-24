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
        for (ll i=0; i<n; i++)
        {
            if (s[i]=='1')  
                count++;
        }
        // cout<<count<<" ";
        if (count%2){
            cout<<"NO"<<endl;
            continue;
        }
        ll maxi = 0;
        bool flag = true;
        if (count == 2){
            for (ll i=0; i<n; i++)
            {
                if (s[i]=='1'){
                    maxi++;
                }
                else{
                    maxi=0;
                }
                if (maxi==2){
                    flag = false;
                    break;
                }
            }
            if (!flag){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}