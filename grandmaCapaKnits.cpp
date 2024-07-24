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

bool isPalindrome(string s)
{
    ll i=0, j=s.size()-1;
    while (i<=j){
        if (s[i]!=s[j])
            return false;
        i++, j--;    
    }

    return true;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;  
        if (isPalindrome(s)){
            cout<<0<<endl;
            continue;
        }

        ll x,y;
        ll i=0, j=n-1;
        // while (i<=j){
        //     if (s[i]!=s[j]){
        //         x = i;
        //         y = j;
        //         break;
        //     }
        // }
        ll s1,s2;
        ll p1=0, p2=0;
        char c1=s[x], c2=s[y];
        // for (ll i=0; i<n; i++){
        //     if (s[i]!=c1){
        //         s1 += s[i];
        //     }
        //     else if (s[i]==c1)
        //         p1++;

        //     if (s[i]!=c2){
        //         s2 += s[i];
        //     }    
        //     else if (s[i]==c2)
        //         p2++;
        // }

        ll sum = n+1;
        for (ll d=0; d<26; d++)
        {
            ll cnt = 0, i=0, j=n-1;
            while (i<=j){
                if (s[i]==s[j]){
                    i++;j--;
                }
                else if (s[i] == char('a'+d)){
                    i++; cnt++;
                }
                else if (s[j] == char('a'+d)){
                    j--; cnt++;
                }
                else{
                    cnt = n+1;
                    break;
                }
            }
            sum = min(cnt,sum);
        }

        if (sum==n+1){
            cout<<-1<<endl;
            continue;
        }

        cout<<sum<<endl;

    }
    return 0;
}