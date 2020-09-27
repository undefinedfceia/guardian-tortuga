#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=(a); i<(b); i++)
#define forn(i,n) forr(i,0,n)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define pb push_back
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
#define dforn(i,n) for(int i=n-1; i>=0; i--)
#define dprint(v) cout << #v"=" << v << endl
#define endl "\n"
#define tab "\t"

const int MAXN=100100;

int count_ones(int a, int b, int n, int k){
    int delta_count = 0;
    for(int j = 0; j < n && delta_count <= k; j++) {
        delta_count +=  (a & 1) != (b & 1);
        a = a >> 1;
        b = b >> 1;
    }
    return delta_count;
}

int main() {
    ios::sync_with_stdio(0);
    int n, m, k, fedors_army, count = 0, delta;

    cin >> n >> m >> k;
 
    int army[m];

    forn(i, m) {
        cin >> army[i];
    }

    cin >> fedors_army;

    forn(i, m) {
        count += count_ones(fedors_army, army[i], n, k) <= k;
    }

    cout << count << endl;

    return 0;
}