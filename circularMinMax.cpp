#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin>>t;
    while (t--){
        ll n;
        cin>>n;
        vector<int>store(n);
        for (int i=0; i<n; i++){
            cin>>store[i];
        }
        sort(store.begin(),store.end());
        int k=0;
        int l=n/2;
        if (n%2){
            cout<<"NO"<<endl;
        }
        else{
            vector<int>result(n);
            for (int i=0; i<n; i++){
                if (i%2==0)
                    result[i]=store[k++];
                else    
                    result[i]=store[l++];    
            }
            int flag = 0;
            for (int i=1; i<n-1; i++){
                if (result[i]>result[i+1] && result[i]>result[i-1]){
                    flag++;
                    continue;
                    
                }
                else if (result[i]<result[i+1] && result[i]<result[i-1]){
                    flag++;
                    continue;
                    
                }
                else    
                    break;
                // flag++;            
            }
            if (flag==n-2){
                cout<<"YES"<<endl;
                for (int i=0; i<n; i++){
                    cout<<result[i]<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}