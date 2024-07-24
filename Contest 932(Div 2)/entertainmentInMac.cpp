// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
bool seeReverse(string s)
{
    ll i=0, j=s.size()-1;
    while (i<j)
    {
        if ((s[i]) < (s[j])){
            return true;
            
        }
            
        else if ((s[i]) > (s[j])) {  
            return false; 
        }
        i++;
        j--;

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
            string s;
            cin>>s;
            string p=s;
            // bool see = seeReverse(s);
            // cout<<see<<endl;
            std::reverse(p.begin(),p.end());
            bool see = seeReverse(s);
            // cout<<see<<endl;
            if (see)
                cout<<s<<endl;
            else if (!see)
                cout<<p+s<<endl;            
        
    }
    return 0;
}

/*
cpm
birggrib
kupitimilablodarbuz
arabypaccapybara
abacaba

*/