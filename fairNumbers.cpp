// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
bool checkNumber(ll &n)
{
    ll k = n;
    // cout<<k<<" ";
    while (k!=0)
    {
        ll dig = k%10;
        if (dig!=0 && n%dig != 0)
            return false;
        k /= 10;    
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
        ll p;
        ll c= 8;
        while (1)
        {
            // cout<<n<<" ";
            bool check = checkNumber(n);
            // cout<<check<<" ";
            if (check){
                p = n;
                break;
            }
            else{
                n++;
            }
        }
        cout<<p<<endl;

    }
    return 0;
}

/*
1
288
1234568040
1000000000000000000

*/