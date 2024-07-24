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
       
        ll highest_set_bit = std::numeric_limits<ll>::digits - __builtin_clz(n);
        ll lower_bound = 1 << highest_set_bit;
        cout<<lower_bound<<endl;
    }
    return 0;
}