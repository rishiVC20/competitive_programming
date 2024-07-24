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
        ll cnt1 = 0;
        ll cnt2 = 0;
        for (auto i:s)
        {
            if (i=='('){
                cnt1++;
            }
            else if (i==')' && cnt1<=0){
                cnt2++;
            }
            else if (i==')'){
                cnt1--;
            }
        }
        cout<<cnt2<<endl;
    }
    return 0;
}