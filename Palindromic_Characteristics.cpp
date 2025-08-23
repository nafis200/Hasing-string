#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N];
string s, t;
int n;
int f(int l, int r)
{
    if (l == r)
    {
        return 1;
    }
    int len = (r - l + 1);
    if (s.substr(l, len) != t.substr(n - r - 1, len))
    {
        return 0;
    }
    int ans = 1;
    int mid = (l + r) / 2;
    if(len % 2){
        mid--;
    }
    ans = ans + f(l, mid);
    return ans;
}
int main()
{
    memset(a, 0, sizeof(a));
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
    for(int i = n - 1; i >= 0 ; i--){
        a[i] = a[i + 1] + a[i];
    }

    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
}