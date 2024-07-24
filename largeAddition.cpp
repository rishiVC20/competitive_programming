// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back 
#define onebit(x) __builtin_popcountll(x)
#define vi vector<ll> 

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

bool check (int n)
{
    while (n)
    {
        if (n%10 < 5)
            return false;
        n /= 10;    
    }

    return true;
}
int main() {
    ll t;
    cin>>t;
    vi pre(18);
    pre[0] = pre[1] = 0;
    pre[2] = 10;
    // pre[3] = 110;
    for (ll i=3; i<18; i++){
        pre[i] = pow(10,i-1) + pre[i-1];
        // cout<<pre[i]<<" ";
        // cout<<powl(10,i-1)<<" "<<pre[i-1]<<" ";
    }
    // cout<<endl;
    while (t--)
    {
        ll n;
        cin>>n;
        ll m = n;
        ll cn = 0;
        // while (m){
        //     cn++;
        //     m /= 10;
        // }
        // if (cn==1){
        //     if (n>=5 && n<=9)
        //         cout<<"YES"<<endl;
        //     else
        //         cout<<"NO"<<endl;
        //     continue;        
        // }
        // string f1 = "0";
        // for (ll i=0; i<cn-1; i++)
        //     f1 = '1' + f1;
        // string f2 = "1";
        // for (ll i=0; i<cn-1; i++)
        //     f2 += '9';
        // ll q1 = stoi(f1);
        // ll q2 = stoi(f2);
        string s = to_string(n);
        ll qq = s.size();
        if (s[0] != '1' || s[qq-1]=='9'){
            cout<<"NO"<<endl;
            continue;
        }
        // if (cn==3 && n%10==9){
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        bool f= true;
        for (ll i=qq-2; i>=1; i--)
        {
            ll k = s[i]-'0';
            k += 9;
            if (k==9){
                f = false;
                break;
            }
        }
        if (f)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;    
        // ll q1 = pre[cn];
        // cout<<q1<<" ";
        // ll q2 = 2*pow(10,cn-1) - 1;
        // if (n >= q1 && n<=q2)
        //     cout<<"YES"<<endl;
        // else
        //     cout<<"NO"<<endl;        
    }
    return 0;
}