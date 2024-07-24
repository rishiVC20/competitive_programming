// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b;
        cin>>a>>b;
        ll count = 0;
        if (a==b){
            cout<<count<<endl;
            continue;
        }       
        else if (a<b){
            while (a<b)
            {
                count++;
                if (a*8 <= b)
                    a *= 8;
                else if (a*4 <= b)
                    a *= 4;
                else if (a*2 <= b)
                    a *= 2;
                else{
                    break;
                }            
            }
            if (a!=b){
                cout<<-1<<endl;
            }
            else{
                cout<<count<<endl;
            }
        }
        else{
            while (a > b)
            {
                count++;
                if (a%8==0 && a/8>=b)
                    a /= 8;
                else if (a%4==0 && a/4>=b)
                    a/= 4  ;
                else if (a%2==0 && a/2>=b)
                    a/=2;
                else{
                    break;
                }          
            }
            if (a!=b)
                cout<<-1<<endl;
            else 
                cout<<count<<endl;    
        }
    }
    return 0;
}