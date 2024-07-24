#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXN = 1000001;
bool prime[MAXN];

vector<ll> prefix;

void preprocess() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int p = 2; p <= sqrt(MAXN); p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAXN; i += p)
                prime[i] = false;
        }
    }
    
    for(ll i = 2; i <= MAXN; i++)
        if(prime[i])    
            prefix.push_back(i);
            
    for(ll i = 1; i < prefix.size(); i++) {
        prefix[i] = prefix[i] + prefix[i-1];
    }
    
}

void solve() {
    ll k;
    cin >> k;

    // Find the smallest prime factor of k
    ll index = 0;
    ll smallestPrimeFactor = 1;
    for (ll p = 2; p <= k; p++) {
        
        if (prime[p]) 
        {
            index++;
            smallestPrimeFactor = p;
            if(k % p == 0)  break;
        }
    }

    cout << k * prefix[index-1] << "\n";
}

int main() {
    preprocess();

    ll t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}