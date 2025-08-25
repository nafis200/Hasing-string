#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int n = (int)s.size();
    int n1 = (int)t.size();
    int cnt = 0;
    if(s.size() < t.size()){
        swap(s,t);
        swap(n,n1);
    }
    for (int i = 0; i + n1 - 1 < n; i++)
    {
        if(s.substr(i, n1) == t.substr(0, n1)){
            cnt++;
        }
    }
    cout << cnt << "\n";
}