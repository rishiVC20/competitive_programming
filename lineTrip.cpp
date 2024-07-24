#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>arr(n+2);
        for (int i=1; i<=n;i++){
            cin>>arr[i];
        }
        arr[0] = 0;
        arr[n+1] = x;
        int ans = INT_MIN;
        for (int i=0; i<n; i++)
        {
            int sub = arr[i+1]-arr[i];
            ans = max(ans,sub);
        }
        int newans = 2*(arr[n+1]-arr[n]);
        ans = max(ans,newans);
        cout<<ans<<endl;
    }
    return 0;
}