// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  




int main() {
    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,m;
        cin>>n>>m;
        vi a(n+1),b(n+1);
        for(ll i=1; i<=n; i++){
            ll x;cin>>x;
            a[i]=x;
        }
        for(ll i=1; i<=m; i++){
            ll x;cin>>x;
            b[i]=x;
        }
        ll cn=0;
        for(ll i=1; i<=m; i++){
            ll k=b[i];
            if(a[k]>0){
                a[k]--;
            }
            else{
                cn++;
            }
        }

        cout<<cn<<endl;
    }
    return 0;
}