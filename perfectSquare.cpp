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
        vector<vector<char>> a(n,vector<char>(n));
        for (ll i=0; i<n; i++){
            for (ll j=0; j<n; j++){
                cin>>a[i][j];
            }
        }
        
        vector<vector<char>> b(n,vector<char>(n));
        vector<vector<bool>> f(n,vector<bool>(n,false));
        ll k = n-1, q=0;
        for (ll i=0; i<n; i++){
            for (ll j=0; j<n; j++){
                b[i][j] = a[k][q];
                k--;
            }
            q++;
            k = n-1;
        }
        // for (ll i=0; i<n; i++){
        //     for (ll j=0; j<n; j++){
        //         cout<<b[i][j];
        //     }
        //     cout<<endl;
        // }
        ll sum = 0;
        for (ll i=0; i<n; i++){
            // bool f = false;
            for (ll j=0; j<n; j++){
                // if (j<i)
                //     continue;
                // sum += abs(a[i][j]-b[i][j]);
                // // cout<<a[i][j]-'a'<<' ';
                // if (a[i][j]-'0' > b[i][j]-'0'){
                //     b[i][j] = a[i][j];
                //     a[(n-1)-j][i] = a[i][j];
                // }
                // else if (b[i][j] > a[i][j]){
                //     a[i][j] = b[i][j];
                //     b[j][(n-1)-i] = b[i][j];
                // }
                if (f[i][j] == false){
                    ll maxi = a[i][j]-'0';
                    maxi = max(a[i][j]-'a',max(a[j][(n-1)-i]-'a',max(a[(n-1)-j][i]-'a',a[(n-1)-i][(n-1)-j]-'a')));
                    // cout<<maxi<<' ';
                    sum += abs(a[j][(n-1)-i]-'a'-maxi);
                    // cout<<sum<<' ';
                    sum += abs(a[(n-1)-j][i]-'a'-maxi);
                    sum += abs(a[(n-1)-i][(n-1)-j]-'a'-maxi);
                    sum += abs(a[i][j]-'a'-maxi);
                    f[j][(n-1)-i] = true;
                    f[(n-1)-j][i] = true;
                    f[(n-1)-i][(n-1)-j] = true;
                    f[i][j] = true;
                }
            }
        }

        cout<<sum<<endl;


    }
    return 0;
}