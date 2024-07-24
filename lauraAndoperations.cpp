// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        vector<ll>m(3,0);
        if (abs(a-b)%2 == 0)
            m[2]=1;
        if (abs(a-c)%2 == 0)
            m[1] = 1;
        if (abs(b-c)%2 == 0)
            m[0] = 1;

        for (ll i=0; i<3; i++) 
            cout<<m[i]<<" ";
        cout<<endl;               
    }
    return 0;
}
/*
1 1 1
0 0 1
0 1 0
1 0 0
1 0 0
0 1 0
0 0 1
1 1 1
1 1 1
0 0 1
0 1 0
1 0 0
1 0 0
0 1 0
0 0 1
1 1 1

16
1 1 1
1 1 2
1 2 1
1 2 2
2 1 1
2 1 2
2 2 1
2 2 2
100 100 100
100 100 99
100 99 100
100 99 99
99 100 100
99 100 99
99 99 100
99 99 99
*/