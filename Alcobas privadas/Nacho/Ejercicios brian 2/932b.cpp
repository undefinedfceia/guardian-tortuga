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

const int MAXN = 1001000;

ll f(ll n) {
    int digit;
    ll product = 1;
    do {
        digit = n % 10;
        if (digit != 0)
            product *= digit;
        n /= 10;
    } while (n > 0);

    return product;
}

ll g(ll n) {
    if (n < 10)
        return n;
    return g(f(n));
}

ll P[MAXN];
ll k1[MAXN];
ll k2[MAXN];
ll k3[MAXN];
ll k4[MAXN];
ll k5[MAXN];
ll k6[MAXN];
ll k7[MAXN];
ll k8[MAXN];
ll k9[MAXN];

void llenar_k(ll a[], int k) {
    a[0] = P[0] == k;
    forr(i, 1, MAXN) {
        a[i] = (P[i] == k) + a[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    ll Q, l, r, k, count = 0;

    cin >> Q;

    forn(i, MAXN) {
        P[i] = g(i);
    }

    llenar_k(k1, 1);
    llenar_k(k2, 2);
    llenar_k(k3, 3);
    llenar_k(k4, 4);
    llenar_k(k5, 5);
    llenar_k(k6, 6);
    llenar_k(k7, 7);
    llenar_k(k8, 8);
    llenar_k(k9, 9);

    forn(q, Q) {
        cin >> l >> r >> k;
        switch (k) {
            case 1:
                count = k1[r] - k1[l - 1];
                break;
            case 2:
                count = k2[r] - k2[l - 1];
                break;
            case 3:
                count = k3[r] - k3[l - 1];
                break;
            case 4:
                count = k4[r] - k4[l - 1];
                break;
            case 5:
                count = k5[r] - k5[l - 1];
                break;
            case 6:
                count = k6[r] - k6[l - 1];
                break;
            case 7:
                count = k7[r] - k7[l - 1];
                break;
            case 8:
                count = k8[r] - k8[l - 1];
                break;
            case 9:
                count = k9[r] - k9[l - 1];
                break;
            default:
                count = 0;
                break;
        }
        cout << count << endl;
    }

    return 0;
}