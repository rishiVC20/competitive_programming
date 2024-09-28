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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll sum = 0;
        if (a>c && b>d){
            sum++;
        } 
        if (a>d && b>c)
            sum++;
        if (b>c && a>d)
            sum++;
        if (b>d && a>c)
            sum++;       
        if (a>c){
            if (b==d)
                sum++;
        }     
        if (a>d){
            if (b==c)
                sum++;
        }
        if (b>d){
            if (a==c)
                sum++;
        }
        if (b>c){
            if (a==d)
                sum++;
        }
        if (b==d){
            if (a>c)
                sum++;
        }
        if (b==c){
            if (a>d)
                sum++;
        }
        if (a==c){
            if (b>d)
                sum++;
        }
        if (a==d){
            if (b>c){
                sum++;
            }
        }

        cout<<sum<<endl;
    }
    return 0;
}