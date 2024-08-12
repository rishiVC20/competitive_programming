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

ll mul (ll a, ll b, ll m=mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll LCM(ll a, ll b)
{
    
    a = (a*b)/(__gcd(a,b));
    return a;
}
bool customComparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}
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
        ll n;
        cin>>n;
        // bool f=false;
        // for (ll i=2; i<=n; i++){
        //     for (ll j=2; j*j<=i; j++){
        //         ll k=n/(i*j);
        //         if ((i*j*k == n) && i!=j && j!=k && i!=k && k>=2){
        //             f=true;
        //             YES;
        //             cout<<i<<' '<<j<<' '<<k<<endl;
        //             break;
        //         }
        //     }
        //     if (f)
        //         break;
        // }
        // if (!f){
        //     NO;
        // }
        // ll l=2, r=1e9;
        // bool f=false;
        // while (l<r){
        //     ll mid = (l+r)/2;
        //     if (l*r*mid==n){
        //         f=true;
        //         YES;
        //         cout<<l<<' '<<r<<' '<<mid<<endl;
        //         break;
        //     }
        //     else if (l*r*mid < n){
        //         l=mid;
        //     }
        //     else{
        //         r=mid;
        //     }
        // }
        // if (!f){
        //     NO;
        // }
        set<ll>st;
        for (ll i=2; i*i<=n; i++){
            if (n%i==0 && st.find(i)==st.end()){
                st.insert(i);
                n/=i;
                break;
            }
        }
        for (ll i=2; i*i<=n; i++){
            if (n%i==0 && st.find(i)==st.end()){
                st.insert(i);
                n/=i;
                break;
            }
        }
        if (st.size()==2 && st.find(n)==st.end()){
            YES;
            for (auto i:st)
                cout<<i<<' ';
            cout<<n;    
            cout<<endl;
            continue;    
        }
        NO;

    }
    return 0;
}