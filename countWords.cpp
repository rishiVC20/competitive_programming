#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int count = 0;
    int i = 0;
    while (i<s.size()){
        if (s[i] == " "){
            count++;
        }
        i++;
    }
    int p = count+1;
    cout<<p;
    return 0;
}