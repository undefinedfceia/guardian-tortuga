#include <bits/stdc++.h>
using namespace std;
#define forr(i,a,b) for(ll i = a; i < b; i++)
#define forn(i,n) forr(i,0,n)
#define zero(v) memset(v,0,sizeof(v)) 
#define sz(c) ((int) c.size())
#define dprint(v) cout << #v" = " << v << endl;
#define fst first
#define snd second
#define pb push_back
#define endl "\n"
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1000000050;

int main(){
	ios::sync_with_stdio(0);
	int n,a,b;
	vector<ii> pares;
	vector<ii>::iterator it;
	cin >> n;
	int lmin = MAXN, rmax = 0;
	forn(i,n){
		cin >> a >> b;
		pares.pb({a,b});
		if(a < lmin) lmin = a;
		if(b > rmax) rmax = b;
	}
	int p = 0;
	for(it = pares.begin(); it != pares.end(); it++){
		p++;
		if(it->fst <= lmin && it->snd >= rmax){
			cout << p << endl;
			return 0;
		}
		
	}
	cout << -1 << endl;
	return 0;
}
