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
        ll i = n-1;
        bool flag = false;
        ll k = n-1;
        while (i >= 1)
        {
            // cout<<i<<" ";
            string p = s.substr(i-1,2);
            // cout<<i<<" ";
            string q = s.substr(0,i-1);
            cout<<q<<" ";
            cout<<p<<" ";
            // size_t found = q.find(s);
            // // cout<<found<<" ";
            auto it = search(q.begin(),q.end(),p.begin(),p.end());
            if (it != q.end()){
                flag = true;
                break;
            }
            // else{
            //     s.pop_back();
                
            // }
            i--;
            // k--;
            // cout<<s<<" ";
            
        }       
        if (flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
    }
    return 0;
}


/*
NO
YES
NO
YES
NO
YES

*/