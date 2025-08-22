#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int length = n * k;
    string s;
    cin >> s;
    s = s + s;

    map<string,int>mp;
    vector<int>ans;

    for(int j = 0; j < k; j++){
        for(int i = j; i < length + j; i+=k){
            string t = s.substr(i, k);
            if(mp.find(t) == mp.end()){
                mp[t] = i + 1;
            }
        }
    }


}