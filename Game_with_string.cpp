#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    stack<char> st;

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
            continue;
        }
        if (st.top() == s[i])
        {

            st.pop();
            cnt++;
            cnt = cnt % 2;
        }
        else
        {
            st.push(s[i]);
        }
    }

      cnt == 1 ? cout << "Yes\n" : cout << "No\n";
}