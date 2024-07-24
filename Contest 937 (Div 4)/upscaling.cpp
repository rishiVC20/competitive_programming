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
        ll m = n;
        string p,q;
        while (m)
        {
            if (m%2)
            {
                p.push_back('#');
                p.push_back('#');
            }
            else{
                p.push_back('.');
                p.push_back('.');
            }
            m--;
        }       
        m = n;
        while (m)
        {
            if (m%2)
            {
                q.push_back('.');
                q.push_back('.');
            }
            else{
                q.push_back('#');
                q.push_back('#');
            }
            m--;
        }
        while (n)
        {
            if (n%2)
            {
                cout<<p<<endl;
                cout<<p<<endl;
            }
            else{
                cout<<q<<endl;
                cout<<q<<endl;
            }
            n--;
        }

    }
    return 0;
}