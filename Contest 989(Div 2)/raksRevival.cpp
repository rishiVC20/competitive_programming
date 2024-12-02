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
        ll n,m,k;
        cin>>n>>m>>k;
        string s;cin>>s;

        ll i=0;
        ll cn=0,cp=0;
        while(i<n){
            if(s[i]=='1'){
                cn=0;
                i++;
                continue;
            }
            else{
                cn++;
                if(cn==m){
                    cp++;
                    i+=k;
                    cn=0;
                }
                else{
                    i++;
                }
            }
        }

        cout<<cp<<endl;

    }
    return 0;
}