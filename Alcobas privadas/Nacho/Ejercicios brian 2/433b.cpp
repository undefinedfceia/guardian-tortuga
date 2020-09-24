#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define forn(i, n) forr(i, 0, n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it, v) for (auto it = v.begin(); it != v.end(); ++it)
#define pb push_back
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
#define dforn(i, n) for (int i = n - 1; i >= 0; i--)
#define dprint(v) cout << #v "=" << v << endl
#define endl "\n"
#define tab "\t"

const int MAXN = 100100;

int compare(int a, int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    ll n, M, l, r, type, result;

    cin >> n;

    ll v[n];
    ll vs[n + 1];
    ll u[n];
    ll us[n + 1];

    forn(i, n) {
        cin >> v[i];
        u[i] = v[i];
    }

    cin >> M;

    sort(u, u + n, compare);

    vs[0] = 0;
    us[0] = 0;

    forr(i, 1, n + 1) {
        vs[i] = v[i - 1] + vs[i - 1];
        us[i] = u[i - 1] + us[i - 1];
    }

    forn(m, M) {
        cin >> type >> l >> r;
        switch (type) {
            case 1:
                result = vs[r] - vs[l - 1];
                break;
            case 2:
                result = us[r] - us[l - 1];
                break;
        }
        cout << result << endl;
    }

    return 0;
}