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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
	ll n,k;
	cin >> n >> k;
	ll a;
	if(n % 2 == 0)
		a = (k <= n/2) ? 2*k-1 : 2*(k-n/2);
	else
		a = (k <= (((ll)n/2) + 1)) ? 2*k-1 : 2*(k-(n/2 + 1));
	cout << a << endl;
	return 0;
}
