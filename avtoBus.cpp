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
        if (n%2 != 0 || n<4)
        {
            cout<<-1<<endl;
            continue;
        }       
        else if (n%6==0 && n%4==0){
            cout<<n/6<<" "<<n/4<<endl;
            continue;
        }
        else{
            ll k = n;
            ll p = n/6;
            n = n-p*6;
            if (n%6==2 || n%6==4)
                p++;
            cout<<p<<" ";
            ll m = k/4;
            cout<<m<<endl;
        }
    }
    return 0;
}

/*
1 1
-1
4 6
166374058999707392 249561088499561088

*/

// https://codeforces.com/problemset/problem/1679/A