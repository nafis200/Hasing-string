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

    map<string, int> mp;
    int g;
    cin >> g;
    vector<string> ans;
    set<string> st;
    while (g--)
    {
        string q;
        cin >> q;
        st.insert(q);
    }

    for (int j = 0; j < k; j++)
    {
        set<string> st1 = st;
        bool ok = false;
        for (int i = j; i < length + j; i += k)
        {
            string t = s.substr(i, k);
            if (st1.find(t) != st1.end())
            {
                ans.push_back(t);
                st1.erase(t);
            }
        }
        if (ans.size() == n)
        {
            break;
        }
        ans.clear();
    }
    if (ans.size() == n)
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