// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n);
        for (ll i =0; i<n; i++)
            cin>>a[i];
        ll x=0, y=n-1;
        vector<ll>arr;
        while (x<=y){
            if (x==y){
                arr.push_back(a[x]);
                break;
            }   
            arr.push_back(a[x]);
            arr.push_back(a[y]);
            x++;
            y--;
        }    
        ll i = 0;
        ll count = 0;
        bool flag = true;
        
        // while (k>0)
        // {
            
        //     if (arr[i] <= (k/2)){
        //         count++;
                
        //     }
        //     else if (!flag)
        //         break;
        //     else
        //         flag = false;        
            
        //     k -= arr[i]/2;
        //     i++;
        //     if (i==n)
        //         break;
        // }
        ll c = 0;
        ll i=0, j=1;
        while (k > 0)
        {
            if (c%2==0 && i<n)
            {
                arr[i] -= 1;
                
                if (arr[i]==0){
                    i+=2;
                    count++;
                }
            }
            else if (c%2!=0 && j<n)
            {
                arr[j] -= 1;
                if (arr[j]==0){
                    j+=2;
                    count++;
                }
            }
            k--, c++;
            if (i>=n && j>=n)
                break;
        }
           
        cout<<count<<endl;

    }
    return 0;
}