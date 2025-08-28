// TLE TEST case 13

// #include <bits/stdc++.h>
// using namespace std;
// const int p = 137, mod = 1e9 + 7;
// const int p1 = 277, mod1 = 1e9 + 7;
// const int N = 1e6 + 9;
// pair<int, int> pw[N], invf[N];
// int n;
// int power(long long n, long long k, int mod)
// {
//     int ans = 1 % mod;
//     n = n % mod;
//     if (n < 0)
//     {
//         n += mod;
//     }
//     while (k)
//     {
//         if (k & 1)
//         {
//             ans = (long long)ans * n % mod;
//         }
//         n = (long long)n * n % mod;
//         k >>= 1;
//     }
//     return ans;
// }
// void prec()
// {
//     // 0 * p^0 + 1 * p^1......
//     pw[0] = {1, 1};
//     for (int i = 1; i < N; i++)
//     {
//         pw[i].first = 1LL * pw[i - 1].first * p % mod;
//         pw[i].second = 1LL * pw[i - 1].second * p1 % mod1;
//     }
//     int ip1 = power(p, mod - 2, mod);
//     int ip2 = power(p1, mod1 - 2, mod1);
//     invf[0] = {1, 1};
//     for (int i = 1; i < N; i++)
//     {
//         invf[i].first = 1LL * invf[i - 1].first * ip1 % mod;
//         invf[i].second = 1LL * invf[i - 1].second * ip2 % mod1;
//     }
// }

// struct Node
// {
//     pair<int, int> pref[N];
//     void bulid(string s)
//     {
//         int n = s.size();
//         for (int i = 0; i < n; i++)
//         {
//             pref[i].first = 1LL * s[i] * pw[i].first % mod;
//             if (i)
//             {
//                 pref[i].first = (pref[i].first + pref[i - 1].first) % mod;
//             }
//             pref[i].second = 1LL * s[i] * pw[i].second % mod1;
//             if (i)
//             {
//                 pref[i].second = (pref[i].second + pref[i - 1].second) % mod1;
//             }
//         }
//     }
//     pair<int, int> get_hash(int i, int j)
//     {
//         assert(i <= j);
//         pair<int, int> hs({0, 0});
//         hs.first = pref[j].first;
//         if (i)
//             hs.first = (hs.first - pref[i - 1].first + mod) % mod;
//         hs.first = 1LL * hs.first * invf[i].first % mod;
//         hs.second = pref[j].second;
//         if (i)
//             hs.second = (hs.second - pref[i - 1].second + mod1) % mod1;
//         hs.second = 1LL * hs.second * invf[i].second % mod1;
//         return hs;
//     }
// } S, T;

// int f(int length)
// {
//     for (int i = 0; i + length - 1 < n; i++)
//     {
//         int j = i + length - 1;
//         if (S.get_hash(i, j) == T.get_hash(n - j - 1, n - i - 1))
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// int main()
// {
//     string s;
//     cin >> s;
//     string t = s;
//     reverse(t.begin(), t.end());
//     int i = 0;
//     int length = 0;
//     prec();
//     S.bulid(s);
//     T.bulid(t);
//     n = s.size();
//     int ans = 0;
//     for (int l = 1; l <= n; l++)
//     {
//         ans = f(l);
//         if (ans != -1)
//         {
//             i = ans;
//             length = l;
//         }
//     }
//     cout << s.substr(i, length) << "\n";
// }


#include<bits/stdc++.h> 
using namespace std; 
const int p = 137, mod = 1e9 + 7; 
const int p1 = 277, mod1 = 1e9 + 7; 
const int N = 1e6 + 9; 
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
int n; 
bool is_palindrome(int i, int j){ 
      if( S.get_hash(i, j) == R.get_hash(n - j - 1, n - i - 1)) 
      return true; 
      return false; 
} 
int odd[N],even[N]; 
//odd lenght er khetre palindrome kina chcek it 
    // 0 1 2 3 4 5 
    // a b a b a c 
    // c a b a b a 
    // i == n - i - 1 
    // fixed center and go both side 
    // let 4 center l = 3 and r = 5 - 4 - 1 = 0 
int32_t main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    prec(); 
    string s; cin >> s; 
    string r = s; 
    n = s.size(); 
    reverse(r.begin(),r.end()); 
    S.bulid(s); 
    R.bulid(r); 
    for(int center = 0; center < n; center++){ 
        int l = 0, r = min(center, n - center - 1), ans = 0; 
        while(l <= r){ 
            int mid = (l + r) >> 1; 
            if(is_palindrome(center - mid, center + mid)){ 
                ans = mid; 
                l = mid + 1; 
            } 
            else{ 
                r = mid - 1; 
            } 
        } 
        odd[center] = ans; 
    } 
    //acbbca 
    // ei khane 2nd b center and 1 b duitai center but 
    // ami 2nd b niye kaj korbo 
    for(int center =  0; center < n; center++){ 
        int l = 0, r = min(center - 1, n - center - 1); 
        int ans = -1; 
        while(l <= r){ 
             int mid = (l + r) >> 1; 
            if(is_palindrome(center - mid - 1, center + mid)){ 
                ans = mid; 
                l = mid + 1; 
            } 
            else{ 
                r = mid - 1; 
            } 
        } 
        even[center] = ans; 
     } 
  int mx_longest = 0, ans_l, ans_r; 
  for(int i = 0; i < n; i++){ 
      int len = 2 * odd[i] + 1; 
      if(len > mx_longest){ 
        mx_longest = len; 
        ans_l = i - odd[i]; 
        ans_r = i + odd[i]; 
      } 
  } 
  for(int i = 0; i < n; i++){ 
     int len = 2 * (even[i] + 1); 
         if(len > mx_longest){ 
        mx_longest = len; 
        ans_l = i - even[i] - 1; 
        ans_r = i + even[i]; 
      } 
  } 
  cout << s.substr(ans_l, ans_r - ans_l + 1) << "\n"; 
} 