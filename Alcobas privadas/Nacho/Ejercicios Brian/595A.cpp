#include <bits/stdc++.h>
using namespace std;
#define forr(i, a, b) for(ll i = 0; i<b; i++)
#define forn(i, n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define pb push_back
#define fst first
#define snd second
#define dforn(i,n) for(int i=n; i > -1; i--)
#define dprint(v) cout << #v"=" << v << endl
#define end "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int MAXN = 100000;


int main(){
	ios::sync_with_stdio(0);
	int n,m;
	cin >> n >> m;
	bool a,b;
	ll count = 0;
	forn(i,n)
		forn(j,m)
			cin >> a >> b, count += (a||b); 
	cout << count << endl;
	return 0;
}
