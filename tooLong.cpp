// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        if (s.size() <= 10){
            cout<<s<<endl;
        }
        else{
            int n=s.size();
            string p=to_string(n-2);
            string ans="";
            ans = (s[0]+p+s[n-1]);
            cout<<ans<<endl;
        }
    }
    return 0;
}

// https://codeforces.com/problemset/problem/71/A