// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        ll p = s[0]-'0';
        ll q = s[1]-'0';
        ll r = p*10+q;
        string a;
        if (r>=12)
            a = " PM";
        else
            a = " AM";
        if (p == 24)
            a = "AM";    
        string ans;
        // cout<<r<<" ";
        if (r==0)
        {
            ans.push_back('1');
            ans.push_back('2');
            ans.push_back(s[2]);
            ans.push_back(s[3]);
            ans.push_back(s[4]);
            ans += a;
            cout<<ans<<endl;
            continue;
        }
        if (r <= 12)
        {
            ans.push_back(s[0]);
            ans.push_back(s[1]);
            ans.push_back(s[2]);
            ans.push_back(s[3]);
            ans.push_back(s[4]);
            if (r==12)
                ans += " PM";
            else
                ans += " AM";    
            // ans += a;
            cout<<ans<<endl;
            // continue;
        }    
        else{
            int k = r%12;
            // cout<<k<<" ";
            char p = k + '0';
            // cout<<p<<" ";
            if (k<10){
                ans.push_back('0');
                ans.push_back(p);
            }
            else{
                ans.push_back(k/10+'0');
                ans.push_back(k%10+'0');
            }
            ans.push_back(s[2]);
            ans.push_back(s[3]);
            ans.push_back(s[4]);
            ans += a;
            cout<<ans<<endl;
        }        
           
    }
    return 0;
}

/*
09:41 AM
06:06 PM
12:14 PM
12:59 AM
12:00 AM
02:34 PM
01:01 AM
07:07 PM
11:59 AM
12:00 PM
09:37 PM

*/