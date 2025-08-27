// acab + acab
#include<bits/stdc++.h>
using namespace std;
const int p = 137, mod = 1e9 + 7; 
const int p1 = 277, mod1 = 1e9 + 7; 
const int N = 2e6 + 9; 
pair<int,int>pw[N],invf[N]; 
string s;
int power(long long n, long long k, int mod){ 
    int ans = 1 % mod; 
    n = n % mod; 
    if(n < 0){ 
        n += mod; 
    } 
    while(k){ 
        if(k & 1){ 
            ans = (long long) ans * n % mod; 
        } 
        n = (long long) n * n % mod; 
        k >>= 1; 
    } 
    return ans; 
} 
void prec(){ 
    // 0 * p^0 + 1 * p^1...... 
    pw[0] = {1, 1}; 
    for(int i = 1; i < N; i++){ 
        pw[i].first = 1LL * pw[i - 1].first * p % mod; 
        pw[i].second = 1LL * pw[i - 1].second * p1 % mod1; 
    } 
    int ip1 = power(p, mod - 2, mod); 
    int ip2 = power(p1, mod1 - 2, mod1); 
    invf[0] = {1, 1}; 
    for(int i = 1; i < N; i++){ 
        invf[i].first = 1LL * invf[i - 1].first * ip1 % mod;   
        invf[i].second = 1LL * invf[i - 1].second * ip2 % mod1; 
    } 
} 
pair<int,int> string_hash(string s){ 
    int n = s.size(); 
    pair<int,int>hs({0,0}); 
    for(int i = 0; i < n; i++){ 
        hs.first += 1LL * s[i] * pw[i].first % mod; 
        hs.first %=mod; 
        hs.second += 1LL * s[i] * pw[i].second % mod1; 
        hs.second %=mod1; 
    } 
    return hs; 
} 
pair<int, int>pref[N]; 
void bulid(string s){ 
    int n = s.size(); 
    for(int i = 0; i < n; i++){ 
        pref[i].first = 1LL * s[i] * pw[i].first % mod; 
        if(i){ 
            pref[i].first = (pref[i].first + pref[i - 1].first) % mod; 
        } 
        pref[i].second = 1LL * s[i] * pw[i].second % mod1; 
         if(i){ 
            pref[i].second = (pref[i].second + pref[i - 1].second) % mod1; 
        } 
    } 
} 
pair<int,int>get_hash(int i, int j){ 
    assert(i <= j); 
    pair<int,int>hs({0, 0}); 
    hs.first = pref[j].first; 
    if(i) 
    hs.first = (hs.first - pref[i - 1].first + mod) % mod; 
    hs.first = 1LL * hs.first * invf[i].first % mod; 
    hs.second = pref[j].second; 
    if(i) 
    hs.second = (hs.second - pref[i - 1].second + mod1) % mod1; 
    hs.second = 1LL * hs.second * invf[i].second % mod1; 
    return hs; 
} 

int lcp(int i, int j, int x, int y){
    int l = 1, r = j - i + 1;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;

}

int compare(int i, int j, int x, int y){
    int len = lcp(i, j, x, y);
    int len1 = j - i  + 1;
    if(len == len1){
        return 0;
    }
    if(s[i + len] < s[x + len]){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    cin >> s;
    int n = (int)s.size();
    s += s;
    prec();
    bulid(s);
    int mni = 0, mnj = n - 1;
    

    for(int i = 0; i + n - 1 < (int)s.size(); i++){
         if(compare(mni, mnj, i, i + n - 1) == 1){
            mni = i;
            mnj = i + n - 1;
         }
    }
    cout << s.substr(mni, n) << "\n";

}


