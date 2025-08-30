#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
int pref[6][N];
string b[6];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<char>p({'a','b','c'});
    int n, q; cin >> n >> q;
    string s; cin >> s;
    int id = 0;
    do{
          b[id].resize(n);
          for(int i = 0; i < n; i++){
            b[id][i] = p[i % 3];
          }
          id++;
    }while(next_permutation(p.begin(),p.end()));

    for(int id = 0; id < 6; id++){
        for(int i = 0; i < n; i++){
            pref[id][i] = s[i] != b[id][i];
            if(i){
                pref[id][i] += pref[id][i- 1];
            }
          }
    }

    while(q--){
        int l, r; cin >> l >> r;
        --l; --r;
        int ans = INT_MAX;
        for(int id = 0; id < 6; id++){
            int ops = 0;
            ops = pref[id][r] - (l ? pref[id][l - 1] : 0);
            ans = min(ans, ops);
        }
        cout << ans << "\n";
    }
  
}

// hellow 