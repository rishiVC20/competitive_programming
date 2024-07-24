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
        ll count = 0;
        count += n/2;
        count += 12*(n/2);
        // cout<<count<<" ";
        if (n%2){
            count += 6;
        }
        cout<<count<<endl;
    }
    return 0;
}

//6 1 6  6+1+12