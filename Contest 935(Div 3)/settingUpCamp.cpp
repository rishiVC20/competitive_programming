// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll in,ex,u;
        cin>>in>>ex>>u;
        ll count = 0;
        count += in;
        // cout<<count<<" ";
        count += ex/3;  
        // cout<<count<<" ";
        ll p = ex%3;
        p += u;
        // cout<<p<<" ";
        if (p>0 && p<3 && ex%3!=0)
            cout<<-1<<endl;
        else{
            count += p/3 + (p%3!=0);
            cout<<count<<endl;
        }    
    }
    return 0;
}

/*
3
-1
3
-1
3
28
0
7
8
1666666667

*/