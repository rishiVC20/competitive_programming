// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
bool arr[90000001];
vector<ll>prime;
void sieve()
{
    ll maxN = 90000000;
    arr[0] = arr[1] = true;
    for (ll i=2; i*i < maxN; i++)
    {
        if (!arr[i])
        {
            for (ll j=i*i; j<=maxN; j+=i)
                arr[j] = true;
        }
    }
    for (ll i=2; i<=maxN; i++)
    {
        if (!arr[i])
            prime.push_back(i);
    }
}
int main() {
    ll t;
    cin>>t;
    sieve();
    while (t--)
    {
        
        ll q;
        cin>>q;
        cout<<prime[q-1]<<endl;
    }
    return 0;
}