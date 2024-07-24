#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
        cin>>n;
        for (int i=1; i<=20; i++)
        {
            for (int j=1;j<=20;j++){
                if (i+j>=n || i==j)
                    continue;
                int k = n-i-j;
                if (k==i || k==j)
                    continue;
                if (i%3==0 || j%3==0 || k%3==0)
                    continue;
                cout<<"YES"<<endl;
                cout<<i<<" "<<j<<" "<<k<<endl;
                return ;            
            }
        }
        cout<<"NO"<<endl; 
}
int main() {
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}