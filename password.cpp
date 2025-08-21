#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int>v;
    for(int len = 1; len <= n / 2; len++){
         if(s.substr(0, len) == s.substr(n - len, len)){
            v.push_back(len);
         }
    }
    
}
