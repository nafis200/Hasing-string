// #include <bits/stdc++.h>
// using namespace std;
// const int N = 5005;
// int a[N];
// string s, t;
// int n;
// int dp[N][N];
// const int p = 137, mod = 1e9 + 7;
// const int p1 = 277, mod1 = 1e9 + 7;
// pair<int, int> pw[N], invf[N];
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
// int f(int l, int r)
// {
//     if (l == r)
//     {
//         return 1;
//     }
//     if(dp[l][r] != -1){
//         return dp[l][r];
//     }
//     int len = (r - l + 1);
//     if (S.get_hash(l, r) != T.get_hash(n - r - 1, n - l - 1))
//     {
//         return 0;
//     }
//     int ans = 1;
//     int mid = (l + r) / 2;
//     if (len % 2)
//     {
//         mid--;
//     }
//     ans = ans + f(l, mid);
//     return dp[l][r] =  ans;
// }
// int main()
// {
//     memset(a, 0, sizeof(a));
//     memset(dp, -1, sizeof(dp));
//     cin >> s;
//     t = s;
//     prec();
//     S.bulid(s);
//     reverse(t.begin(), t.end());
//     T.bulid(t);
//     n = (int)s.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {

//             a[f(i, j)]++;
//         }
//     }
//     for (int i = n - 1; i >= 0; i--)
//     {
//         a[i] = a[i + 1] + a[i];
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         cout << a[i] << " ";
//     }
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N];
int dp[N][N];
int par[N][N];
string s, t;
int n;
bool palindrome(int l, int r){
    if(l > r) return true;
    int &ans = par[l][r];
    if(ans != -1) return ans;
    ans = (s[l] == s[r]) and palindrome(l + 1, r - 1);
    return par[l][r] = ans;
}

int f(int l, int r)
{
    if (!palindrome(l, r))
    {
        return 0;
    }
    if (l == r)
    {
        return 1;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    int len = (r - l + 1);

    int ans = 1;
    int mid = (l + r) / 2;
    if (len % 2)
    {
        mid--;
    }
    ans = ans + f(l, mid);
    return dp[l][r] = ans;
}
int main()
{
    memset(a, 0, sizeof(a));
    memset(dp, -1, sizeof(dp));
    memset(par, -1, sizeof(par));
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    n = (int)s.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {

            a[f(i, j)]++;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        a[i] = a[i + 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
}