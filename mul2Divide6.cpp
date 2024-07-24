// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        ll cnt = 0;
        bool flag = true;
        while (n > 1)
        {
            if (n%6!=0 && n%3!=0){
                flag = false;
                break;
            }
            if (n%6==0){
                while (n%6==0){
                    cnt++;
                    n /= 6;
                }
            }
            if (n%3==0){
                while (n%3==0){
                    cnt++;
                    n *= 2;
                    if (n%6==0)
                        break;
                }
            }

        }      
        if (!flag)
            cout<<-1<<endl;
        else    
            cout<<cnt<<endl; 
    }
    return 0;
}