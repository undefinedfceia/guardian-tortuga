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

int main() {
    ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    ll n, value, count, prev, next, minimum, acumulacion = 0;
    map<ll, ll> mymap;
    map<ll, ll>::reverse_iterator i, j;

    cin >> n;

    forn(i, n) {
        cin >> value;
        if (mymap[value])
            mymap[value] = mymap[value] + 1;
        else
            mymap[value] = 1;
    }

    for (i = mymap.rbegin(); i != mymap.rend(); ++i) {
        acumulacion += i->second;
    }

    count = 0;
    // cout << "acumulacion: " << acumulacion << endl;

    for (i = mymap.rbegin(); i != mymap.rend() && acumulacion > 0; ++i) {
        acumulacion -= i->second;  // le restamos la cantidad del mayor
        // cout << i->first << "\t" << i->second << endl;
        if (acumulacion >= i->second) {
            count += i->second;
        } else {
            count += acumulacion;
            acumulacion = 0;
        }
    }

    cout << count << endl;

    return 0;
}