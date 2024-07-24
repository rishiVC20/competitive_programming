// // Rishikesh Chaudhari
// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long 
// int main() {
//     string s;
//     cin>>s;
//     int n=s.size();
//     if (s=="wjmzbmr")
//         cout<<"CHAT WITH HER!"<<endl;
//     else if (n%2==0)
//         cout<<"CHAT WITH HER!"<<endl;
//     else
//         cout<<"IGNORE HIM!"<<endl;
//     return 0;
// }

// Rishikesh Chaudhari
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int>arr(26,0);
    for (int i=0; i<n; i++){
        int ans=s[i]-'a';
        arr[ans]++;
    }
    int count=0;
    for (int i=0; i<26; i++){
        if (arr[i] != 0){
            count++;
        }
    }

    if (count%2==0)
        cout<<"CHAT WITH HER!"<<endl;
    else
        cout<<"IGNORE HIM!"<<endl;    
    return 0;
}

// https://codeforces.com/problemset/problem/236/A