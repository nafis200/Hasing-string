#include <bits/stdc++.h>
using namespace std;
const int p = 137, mod = 1e9 + 7;
const int p1 = 277, mod1 = 1e9 + 7;
const int N = 1500 + 20;
pair<int, int> pw[N], invf[N];
int power(long long n, long long k, int mod)
{
    int ans = 1 % mod;
    n = n % mod;
    if (n < 0)
    {
        n += mod;
    }
    while (k)
    {
        if (k & 1)
        {
            ans = (long long)ans * n % mod;
        }
        n = (long long)n * n % mod;
        k >>= 1;
    }
    return ans;
}
void prec()
{
    // 0 * p^0 + 1 * p^1......
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        pw[i].first = 1LL * pw[i - 1].first * p % mod;
        pw[i].second = 1LL * pw[i - 1].second * p1 % mod1;
    }
    int ip1 = power(p, mod - 2, mod);
    int ip2 = power(p1, mod1 - 2, mod1);
    invf[0] = {1, 1};
    for (int i = 1; i < N; i++)
    {
        invf[i].first = 1LL * invf[i - 1].first * ip1 % mod;
        invf[i].second = 1LL * invf[i - 1].second * ip2 % mod1;
    }
}
pair<int, int> pref[N];
void bulid(string s)
{
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        pref[i].first = 1LL * s[i] * pw[i].first % mod;
        if (i)
        {
            pref[i].first = (pref[i].first + pref[i - 1].first) % mod;
        }
        pref[i].second = 1LL * s[i] * pw[i].second % mod1;
        if (i)
        {
            pref[i].second = (pref[i].second + pref[i - 1].second) % mod1;
        }
    }
}
pair<int, int> get_hash(int i, int j)
{
    assert(i <= j);
    pair<int, int> hs({0, 0});
    hs.first = pref[j].first;
    if (i)
        hs.first = (hs.first - pref[i - 1].first + mod) % mod;
    hs.first = 1LL * hs.first * invf[i].first % mod;
    hs.second = pref[j].second;
    if (i)
        hs.second = (hs.second - pref[i - 1].second + mod1) % mod1;
    hs.second = 1LL * hs.second * invf[i].second % mod1;
    return hs;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    string p;
    cin >> p;
    int k;
    cin >> k;
    int a[27];
    map<char, int> mp;
    prec();
    bulid(s);
    for (int i = 0; i < 26; i++)
    {
        a[i] = p[i] - '0';
    }
    int n = (int)s.size();
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            char x = s[j];
            if (a[x - 'a'] == 0)
            {
                cnt++;
                if (cnt > k)
                {
                    break;
                }
            }
            st.insert(get_hash(i, j));
        }
    }
    cout << st.size() << "\n";
}