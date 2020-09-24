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

int get_resul(int a[], int b[], int n, int m) {
    int indexb = 0, count = 0;
    forn(i, n) {
        forr(j, indexb, m) {
            // cout << a[i] << tab << b[j] << tab;
            if (abs(a[i] - b[j]) <= 1) {
                // cout << "MATCH" << endl;
                indexb = j + 1;
                count++;
                break;
            } else {
                // cout << endl;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m;

    cin >> n;
    int h[n];

    forn(i, n) {
        cin >> h[i];
    }

    cin >> m;
    int f[m];

    forn(i, m) {
        cin >> f[i];
    }

    sort(h, h + n, compare);
    sort(f, f + m, compare);

    int result = 0;

    if (n <= m)
        result = get_resul(h, f, n, m);
    else
        result = get_resul(f, h, m, n);

    cout << result << endl;

    return 0;
}