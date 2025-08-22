// So prefix sum not possible this problem
// try dp or segment tree range query

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5005;
// int a[N];
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     string s, t;
//     cin >> s;
//     t = s;
//     int n = (int)s.size();
//     memset(a, 0, sizeof(a));
//     reverse(t.begin(), t.end());
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             int len = (j - i) + 1;

//             if (s.substr(i, len) == t.substr(n - j - 1, len))
//             {
//                 a[i]++;
//             }
//         }
//     }
//     // for (int i = 1; i < n; i++)
//     // {
//     //     a[i] = a[i - 1] + a[i];
//     // }

//     for(int i = 0; i < n; i++){
//         cout << a[i] << "\n";
//     }

//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int l, r;
//         cin >> l >> r;
//         r--;
//         l--;
//         int ans = a[r];
//         if (l != 0)
//         {
//             ans = ans - a[l];
//         }
//         cout << ans << "\n";
//     }
// }

// Try to dp

//  aaa     (1, 2), (2, 3) - (2) karon 2 2times count hoyeche
//  a  a

//  1 + 1 + 1
//  a = 1,   a = 1  aa = 1

// case 2
//  aaa
//  aaa = 3
//  aa = 2 (1,2)
//  aa = 2 (2,3)
// total = 7 but total is 6 (2,2) extra add

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5005;
// int dp[5005][5005];
// bool par[5005][5005];
// string s;

// bool palindrome(int l, int r)
// {
//     if (l > r)
//     {
//         return true;
//     }
//     if (par[l][r])
//     {
//         return par[l][r];
//     }
//     par[l][r] = palindrome(l + 1, r - 1) && (s[l] == s[r]);
//     return par[l][r];
// }

// int f(int l, int r)
// {
//     if (l > r)
//     {
//         return 0;
//     }
//     if (dp[l][r] != -1)
//     {
//         return dp[l][r];
//     }
//     return dp[l][r] = palindrome(l, r) + f(l, r - 1) + f(l + 1, r) - f(l + 1, r - 1);
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     memset(dp, -1, sizeof(dp));
//     memset(par, false, sizeof(par));
//     cin >> s;
//     int q;
//     cin >> q;
//     while (q--)
//     {
//         int l, r;
//         cin >> l >> r;
//         l--;
//         r--;
//         cout << f(l, r) << "\n";
//     }
// }



#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int pal[N][N],dp[N][N];
const int p = 137, mod = 1e9 + 7;
const int p1 = 277, mod1 = 1e9 + 7;
pair<int,int>pw[N],invf[N];
string s,r;
int n;
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
int palindrome(int l, int r){
    return S.get_hash(l, r) == R.get_hash(n - r - 1, n - l - 1);
    
}
int f(int l, int r){
    if(l > r)
    return 0;
    int &ans = dp[l][r];
    if(ans != -1)
    return ans;
    return ans = palindrome(l, r) + f(l + 1, r) + f(l , r - 1) - f(l + 1, r - 1);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prec();
    memset(dp,-1,sizeof(dp));
    memset(pal,-1,sizeof(pal));
    cin >> s;
    r = s;
    n = s.size();
    reverse(r.begin(),r.end());
    S.bulid(s);
    R.bulid(r);
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        l--; r--;
        cout << f(l, r) << "\n";
    }
}
