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

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int length = n * k;
    string s;
    cin >> s;
    s = s + s;
    int g;
    cin >> g;
    vector<int> ans;
    map<string, int> st;
    int i = 0;

    for (int i = 1; i <= g; i++)
    {
        string q;
        cin >> q;
        st[q] = i;
    }

    map<string, int> mp;
    for (int j = 0; j < k; j++)
    {
        map<string, int> st1 = st;

        for (int i = j; i < length + j; i += k)
        {
            string t = s.substr(i, k);
            if(st1[t]){
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