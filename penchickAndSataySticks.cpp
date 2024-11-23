// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;




int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n;
        cin>>n;
        vi a;
        bool f=true;
        for(ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            if(abs((i+1)-x) > 1){
                f=false;
            }           
        }

       
        if(f)
            YES;
        else
            NO;    
    }
    return 0;
}