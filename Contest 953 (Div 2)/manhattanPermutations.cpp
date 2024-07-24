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

ll calculate(vi &a)
{
    ll sum = 0;
    ll n = a.size();
    for (ll i=0; i<n; i++)
    {
        sum += abs(a[i]-i);
    }

    return sum;
}
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vi a;
        a.pb(0);
        for (ll i=1; i<=n; i++)
            a.pb(i);

        ll maxSum = 0;
        ll q = 1;
        for (ll i=n; i>=1; i--){
            maxSum += abs(a[i]-q);
            q++;
            // cout<<maxSum<<' ';
        }
        if (k > maxSum || k%2==1){
            NO;
            continue;
        }
        if (k==maxSum){
            YES;
            for (ll i=n; i>=1; i--)
                cout<<i<<' ';
            cout<<endl;    
            continue;    
        }
        // cout<<'h'<<' ';
        if (k==0){
            YES;
            for (ll i=1; i<=n; i++)
                cout<<a[i]<<' ';
            cout<<endl;
            continue;
        }    
        
        // bool c = true;
        // ll sum = 0; 
        // ll z = -1;
        // while (sum < k)
        // {
        //     z = -1;
        //     sum = calculate(a);
        //     if (sum==k)
        //         break;
        //     if (sum > k){
        //         c = false;
        //         break;
        //     }
        //     for (ll i=n-1; i>=1; i--){
        //         if (a[i] < a[i+1]){
        //             z = i;
        //             break;
        //         }
        //     }
        //     if (z==-1){
        //         c = false;
        //         break;
        //     }
        //     reverse(a.begin()+z+1,a.end());
        //     for(int i = n; i>z; i--){
        //         if(a[i]>a[z]){
        //             swap(a[i], a[z]);
        //             break;
        //         }
        //     }   
        //     reverse(a.begin()+z+1,a.end());
        // }

        // if (!c){
        //     cout<<"NO"<<endl;
        //     continue;
        // }

        // cout<<"YES"<<endl;
        // for (ll i=1; i<=n; i++)
        //     cout<<a[i]<<' ';
        // cout<<endl;    

        ll tar = n-1;
        k /= 2;
        for (ll i=1; i<=n; i++)
        {
            if (k<=tar){
                swap(a[i],a[i+k]);
                k = 0;
                break;
            }
            swap(a[i],a[i+tar]);
            k -= tar;
            tar -= 2;
            if (tar <= 0)
                break;
        }

        if (k)
            NO;
        else{
            YES;
            for (ll i=1; i<=n; i++)
                cout<<a[i]<<' ';
            cout<<endl;    
        }    
    }
    return 0;
}