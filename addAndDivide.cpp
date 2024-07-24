// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        ll count = 0;
        while (a )
        {
            b++;
            count++;
            a /= b;
            if (a>b)
                count++;
            else    
                break;
        }       
        cout<<count+1<<endl;
    }
    return 0;
}