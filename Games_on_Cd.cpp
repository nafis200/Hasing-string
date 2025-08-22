// my aapproch wrong
// test case aabbccdd

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, k;
//     cin >> n >> k;
//     int length = n * k;
//     string s;
//     cin >> s;
//     s = s + s;

//     map<string,int>mp;

//     for(int j = 0; j < k; j++){
//         for(int i = j; i < length + j; i+=k){
//             string t = s.substr(i, k);
//             if(mp.find(t) == mp.end()){
//                 mp[t] = i + 1;
//             }
//         }
//     }

//     int g;
//     cin >> g;
//     vector<int>ans;
//     while(g--){
//         string q;
//         cin >> q;
//         if(mp.find(q) != mp.end()){
//             ans.push_back(mp[q]);
//             mp.erase(q);
//         }
//     }
//     if(ans.size() == n){
//         cout << "YES\n";
//         for(auto it : ans){
//             cout << it << " ";
//         }
//     }
//     else{
//         cout << "NO\n";
//     }

// }

// O(n * k * (k + log n))

// while n = 10 k = 1e5 vice versa

// n = 10^ 5 and k = 10 test case easily pass beacuse its give n * k * logn
//  but k = 10^5 and n = 10 then give n * k^2

#include <bits/stdc++.h>
using namespace std;
const int p = 137, mod = 1e9 + 7;
const int p1 = 277, mod1 = 1e9 + 7;
const int N = 2e7 + 9;
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
pair<int, int> string_hash(string s)
{
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++)
    {
        hs.first += 1LL * s[i] * pw[i].first % mod;
        hs.first %= mod;
        hs.second += 1LL * s[i] * pw[i].second % mod1;
        hs.second %= mod1;
    }
    return hs;
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
    int n, k;
    cin >> n >> k;
    int length = n * k;
    string s;
    cin >> s;
    s = s + s;
    prec();
    bulid(s);
    int g;
    cin >> g;
    vector<int> ans;
    map<pair<int, int>, int> st;
    int i = 0;

    for (int i = 1; i <= g; i++)
    {
        string q;
        cin >> q;
        st[string_hash(q)] = i;
    }
// 
    for (int j = 0; j < k; j++)
    {
        map<pair<int, int>, int> st1 = st;

        for (int i = j; i < length + j; i += k)
        {
            auto t = get_hash(i, i + k - 1);
            if (st1[t])
            {
                ans.push_back(st1[t]);
                st1.erase(t);
            }
        }

        if ((int)ans.size() == n)
        {
            break;
        }
        ans.clear();
    }

    if ((int)ans.size() == n)
    {
        cout << "YES\n";
        for (auto it : ans)
        {
            cout << it << " ";
        }
    }
    else
    {
        cout << "NO\n";
    }
}