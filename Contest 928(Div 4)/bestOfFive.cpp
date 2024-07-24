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
        ll countA=0;
        ll countB=0;
        for(ll i=0; i<5; i++)
        {
            if (s[i]=='A')
                countA++;
            else    
                countB++; 
        }
        if (countA > countB)
            cout<<'A'<<endl;
        else
            cout<<'B'<<endl;    
    }
    return 0;
}

// https://codeforces.com/contest/1926/problem/A