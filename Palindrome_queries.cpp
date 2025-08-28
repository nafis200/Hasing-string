
// H(s[0..n−1])=s[0]⋅p0+s[1]⋅p1+⋯+s[n−1]⋅pn−1

//                  root (1..4)
//              /                  \
//        (1..2)                   (3..4)
//       /     \                  /      \
//    (1..1) (2..2)           (3..3)   (4..4)


// leaf (1..1): "a" = 'a' * p^0

// leaf (2..2): "a" = 'a' * p^0

// leaf (3..3): "b" = 'b' * p^0

// leaf (4..4): "b" = 'b' * p^0


// (1..2) = "aa" →

// left = "a" (hash = a*p^0)
// right = "a" (hash = a*p^0)
// merge = left + right * p^(len(left))
//       = (a*p^0) + (a*p^0) * p^1
//       = a*p^0 + a*p^1


// (3..4) = "bb" →

// left = b*p^0
// right = b*p^0
// merge = b*p^0 + (b*p^0)*p^1
//       = b*p^0 + b*p^1


// left = "aa" = a*p^0 + a*p^1
// right = "bb" = b*p^0 + b*p^1
// merge = left + right * p^(len(left))
//       = (a*p^0 + a*p^1) + (b*p^0 + b*p^1) * p^2
//       = a*p^0 + a*p^1 + b*p^2 + b*p^3


#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 9;
const int p = 137, p1 = 277;

pair<int,int> pw[N], invpw[N];

int power(long long n, long long k, int mod) {
    long long ans = 1 % mod;
    n %= mod;
    while (k) {
        if (k & 1) ans = ans * n % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return ans;
}

void prec() {
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i-1].first * p % mod;
        pw[i].second = 1LL * pw[i-1].second * p1 % mod1;
    }
    int ip = power(p, mod - 2, mod);
    int ip1 = power(p1, mod1 - 2, mod1);
    invpw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        invpw[i].first = 1LL * invpw[i-1].first * ip % mod;
        invpw[i].second = 1LL * invpw[i-1].second * ip1 % mod1;
    }
}

struct node {
    int len;
    pair<int,int> fh, rh; 
};

string a;
node s[N * 4];

node merge(node L, node R) {
    node ans;
    ans.len = L.len + R.len;

    ans.fh.first = (L.fh.first + 1LL * R.fh.first * pw[L.len].first) % mod;
    ans.fh.second = (L.fh.second + 1LL * R.fh.second * pw[L.len].second) % mod1;

   
    ans.rh.first = (R.rh.first + 1LL * L.rh.first * pw[R.len].first) % mod;
    ans.rh.second = (R.rh.second + 1LL * L.rh.second * pw[R.len].second) % mod1;

    return ans;
}

void build(int n, int b, int e) {
    if (b == e) {
        s[n].len = 1;
        s[n].fh = {a[b-1], a[b-1]};
        s[n].rh = {a[b-1], a[b-1]};
        return;
    }
    int l = n*2, r = n*2+1, mid = (b+e)/2;
    build(l, b, mid);
    build(r, mid+1, e);
    s[n] = merge(s[l], s[r]);
}

void update(int n, int b, int e, int i, char x)
{
    if (b > i or e < i)
        return;

    if (b == e)
    {
        s[n].len = 1;
        s[n].fh = {x, x};
        s[n].rh = {x, x};
        return;
    }
    int mid = (b + e) / 2;
    int l = n * 2, r = n * 2 + 1;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    s[n] = merge(s[l], s[r]);
}

node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {0,{0,0},{0,0}};
    if (b >= i && e <= j) return s[n];
    int l = n*2, r = n*2+1, mid = (b+e)/2;
    return merge(query(l, b, mid, i, j), query(r, mid+1, e, i, j));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prec();

    int n, m;
    cin >> n >> m;
    cin >> a;

    build(1, 1, n);

    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k; char x;
            cin >> k >> x;
            update(1, 1, n, k, x);
        } else {
            int l, r;
            cin >> l >> r;
            auto ans = query(1, 1, n, l, r);
            if (ans.fh == ans.rh) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
