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
    ll n,h;
    cin>>n>>h;
    vi a;
    for (ll i=0; i<n; i++){
        ll x; cin>>x;
        a.pb(x);
    }
    if (n<=2){
        cout<<n<<endl;
        return 0;
    }
    ll qq = 1;
    ll k;
    if (a[0]<a[1]){
        k=-1;
        bool f=true;
        ll cn=0;
        ll sum = a[0];
        for (ll i=1; i<n; i++){
            if (sum+a[i] == h){
                k=i;
                f=false;
                cn++;
            }
            else if (sum+a[i] > h){
                k=i-1;
                f=false;
                break;
            }
            else{
                if (!f ){
                    // k=i;
                    break;
                }
            }
            if (cn==2)
                break;
            if (i%2 == 0){
                sum += max(a[i],a[i-1]);
            }    
        }
        if (f){
            cout<<1<<endl;
            return 0;
        }
        if (k%2==1){
            k++;
        }
        k++; //k is 0 indexed ll 
        qq = max(qq,k);
    }
    // else{
        ll q=-1;
        bool f=true;
        ll pp=0;
        ll res = max(a[0],a[1]);
        for (ll i=2; i<n; i++){
            if (res+a[i] == h){
                q=i;
                f=false;
                pp++;
            }
            else if (res+a[i] > h){
                q = i-1;
                f=false;
                break;
            }
            else{
                if (!f)
                    break;
            }
            if (pp==2)
                break;
            if (i%2 == 1){
                res += max(a[i],a[i-1]);
            }    
        }
        if (f){
            cout<<n<<endl;
            return 0;
        }
        if (q%2 == 0)
            q++;
        ll ans = 2+(q-1);
        qq = max(qq,ans);

    // }

    cout<<qq<<endl;


    
    return 0;
}