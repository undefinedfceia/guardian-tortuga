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

const int MAXN = 100100;

int compare(int a, int b) {
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    int n, count;
    int max = -1;

    cin >> n;

    int a[n];

    forn(i, n) {
        cin >> a[i];
    }

    sort(a, a + n, compare);

    forn(i, n) {
        count = 0;
        if (max >= (n - i))
            break;

        forr(j, i, n) {
            if (a[j] - a[i] <= 5)
                count++;
            else
                break;
        }
        if (count > max)
            max = count;
    }

    cout << max;

    return 0;
}