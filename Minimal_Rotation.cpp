#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int n = (int)s.size();
    s = s + s;

    string t = s;

    for(int i = 0; i + n - 1 < (int)s.size(); i++){
         string x;
         x = s.substr(i, n);
         t = min(x, t);
    }
    cout << t << "\n";
}