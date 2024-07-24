// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

const ll mod = 1e9+7;

ll power(ll base, ll exponent)
{
    if (exponent < 0)
    {
        return 0;
    }
    ll ans = 1;
    while (exponent)
    {
        if (exponent%2==0)
        {
            base = (base*base) % mod;
            exponent = exponent/2;
        }
        else
        {
            ans = (ans*base) % mod;
            exponent--;
        }
    }
    return ans;
}


int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k,pt,ps;
        cin>>n>>k>>pt>>ps;
        pair<ll,ll>arr[n];
        // ll kb,ks,kt,pt;
        ll b1,b2,b3,b4;
        ll s1,s2,s3,s4;
        for (int i=0; i<n; i++)
            cin>>arr[i].first;
        for (ll i=0; i<n; i++){
            cin>>arr[i].second;
            if (i==pt-1){
                b1 = arr[i].second;
                b2 = arr[i].first;
            }
            if (i==ps-1){  
                s1 = arr[i].second;
                s2 = arr[i].first;
            }  
        }    
        cout<<b1<<" "<<b2<<" ";
        // for (ll i=0; i<n; i++)
        // {
        //     if (i==b2-1)
        //         b3 = arr[i].second;
        //     if (i==s2-1)
        //         s3 = arr[i].second;    
        // }
        ll bd = b1;
        ll ss = s1;
        for (int i=0; i<k-1; i++)
        {
            ll k1 = arr[b2].second;
            ll k2 = arr[b2].first;
            if (k1 > b1){
                bd += k1;
                b2 = k2;
                b1 = k1;
            }
            else{
                bd += b1;
            }
        }
        for (ll i=0; i<k-1; i++){
            ll p1 = arr[s2].second;
            ll p2 = arr[s2].first;
            if (p1 > s1){
                ss += p1;
                s2 = p2;
                s1 = p1;
            }
            else{
                ss += s1;
            }
        }
        // if (b3 > b1){
        //     bd += b3*(k-1);
        // }
        // else{
        //     bd += b1*(k-1);
        // }
        // if (s3 > s1){
        //     ss += s3*(k-1);
        // }
        // else{
        //     ss += s1*(k-1);
        // }
        if (bd > ss){
            cout<<"Bodya"<<endl;
        }
        else if (bd < ss){
            cout<<"Sasha"<<endl;
        }
        else{
            cout<<"Draw"<<endl;
        }
        // unordered_map<ll,ll>mp;
        // for (ll i=0; )
    }
    return 0;
}