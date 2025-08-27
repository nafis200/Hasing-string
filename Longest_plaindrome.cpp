#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool vis[N][N];
string s[N][N];
string s1;
int n;

string f(int i, int j){
    if(i == j){
        return string(1,s1[i]);
    }
    if(i > j){
        return "";
    }
    if(vis[i][j]){
        return s[i][j];
    }
    string ans = f(i + 1, j);
    ans = f(i, j - 1);
    if(s1[i] == s1[j]){
        ans = s1[i] + f(i + 1, j - 1) + s1[j];
    }
    vis[i][j] = true;
    return s[i][j] =  ans;
    return ans;
}

int main(){
    memset(vis,false,sizeof(vis));
    cin >> s1;
    n = s1.size();
   cout << f(0, n - 1) << "\n";
}