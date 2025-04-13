// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll>
#define vvp vector<pair<ll,ll>>
#define vvt vector<tuple<ll,ll,ll>>
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define YES cout<<'Y'<<'E'<<'S'<<endl
#define NO cout<<'N'<<'O'<<endl  

const ll mod = 1e9+7;


bool solve(ll n){
    if(n<2)
        return false; 
    if(n%2==0)
        return false;      
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);


    ll tt;
    cin>>tt;
    while (tt--)
    {
        ll n,k;
        cin>>n>>k;
        bool ff=solve(n);
        // cout<<ff<<' ';
        if(n==1 && k==2){
            YES;
            continue;
        }
        if(n==2 && k<=1){
            YES;
            continue;
        }
        // cout<<ff<<' ';
        if(k==1){
            if(ff){
                YES;
            }
            else{
                NO;
            }
        }
        else{
            NO;
        }
    }
    return 0;
}