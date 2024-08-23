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
const ll MAX = 1e7;
vector<bool> ww(MAX, false);
vector<bool> xx(MAX, true);

void sieve() {
    xx[0] = xx[1] = false; 
    for (ll i = 2; i < MAX; ++i) {
        if (xx[i]) {
            for (ll j = i * i; j < MAX; j += i) {
                xx[j] = false;
                ww[j] = true;
            }
        }
    }
    for (ll i = 0; i < MAX; ++i) {
        if (!xx[i]) {
            ww[i] = true;
        }
    }
}
ll check(ll x){
    // if ()
    for (ll i=2; i*i<=x; i++){
        if (x%i==0){
            return true;
        }

    }
    return false;
}
int main() {
    ll t;
    cin>>t;
    sieve();
    vector<bool> pre(2e5,false);
    // for (ll i=3; i<2e5; i++){
    //     if (i%2==0){
    //         pre[i]=true;
    //         continue;
    //     }
    //     if (check(i)){
    //         pre[i]=true;
    //     }
    // }
    while (t--)
    {
        ll n;
        cin>>n;
        vi a;
        vector<pair<ll,ll>>v;
        ll p=0,q=0;
        
        for (ll i=0; i<n; i++){
            ll x;cin>>x;
            a.pb(x);
            v.pb({x,i});
            if (x%2)
                p++;
            else
                q++;    
        }
        bool f=false;
        sort(v.begin(),v.end(),[&](pair<ll,ll>a,pair<ll,ll>b){
            return a.first<b.first;
        });
        if (p>=2){
            ll ss=-1,dd=-1;
            for (ll i=n-1; i>=0; i--){
                if (v[i].first%2==1 && ss==-1){
                    ss=v[i].second;
                }
                else if (v[i].first%2==1 && dd==-1){
                    dd=v[i].second;
                }
                if (ss!=-1 && dd!=-1)
                    break;
            }
            ll hh = a[ss]+a[dd];
            if (hh > 2 && ww[hh] && ss!=dd){
                f=true;
                cout<<ss+1<<' '<<dd+1<<endl;
                // continue;
            }
        }
        if (f){
            continue;
        }
        if (q>=2){
            ll ss=-1,dd=-1;
            for (ll i=n-1; i>=0; i--){
                if (v[i].first%2==0 && ss==-1){
                    ss=v[i].second;
                }
                else if (v[i].first%2==0 && dd==-1){
                    dd=v[i].second;
                }
                if (ss!=-1 && dd!=-1)
                    break;
            }
            ll hh = a[ss]+a[dd]; 
            if (hh>2 && ww[hh] && ss!=dd){
                f=true;
                cout<<ss+1<<' '<<dd+1<<endl;
                // continue;
            }
        }
        if (f){
            continue;
        }
        ll bb=-1,gg=-1;
        for (ll i=n-1; i>=0; i--){
            if (v[i].first%2==1 && bb==-1){
                bb=v[i].second;
            }
            if (v[i].first%2==0 && gg==-1){
                gg=v[i].second;
            }
            // cout<<bb<<' '<<gg<<' ';
        }
        if (bb==-1 || gg==-1){
            cout<<-1<<endl;
            continue;
        }
        ll y=a[bb]+a[gg];
        if (y % 2 == 0 || ww[y]){
            cout<<bb+1<<' '<<gg+1<<endl;
            // continue;
        }
        else{
            cout<<-1<<endl;
        }
        // if (pre[y]==true){
        //     cout<<bb+1<<' '<<gg+1<<endl;
        //     continue;
        // }
        
    }
    return 0;
}