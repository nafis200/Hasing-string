// Bba
// B a a
// baaa

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    for (int i = 1; i < (int)s.size(); i++)
    {
        bool ok = false;
        char x = 'a';

            while ((s[i] == s[i - 1]))
            {
                if (s[i] == x)
                {
                    x++;
                }
                ok = true;
                s[i] = x;
            }
        
        while (ok && (((i + 1 < s.size()) && (s[i] == s[i + 1])) || (s[i] == s[i - 1])))
        {
            x++;
            s[i] = x;
        }

    }
    cout << s << "\n";
}