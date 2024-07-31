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
        string s;
        cin>>s;
        ll n = s.size();
        string k = "";
        bool f=false;
        k+=s[0];
        for (ll i=1; i<n; i++){
            if (s[i]==s[i-1] && !f){
                if (s[i]!='z'){
                    ll p = s[i]-'a';
                    p++;
                    char q = static_cast<char>(p+'a');
                    // cout<<q<<' ';
                    string x = to_string(q);
                    k += q;
                }
                else{
                    k+="a";
                }
                k+=s[i];
                f=true;
            }
            else{
                k+=s[i];
            }
        }       
        if (!f){
            // string r= s.substr(1,n-1);
            // k+=r;
            if (s[n-1]=='z'){
                k += "a";
                cout<<k<<endl;
                continue;
            }
            ll c = s[n-1]-'a';
            c++;
            char p = static_cast<char>(c+'a');
            // cout<<p<<' ';
            // string y = to_string(p);
            k += p;
        }
        cout<<k<<endl;
    }
    return 0;
}