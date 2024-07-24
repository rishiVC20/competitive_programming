    // Rishikesh Chaudhari
    #include<bits/stdc++.h>
    using namespace std;

    #define ll long long 
    ll solve(ll &h, vector<ll> &arr)
    {
        ll cnt = 0;
        for (ll i=0; i<arr.size(); i++){
            if (h > arr[i])
                cnt++;
            else
                break;
        }
        return cnt;        

    }
    int main() {
        ll t;
        cin>>t;
        while (t--)
        {
            ll n,w;
            cin>>n>>w;
            vector<ll>arr;
            for (ll i=0; i<n; i++){
                ll x;
                cin>>x;
                arr.push_back(x);
            }       
            bool f = true;
            sort(arr.begin(),arr.end());
            ll h = arr[0];
            // while (w > 0)
            // {
            //     h++;
            //     // ll p = solve(h,arr);
            //     ll p = count_if(arr.begin(),arr.end(),[h](ll num){
            //         return num > h;
            //     });
            //     w -= p;
            //     if (w < 0){
            //         f = false;
            //         break;
            //     }
            // }
            // if (!f){
            //     h--;
            //     cout<<h<<endl;
            // }
            // else{
            //     cout<<h<<endl;
            // }

            vector<ll>c;
            for (ll i=0; i<n-1; i++)
            {
                c.push_back((i+1)*(arr[i+1]-arr[i]));
            }
            // for (auto i:c)
            //     cout<<i<<" ";
            arr.push_back(INT_MAX);
            for (ll i=1; i<=n; i++)
            {
                ll p = i*(arr[i]-arr[i-1]);
                if (w-p <= 0){
                    ll m = w/i;
                    cout<<arr[i-1]+m<<endl;
                    break;
                }
                w -= p;

            }
            // if (!f){
            //     cout<<--h<<endl;
            // }
            // else{
            //     cout<<h<<endl;
            // }

        }
        return 0;
    }