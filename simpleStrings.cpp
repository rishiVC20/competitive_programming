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
    string s;
    cin>>s;
    ll n = s.size();
    if (n==1){
        cout<<s<<endl;
        return 0;
    }
    string p = "";
    p+=s[0];
    ll i=0, j=1;
    while (j<n){
        if (s[i]==s[j]){
            if (i!=0)
                p += s[i];
            while (s[i]==s[j]){
                p += ".";
                j++;
            }
            i=j, j++;
        }
        else{
            if (i!=0)
                p += s[i];
            i++, j++;
        }
    }
    if (j==n)
        p += s[n-1];
    for (ll i=1; i<n; i++){
        if (p[i]=='.'){
            char h=p[i-1]+1;
            if (p[i-1]=='z'){
                h='a';
            }
            if (i+1 < n){
                if (p[i+1] != h){
                    p[i]=h;
                }
                else{
                    char w = p[i+1]+1;
                    if (p[i+1]=='z')
                        w='a';
                    p[i]=w;
                }
            }
            else{
                p[i]=h;
            }
        }
    }
    for (ll i=1; i<n-1; i++){
        if (s[i]!=p[i]){
            if (p[i-1]!=s[i] && p[i+1]!=s[i])
                p[i] = s[i];
        }
    }
    if (s[n-1] != p[n-1]){
        if (n-2>=0){
            if (s[n-1] != p[n-2]){
                p[n-1] = s[n-1];
            }
        }
    }
    cout<<p<<endl;
    return 0;
}