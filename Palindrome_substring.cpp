#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    while (cin >> s)
    {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        set<string> st;
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                string ans = s.substr(i, len);
                // string ans1 = ans;
                string ans2 = t.substr(n - len - i, len);
                // reverse(ans1.begin(), ans1.end());
                if (ans == ans2)
                {
                    st.insert(ans);
                }
            }
        }
        for (auto it : st)
        {

            cout << it << "\n";
        }
        cout << "\n";
    }
}


// #include<bits/stdc++.h>
// using namespace std;

// const int p = 137, mod = 1e9 + 7;
// const int p1 = 277, mod1 = 1e9 + 7;
// const int N = 1005;

// pair<int,int> pw[N], invf[N];
// pair<int,int> pref[N], suff[N];


// int power(long long n, long long k, int mod){
//     int ans = 1 % mod;
//     n = n % mod;
//     if(n < 0) n += mod;
//     while(k){
//         if(k & 1) ans = (long long) ans * n % mod;
//         n = (long long) n * n % mod;
//         k >>= 1;
//     }
//     return ans;
// }

// void prec(){
//     pw[0] = {1,1};
//     for(int i=1;i<N;i++){
//         pw[i].first = 1LL * pw[i-1].first * p % mod;
//         pw[i].second = 1LL * pw[i-1].second * p1 % mod1;
//     }
//     int ip1 = power(p, mod-2, mod);
//     int ip2 = power(p1, mod1-2, mod1);
//     invf[0] = {1,1};
//     for(int i=1;i<N;i++){
//         invf[i].first = 1LL * invf[i-1].first * ip1 % mod;
//         invf[i].second = 1LL * invf[i-1].second * ip2 % mod1;
//     }
// }


// void build(string &s, pair<int,int> arr[]){
//     int n = s.size();
//     for(int i=0;i<n;i++){
//         arr[i].first = 1LL * s[i] * pw[i].first % mod;
//         arr[i].second = 1LL * s[i] * pw[i].second % mod1;
//         if(i){
//             arr[i].first = (arr[i].first + arr[i-1].first) % mod;
//             arr[i].second = (arr[i].second + arr[i-1].second) % mod1;
//         }
//     }
// }

// pair<int,int> get_hash(pair<int,int> arr[], int i, int j){
//     assert(i <= j);
//     pair<int,int> hs = arr[j];
//     if(i){
//         hs.first = (hs.first - arr[i-1].first + mod) % mod;
//         hs.second = (hs.second - arr[i-1].second + mod1) % mod1;
//     }
//     hs.first = 1LL * hs.first * invf[i].first % mod;
//     hs.second = 1LL * hs.second * invf[i].second % mod1;
//     return hs;
// }

// int32_t main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     prec();

//     string s;
//     while(getline(cin, s)){
//         if(s.empty()) continue;

//         int n = s.size();
//         set<string> st;

//         build(s, pref);

//         string rs = s;
//         reverse(rs.begin(), rs.end());
//         build(rs, suff);

//         for(int len = 2; len <= n; len++){
//             for(int i=0;i+len<=n;i++){
//                 int j = i + len - 1;
//                 pair<int,int> h1 = get_hash(pref, i, j);          
//                 int ri = n - 1 - j, rj = n - 1 - i;             
//                 pair<int,int> h2 = get_hash(suff, ri, rj);     
//                 if(h1 == h2){
//                     st.insert(s.substr(i,len));
//                 }
//             }
//         }

//         for(auto it: st){
//             cout << it << "\n";
//         }
//         cout << "\n";
//     }
// }
