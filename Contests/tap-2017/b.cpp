#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(int i=a;i<b;i++) 
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v))
#define sz(c) ((int)c.size())
#define fst first
#define snd second
#define pb push_back
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define dprint(v) cout << #v " = " << v << endl
#define endl "\n"
#define MOD 1000000007
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int n;
	cin >> n;
	ll p[n],c[n];
	forn(i,n)
		cin >> p[i];
	forn(i,n)
		cin >> c[i];
	sort(p,p+n);
	sort(c,c+n);
	ll count[n];
	forn(i,n)
		count[i] = (c+n) - lower_bound(c,c+n,p[i]);
	ll total = 1;
	forn(i,n)
		total = (total * count[i]) % MOD;
	total = total % MOD;
	total = total / n;
	cout << total << endl;
	return 0;
}
