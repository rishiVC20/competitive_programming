// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        // if(a/b == c/d && a%b==c%d)
        //     cout<<0;
        // else if (a==0 || c==0)
        //     cout<<1;
        // else{
        //     if ((a*d)%(c*b)==0 || (c*b)%(a*d)==0)
        //         cout<<1;
        //     else
        //         cout<<2;    
        // }        
        // cout<<endl;

        ll x = a*d;
        ll y = b*c;
        // if (a==0 || c==0)
            // cout<<
        if (x==y)
            cout<<0;
        // else if (x=0 || y==0)
        //     cout<<1;
        else if (y!=0 && x%y==0 || x!=0 && y%x==0)
            cout<<1;
        else    
            cout<<2;
        cout<<endl;            
    }
    return 0;
}