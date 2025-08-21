#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool f(int len){
     for(int i = 1; i + len - 1 < n - 1; i++){
          if(s.substr(i, len) == s.substr(0,len)){
             return true;
          }
     }
     return false;
}

int main(){
  
    cin >> s;
    n = (int)s.size();
    vector<int>v;
    for(int len = 1; len <= n - 1; len++){
         if(s.substr(0, len) == s.substr(n - len, len)){
            v.push_back(len);
         }
    }
    int ans = 0;
    int l = 0, h = v.size() - 1;
    while(l <= h){
        int mid = (l + h) / 2;
        if(f(v[mid])){
            ans = v[mid];
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    if(ans){
        cout << s.substr(0, ans) << "\n";
    }
    else{
        cout << "Just a legend\n";
    }
    
}
