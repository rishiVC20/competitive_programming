#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
        cin>>n;
        vector <int> a(n);
        for (int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        a[0]++;
        int pro = 1;
        for (int i=0; i<n; i++){
            pro *= a[i];
        }
        cout<<pro<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
return 0;
}