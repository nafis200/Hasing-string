#include<bits/stdc++.h>
using namespace std;
const int N = 5e6 + 9;
int dp[N];
bool pal[N];
string s, r;
int n;
const int p = 137, mod = 1e9 + 7;
const int p1 = 277, mod1 = 1e9 + 7;
pair<int,int>pw[N],invf[N];
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
struct hasing{
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
}S,R;
bool palindrome(int l, int r){
    return (S.get_hash(l,r) == R.get_hash(n - r -1, n - l - 1));
}
int f(int i){
     if(!pal[i])
     return 0;
     if(i == 0)
     return 1;
     int &ans = dp[i];
     if(ans != -1)
     return ans;
     int end = (i) / 2;
     if((i + 1) % 2 == 1){
        end--;
     } 
     ans = 1;
     if(pal[end])
     ans += f(end);
     return ans;
}
int cnt[N];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    memset(dp,-1,sizeof(dp));
    cin >> s;
    S.bulid(s);
    r = s;
    reverse(r.begin(),r.end());
    R.bulid(r);
     n = s.size();
     for(int i = 0; i < n; i++){
        pal[i] = palindrome(0, i);
     }
    long long sum = 0;
    for(int i = 0; i < n; i++){
         sum += f(i);
    }
   cout << sum << "\n";
}
 