// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 

void changeArray(vector<ll> &arr, ll p)
{
    // for (ll i=0; i<arr.size(); i++)
    //     arr[i] = p;
    ll i=0, j=arr.size()-1;
    while (i<=j){
        arr[i] = p;
        arr[j] = p;
        i++;
        j--;
    }
}
int main() {
    ll n,q;
    cin>>n>>q;
    vector<ll>arr(n);
    ll sum = 0;
    for (ll i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }
    bool f = false;
    ll kk;
    unordered_map<ll,ll>ss;
    for (ll i=0; i<q; i++)
    {
        //  for (ll i=0; i<n; i++)
        //             cout<<arr[i]<<" ";
        ll x; cin>>x;
        if (x == 1)
        {
            ll l,r;
            cin>>l>>r;
            if (f){
                // sum -= kk;
                // sum += r;
                // cout<<sum<<endl;
                if (ss.find(l-1)!=ss.end())
                {
                    sum -= ss[l-1];
                    sum += r;
                    ss[l-1] = r;
                }
                else{
                    sum -= kk;
                    sum += r;
                    ss[l-1] = r;
                }

            }
            else{
                ll ph = arr[l-1];
                // for (ll i=0; i<n; i++)
                //     cout<<arr[i]<<" ";
                arr[l-1] = r;
                // cout<<sum(arr)<<endl;
                // sum = sum - ph + r;
                sum -= ph;
                sum += r;
                // cout<<sum<<endl;
            }
            cout<<sum<<endl;
            
        }
        else{
            ll p;
            cin>>p;
            // changeArray(arr,p);
            f = true;
            kk = p;
            // for (ll i=0; i<n; i++)
            //     cout<<arr[i]<<" ";
            sum = p*n;
            ss.clear();
            cout<<p*n<<endl;
            
        }

        // cout<<sum<<endl;
        // cout<<endl;
    }
    return 0;
}