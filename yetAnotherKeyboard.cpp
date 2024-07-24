// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// void checkCapital(ll i, vector<ll> &A)
// {
//     if (A.size())
//     {
//         for (auto it=A.end()-1; it>=A.begin(); it--)
//         {
//             if (*it < i)
//             {
//                 A.erase(it);
//                 return;
//             }
//         }
//     }
// }
// int main() {
//     ll t;
//     cin>>t;
//     while (t--)
//     {
//         string s;
//         cin>>s;
//         vector<ll>a;
//         vector<ll>A;
//         vector<ll>b;
//         vector<ll>B;
//         for (ll i=0; i<s.size(); i++)
//         {
//             if (s[i]=='b')
//                 b.push_back(i);
//             else if (s[i]=='B')
//                 B.push_back(i);
//             else if (s[i]-'A' <= 26)
//                 A.push_back(i); 
//             else if (s[i]-'a' <= 26)
//                 a.push_back(i);               
//         }
//         // for (auto i:a)
//         //     cout<<i<<" ";
//         // cout<<endl;    
//         // for (auto i:A)
//             // cout<<i<<" ";  
//         for (ll i=0; i<B.size(); i++)
//         {
//             checkCapital(B[i], A);
//         }    
//         for (ll i=0; i<b.size(); i++)
//         {
//             checkCapital(b[i],a);
//         }
//         // for (auto i:a)
//         //     cout<<i<<" ";
//         // cout<<endl;    
//         // for (auto i:A)
//         //     cout<<i<<" ";    
//         vector<ll>p;
//         for (ll i=0; i<a.size(); i++)
//             p.push_back(a[i]);
//         for (ll i=0; i<A.size(); i++)
//             p.push_back(A[i]);
//         string si;
//         sort(p.begin(),p.end());
//         for (ll i=0; i<p.size(); i++)
//         {
//             si.push_back(s[p[i]]);
//         }        
//         cout<<si<<endl;

//     }
//     return 0;
// }


// /*
// ity
// YetnotherrokenKeoard
// le
// Imprle
// revile

// usyasaeeinaedofloominglossoms
// CDARIES
// codeforces
// es

// helaoard

// */





// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    ll t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        stack<ll>a;
        stack<ll>A;
        for (ll i=0; i<s.size(); i++)
        {
            if (s[i]=='b' && a.size())
                a.pop();
            else if (s[i]=='B' && A.size())
                A.pop();
            else if (s[i]-'A' <= 25 && s[i]!='B' && s[i]!='b') 
                A.push(i);
            else if (s[i]-'a' <= 25 && s[i]!='b' && s[i]!='B')
                a.push(i);           
        }
        vector<ll>p;
        // cout<<a.size()<<" ";
        
        while (!a.empty()){
            // cout<<a.top()<<" ";
            p.push_back(a.top());
            a.pop();
        }
        while (!A.empty()){
            // cout<<A.top()<<" ";
            p.push_back(A.top());
            A.pop();
        }
        // for (auto i:p)
        //     cout<<i<<" ";
        string si;
        sort(p.begin(),p.end());
        
        // cout<<endl;    
        // for (auto i:A)
        //     cout<<i<<" ";
        for (ll i=0; i<p.size(); i++)
        {
            si.push_back(s[p[i]]);
        }        
        cout<<si<<endl;
   }
    return 0;
}