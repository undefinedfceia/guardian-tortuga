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

const int MAXN=100100;

double a[4] = {1.0000000000, 1.7182818285, 12.43598041302022, 3814263.950497979};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed;
    cout << setprecision(10);
    int n;
    cin >> n;
    cout << a[n] << endl;
	return 0;
}
